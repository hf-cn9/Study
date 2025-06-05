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
	string a = "1";//�ֲ���������test�����٣������߳���Ȼ���У�
	thread2 = thread(printHello, ref(a));
}
class A {
public:
	void func() {};
};
void func1(int &test) {
	for (int i = 0; i < 100000;i++) {
		mtx.lock();//��ס��ֻ�е�ǰ���ʵĽ����ܹ�����mtx(�������Ȩ��
		//�����̶߳�Ҫ��ȡmtx������Ȩ��ֻ���Ȼ�ȡ�˲�������ִ��test +=1;
		test += 1;
		mtx.unlock();//�������ͷ�����Ȩ)
	}
}
mutex m1, m2;
void func_each1() {
	m1.lock();
	//Sleep(100);//��һ���ӳ����컥������
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
	lock_guard<mutex> lg(mtx);//ʵ���Զ��������Զ��ͷ�
	//���ܸ��ƺ��ƶ�,������mtx����ʽ����ת������������
	
	for (int i = 0; i < 100;i++) {
	//unique_lock<mutex> lg(mtx)�Ĺ��ܱ�lock_gurad����
	//unique_lock<timed_mutex> lg(tmtx , defer_lock);//���캯��ʱ������
	//lg.try_lock_for(chrono::second(2));//���Ի�ȡmtx������Ȩ,�ȴ�����δ��ȡ�����ٻ�ȡ
										 //Ҳ��ִ�к���Ĵ���(try_lock_forֻ����timed_mutex����;
	//lg.try_lock_until���ǵȴ���ĳ��ʱ���
	//unique_lock֧����ֵ���ú�swap��ת��
		value += 1;
	}
}
class Log;//��������
static Log* g_log= nullptr;//g_log��ֹ��lambda�޷���ȷ���������޶���log
static once_flag flag;
//����ģʽ(ֻ����һ��ʵ��)
class Log {
public:
	Log() {};
	Log(const Log& log) = delete;//���ÿ�������
	Log& operator=(const Log& log) = delete;
	static Log& GetInstance() {//�������ã�ȷ��ֻ��һ��ʵ��
		// c++11�Ժ�ֲ���̬�����ĳ�ʼ�����̰߳�ȫ�ġ�
		// ���ضԸþ�̬��������ò����ƻ���һ����
		// ͬʱ��֤�˶��̻߳����¶�ͬһʵ���ķ���һ���ԡ�
		//static Log log;//����ģʽ
		//return log;

		//����ģʽ��������Ҫ��ʱ��Ź����������
		//��Ҫ��call_once���б������������߳�ִ�в������ܻᴴ����g_log��ֻ�����߳�����ã���
		call_once(flag, []() {g_log = new Log;});//��ֻ֤��һ���߳�ִ��call_once;
		return *g_log;
	}
	void PrintLog(string msg) {
		cout <<__TIME__<<msg << endl;//__TIME__һ��ʱ��꣬��ȡ��ǰʱ��
	}
};
queue<int> q_queue;
condition_variable g_cv;
mutex mtx1;
//��������������ģ��
void productor() {
	for (int i = 0;i < 10;i++) {
		unique_lock<mutex> lock(mtx1);//����
		q_queue.push(i);
		g_cv.notify_one();//֪ͨ������
		cout << "task :" << i << "\n";
	}
	this_thread::sleep_for(chrono::microseconds(100));//����100ms
}
void consumer() {
	while (1) {
		unique_lock<mutex> lock(mtx1);//����
		g_cv.wait(lock, []() {return !q_queue.empty();});//��������ȴ�
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

	//�����߳�
	string a = "hello";
	thread thread1(printHello,ref(a));//�޲����޶���(�޷������õĲ�������Ϊ��ʱ�����ᱻ�ͷŵ�)
									  //��ref����֮�󣬽�aת�����������͵ı���
	//���߳̽������߳��ں�̨��������
	//thread1.detach();
	//����һ��boolֵ���жϸ��߳��Ƿ���Ե���join
	//���ǲ����Ե���,���ǵ����˻ᱨ��
	bool isJoin = thread1.joinable();
	if (isJoin) {
		//����߳��Ƿ�ִ���꣬��ֹ���߳̽��������߳�δ������
		//join()ִ�����Ż�ִ��֮��ĳ���;
		thread1.join();
	}
	/*test();
	thread2.join();*/
	//��ָ�뱻��ǰ�ͷţ��������ǰ�ͷŶ���һ������
	//������ָ��shared_ptr�Ϳ��Խ����ǰ�ͷŵ�����

	//���Ա�����ĵ���
	//�Ǿ�̬��Ա������������һ���������ص� this ָ��ĺ���ָ��;
	//��������Ҫ��һ������Ķ��������ö�Ӧ�ĳ�Ա������
	//A test1;
	shared_ptr<A> ptr_a = make_shared <A>();//��ֹ����������ͷ��˶���,�ȼ���this������ָ��
	std::thread t(&A::func, ptr_a);
	t.join();
	
	//���ݾ�������(������������ʱ��������Ϊ�����߳�ͬʱ����һ������ֵ�����½������)
	int value2 = 0;
	thread t1(func1, ref(value2));
	thread t2(func1, ref(value2));
	t1.join();
	t2.join();
	cout << test2 << endl;
	
	//����������
	thread t_each1(func_each1);
	thread t_each2(func_each2);
	t_each1.join();
	t_each2.join();
	cout << "over" << endl;//t_each1���̵ȴ���ȡm2,t_each2���̵ȴ���ȡm1���������໥����

	//lock_guard��unique_lock
	thread t3(test2);
	t3.join();
	cout << value << endl;
	
	//����ģʽ
	Log::GetInstance().PrintLog("error");

	//condition_variable(��������)
	thread t4(productor);
	thread t5(consumer);
	t4.join();
	t5.join();

	//atomicԭ�Ӳ���ʵ���̰߳�ȫ�·����޸Ĺ������
	//���ֶ�������Ч�ʸ���
	thread t6(func_1);
	thread t7(func_1);
	t6.join();
	t7.join();
	shared_data.store(1);//����ֱ�Ӹ�ֵ����֤������ԭ���Ե�
	cout << shared_data << endl;

	return 0;
}