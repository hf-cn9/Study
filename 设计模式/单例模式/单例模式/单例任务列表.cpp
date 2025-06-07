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
		static TaskQueue tq;//����ģʽʵ��һ�������޳�ʼ������ʱ���в���������Ҫ�ȴ���ʼ��;
		//��̬����static int tq��ȫ������Ĭ�ϵ���0����static int tq = 0;Ϊδ��ʼ����
		return tq;
#elif 0
		if (m_taskQ == nullptr) {//����ģʽʵ�ֶ���˫�ؼ�����������˵�һ�����ⲻ�ᱻ��ס
			//©��:newһ������Ĺ���������ģ����ܴ���ֻ�����ڴ漴��
			//m_taskQ��Ϊ�գ������ڲ������ݾ��Ѿ���return�˵����(���߳�)
			std::unique_lock<std::mutex> lock(mtx);
			if (m_taskQ == nullptr) {
				m_taskQ = new TaskQueue;
			}
		}
		return *m_taskQ;
#elif 0
		//ԭ�ӱ�����ʼ�հ�����ȷ˳��ִ�л���ָ��������ã�
		TaskQueue* taskQ = m_taskQ_at.load();
		if (taskQ == nullptr) {//����ԭ�ӱ�����Ϸ�����ʵ�ֵ���������
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
	//�������
	void addTask(int node) {
		if (!stop) {
			std::unique_lock<std::mutex> lock(m_mtx);
			q.push(node);
			m_cv.notify_one();
		}
	}
	// ����ʽȡ�����񣬵�����Ϊ��ʱ�ȴ�
	bool popTask(int& node) {
		std::unique_lock<std::mutex> lock(m_mtx);
		m_cv.wait(lock, [&]() { return !q.empty() || stop; });//���ܳ�����ٻ��ѣ���Ҫν������ֹ�ڴ�й¶
		if (stop && q.empty())
			return false;
		node = q.front();
		q.pop();
		return true;
	}

	// ֪ͨ���еȴ��߳��˳�
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
// ������
static void Productor(TaskQueue& taskQ) {
	for (int i = 0; i < 10; i++) {
		taskQ.addTask(i + 10);
		std::cout << "+++ Push Data: " << (i + 10)
			<< ", Thread_id: " << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	// ����������֪ͨ�������˳����������Ҫ�����˳���
	taskQ.signalStop();
}

// ������
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