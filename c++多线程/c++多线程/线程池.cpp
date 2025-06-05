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
	ThreadPool(const ThreadPool&) = delete;//���ÿ�������
	ThreadPool& operator=(const ThreadPool&) = delete;//���ø�ֵ
	static ThreadPool& getInstance() {//�������ã�ȷ�����۴����������󣬶���ָ��һ��ʵ��
		static ThreadPool pool(4);//ֱ�Ӵ����߳���
		return pool;
	}
	template<class F, class ... Args>
	void enqueue(F&& f, Args&& ... args) {//fΪ��������
		auto task = bind(forward<F>(f), forward<Args>(args)...);//�����͵���������Ҫ�Ĳ���������һ��
		{
			unique_lock<mutex>lk(mtx);
			tasks.emplace(move(task));//����task�ɱ��ƶ��������ƶ����캯������task��ֵ��ȡ����ʱtaskΪ��
		}
		cv.notify_one();
	}
private:
	//����ģʽ
	ThreadPool(int nums) :stop(false) {
		for (int i = 0;i < nums;i++) {
			threads.emplace_back([this] {
				while (1) {
					function<void()> task;
					{
						unique_lock<mutex> log(mtx);//����������
						cv.wait(log, [this] {
							return stop || !tasks.empty();
							});
						if (stop && tasks.empty()) {
							return;//ִ������������
						}
						task = move(tasks.front());//moveת��tasks�еĵ�һ��ֵΪ��ֵ��ʵ��ǳ����
						tasks.pop();
					}
					task();//�������
				}
				});//ֱ�ӵ��ÿ�����������ʡ��Դ��
		}
	}
	~ThreadPool() {
		{//ָ��������Χ
			unique_lock<mutex> lock(mtx);
			stop = true;//�߳�ֹͣ
			cv.notify_all();//֪ͨ�����߳�ȡ����
		}
		//�����������
		for (auto& t : threads) {//thread���ɸ��ƣ�ֻ����&t����
			if (t.joinable()) {
				t.join();
			}
		}
	}
	vector<thread> threads;//�߳�����
	queue<function<void()>> tasks;//�������
	mutex mtx;//��������
	condition_variable cv;//֪ͨ�߳�
	bool stop;//����
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