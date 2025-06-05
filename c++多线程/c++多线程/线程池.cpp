#include<queue>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<vector>
#include<functional>
#include<iostream>
using namespace std;

class ThreadPool {
public:
	ThreadPool(const ThreadPool&) = delete;//禁用拷贝构造
	ThreadPool& operator=(const ThreadPool&) = delete;//禁用赋值
	static ThreadPool& getInstance() {//返回引用，确保无论创建几个对象，都是指向一个实例
		static ThreadPool pool(4);//直接创建线程数
		return pool;
	}
	template<class F, class ... Args>
	void enqueue(F&& f, Args&& ... args) {//f为函数对象
		auto task = bind(forward<F>(f), forward<Args>(args)...);//函数和调用它所需要的参数捆绑在一起。
		{
			unique_lock<mutex>lk(mtx);
			tasks.emplace(move(task));//表明task可被移动，调用移动构造函数，将task的值窃取，此时task为空
		}
		cv.notify_one();
	}
private:
	//单例模式
	ThreadPool(int nums) :stop(false) {
		for (int i = 0;i < nums;i++) {
			threads.emplace_back([this] {
				while (1) {
					function<void()> task;
					{
						unique_lock<mutex> log(mtx);//互斥量锁定
						cv.wait(log, [this] {
							return stop || !tasks.empty();
							});
						if (stop && tasks.empty()) {
							return;//执行完所有任务
						}
						task = move(tasks.front());//move转换tasks中的第一个值为右值，实现浅拷贝
						tasks.pop();
					}
					task();//完成任务
				}
				});//直接调用拷贝函数，节省资源；
		}
	}
	~ThreadPool() {
		{//指定作用域范围
			unique_lock<mutex> lock(mtx);
			stop = true;//线程停止
			cv.notify_all();//通知所有线程取任务
		}
		//完成所有任务
		for (auto& t : threads) {//thread不可复制，只能用&t接收
			if (t.joinable()) {
				t.join();
			}
		}
	}
	vector<thread> threads;//线程数组
	queue<function<void()>> tasks;//任务队列
	mutex mtx;//保护变量
	condition_variable cv;//通知线程
	bool stop;//条件
};
int main1() {
	ThreadPool& pool = ThreadPool::getInstance();
	for (int i = 0;i < 10;i++) {
		pool.enqueue([i] {
			cout << "task: " << i << " is start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "task: " << i << " is end" << endl;
			});
	}
	return 0;
}