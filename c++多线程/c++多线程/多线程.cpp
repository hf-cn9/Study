#include<Thread>
#include<iostream>
#include<string>
#include<memory>
#include<mutex>
#include<windows.h>
#include<condition_variable>
#include<queue>

using namespace std;

mutex mtx;
timed_mutex tmtx;
int value = 0;
thread thread2;
void printHello(string& a) {
	cout << a <<"\n";
}
void test() {
	string a = "1";//局部变量会在test里销毁，但是线程依然进行；
	thread2 = thread(printHello, ref(a));
}
class A {
public:
	void func() {};
};
void func1(int &test) {
	for (int i = 0; i < 100000;i++) {
		mtx.lock();//锁住，只有当前访问的进程能够访问mtx(获得所有权）
		//两个线程都要获取mtx的所有权，只有先获取了才能往后执行test +=1;
		test += 1;
		mtx.unlock();//解锁（释放所有权)
	}
}
mutex m1, m2;
void func_each1() {
	m1.lock();
	//Sleep(100);//加一点延迟制造互斥锁死
	m2.lock();
	m1.unlock();
	m2.unlock();
}
void func_each2() {
	m2.lock();
	m1.lock();
	m1.unlock();
	m2.unlock();
}
void test2() {
	lock_guard<mutex> lg(mtx);//实现自动锁定和自动释放
	//不能复制和移动,不允许mtx的隐式类型转换，必须声明
	
	for (int i = 0; i < 100;i++) {
	//unique_lock<mutex> lg(mtx)的功能比lock_gurad更多
	//unique_lock<timed_mutex> lg(tmtx , defer_lock);//构造函数时不加锁
	//lg.try_lock_for(chrono::second(2));//尝试获取mtx的所有权,等待两秒未获取到则不再获取
										 //也不执行后面的代码(try_lock_for只能用timed_mutex类型;
	//lg.try_lock_until则是等待到某个时间点
	//unique_lock支持右值引用和swap的转换
		value += 1;
	}
}
class Log;//声明类型
static Log* g_log= nullptr;//g_log防止在lambda无法明确作用域内限定的log
static once_flag flag;
//单例模式(只存在一个实例)
class Log {
public:
	Log() {};
	Log(const Log& log) = delete;//禁用拷贝构造
	Log& operator=(const Log& log) = delete;
	static Log& GetInstance() {//返回引用，确保只有一个实例
		// c++11以后局部静态变量的初始化是线程安全的。
		// 返回对该静态对象的引用不会破坏这一特性
		// 同时保证了多线程环境下对同一实例的访问一致性。
		//static Log log;//懒汉模式
		//return log;

		//饿汉模式（在有需要的时候才构造这个对象）
		//需要用call_once进行保护，否则多个线程执行操作可能会创造多个g_log（只能在线程里调用）；
		call_once(flag, []() {g_log = new Log;});//保证只有一个线程执行call_once;
		return *g_log;
	}
	void PrintLog(string msg) {
		cout <<__TIME__<<msg << endl;//__TIME__一个时间宏，获取当前时间
	}
};
queue<int> q_queue;
condition_variable g_cv;
mutex mtx1;
//生产者与消费者模型
void productor() {
	for (int i = 0;i < 10;i++) {
		unique_lock<mutex> lock(mtx1);//加锁
		q_queue.push(i);
		g_cv.notify_one();//通知消费者
		cout << "task :" << i << "\n";
	}
	this_thread::sleep_for(chrono::microseconds(100));//休眠100ms
}
void consumer() {
	while (1) {
		unique_lock<mutex> lock(mtx1);//加锁
		g_cv.wait(lock, []() {return !q_queue.empty();});//无任务则等待
		int value = q_queue.front();
		q_queue.pop();
		cout << "need :" << value << "\n";
	}
}
atomic<int> shared_data = 0;
void func_1() {
	for (int i = 0; i < 10000; i++) {
		shared_data++;
	}
}
int main2() {

	//创建线程
	string a = "hello";
	thread thread1(printHello,ref(a));//无参则无逗号(无法传引用的参数，因为临时变量会被释放掉)
									  //用ref修饰之后，将a转换成引用类型的变量
	//主线程结束，线程在后台持续运行
	//thread1.detach();
	//返回一个bool值，判断该线程是否可以调用join
	//若是不可以调用,但是调用了会报错
	bool isJoin = thread1.joinable();
	if (isJoin) {
		//检查线程是否执行完，防止主线程结束但是线程未结束；
		//join()执行完后才会执行之后的程序;
		thread1.join();
	}
	/*test();
	thread2.join();*/
	//空指针被提前释放，类对象被提前释放都是一个道理
	//用智能指针shared_ptr就可以解决提前释放的问题

	//类成员函数的调用
	//非静态成员函数本质上是一个包含隐藏的 this 指针的函数指针;
	//所以它需要绑定一个具体的对象来调用对应的成员函数。
	//A test1;
	shared_ptr<A> ptr_a = make_shared <A>();//防止后续误操作释放了对象,等价于this的智能指针
	std::thread t(&A::func, ptr_a);
	t.join();
	
	//数据竞争问题(当数据量够大时，可能因为两个线程同时访问一个变量值，导致结果出错)
	int value2 = 0;
	thread t1(func1, ref(value2));
	thread t2(func1, ref(value2));
	t1.join();
	t2.join();
	cout << test2 << endl;
	
	//互斥量死锁
	thread t_each1(func_each1);
	thread t_each2(func_each2);
	t_each1.join();
	t_each2.join();
	cout << "over" << endl;//t_each1进程等待获取m2,t_each2进程等待获取m1两个进程相互锁死

	//lock_guard与unique_lock
	thread t3(test2);
	t3.join();
	cout << value << endl;
	
	//单例模式
	Log::GetInstance().PrintLog("error");

	//condition_variable(条件变量)
	thread t4(productor);
	thread t5(consumer);
	t4.join();
	t5.join();

	//atomic原子操作实现线程安全下访问修改共享变量
	//比手动加锁的效率更高
	thread t6(func_1);
	thread t7(func_1);
	t6.join();
	t7.join();
	shared_data.store(1);//可以直接赋值，保证操作是原子性的
	cout << shared_data << endl;

	return 0;
}