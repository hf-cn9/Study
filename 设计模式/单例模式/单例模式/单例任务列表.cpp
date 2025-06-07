#include<iostream>
#include<mutex>
#include<atomic>
#include<queue>
#include<thread>
#include<condition_variable>

class TaskQueue {
public:
	TaskQueue(const TaskQueue&) = delete;
	TaskQueue& operator=(const TaskQueue&) = delete;
	static TaskQueue& getInstance() {
#if 1
		static TaskQueue tq;//懒汉模式实现一：创建无初始化对象时所有并发程序都需要等待初始化;
		//静态变量static int tq在全局区中默认等于0，即static int tq = 0;为未初始化；
		return tq;
#elif 0
		if (m_taskQ == nullptr) {//懒汉模式实现二：双重检查锁定；除了第一次以外不会被锁住
			//漏洞:new一个对象的过程是随机的，可能存在只创建内存即：
			//m_taskQ不为空，但是内部无数据就已经被return了的情况(多线程)
			std::unique_lock<std::mutex> lock(mtx);
			if (m_taskQ == nullptr) {
				m_taskQ = new TaskQueue;
			}
		}
		return *m_taskQ;
#elif 0
		//原子变量：始终按照正确顺序执行机器指令（可以设置）
		TaskQueue* taskQ = m_taskQ_at.load();
		if (taskQ == nullptr) {//利用原子变量结合方法二实现单例创建；
			std::unique_lock<std::mutex> lock(mtx);
			taskQ = m_taskQ_at.load();
			if (taskQ == nullptr) {
				taskQ = new TaskQueue;
				m_taskQ_at.store(taskQ);
			}
		}
		return *taskQ;
#endif
	}
	//添加任务
	void addTask(int node) {
		if (!stop) {
			std::unique_lock<std::mutex> lock(m_mtx);
			q.push(node);
			m_cv.notify_one();
		}
	}
	// 阻塞式取出任务，当队列为空时等待
	bool popTask(int& node) {
		std::unique_lock<std::mutex> lock(m_mtx);
		m_cv.wait(lock, [&]() { return !q.empty() || stop; });//可能出现虚假唤醒，需要谓词来防止内存泄露
		if (stop && q.empty())
			return false;
		node = q.front();
		q.pop();
		return true;
	}

	// 通知所有等待线程退出
	void signalStop() {
		std::lock_guard<std::mutex> lock(m_mtx);
		stop = true;
		m_cv.notify_all();
	}
private:
	TaskQueue():stop(false){}
	static TaskQueue* m_taskQ;
	static std::atomic<TaskQueue* > m_taskQ_at;
	std::queue<int> q;
	std::mutex m_mtx;
	std::condition_variable m_cv;
	bool stop;
};
TaskQueue* TaskQueue::m_taskQ = nullptr;
std::atomic<TaskQueue* >TaskQueue:: m_taskQ_at;
// 生产者
static void Productor(TaskQueue& taskQ) {
	for (int i = 0; i < 10; i++) {
		taskQ.addTask(i + 10);
		std::cout << "+++ Push Data: " << (i + 10)
			<< ", Thread_id: " << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	// 生产结束后通知消费者退出（如果你需要快速退出）
	taskQ.signalStop();
}

// 消费者
static void Consumer(TaskQueue& taskQ) {
	int task;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	while (taskQ.popTask(task)) {
		std::cout << "+++ Use Data: " << task
			<< ", Thread_id: " << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
int main() {
	TaskQueue& taskQ = TaskQueue::getInstance();
	std::thread t1(Productor, std::ref(taskQ));
	std::thread t2(Consumer, std::ref(taskQ));
	t1.join();
	t2.join();
	return 0;
}