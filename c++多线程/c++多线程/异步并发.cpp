#include<iostream>
#include<future>
#if 0
int add() {
	int i = 0;
	for (int j =0 ;j < 100;j++) {
		i += 1;
	}
	return i;
}
void func(std::promise<int>& f) {
	f.set_value(100);
}
int main() {
	std::future<int>future_result = std::async(std::launch::async, add);//�������У���Ӱ������Ĵ���ִ�У�
														//����һ�ε�add()Ҳ������
	std::cout << add() << "\n";
	std::cout << future_result.get() << "\n";//�ȴ�future_result�õ�ֵ�Ż�������δ��룻

	std::packaged_task<int()>task(add);//���ƶ�����
	std::future<int>future_result1 = task.get_future();
	std::thread t(std::move(task));//ִ���̰߳�������future_result1��
	t.join();
	std::cout << future_result1.get() << std::endl;
	
	std::promise<int> f;//������һ���߳��в�������ȡһ��ֵ
	std::thread t1(func, ref(f));
	t1.join();
	std::cout << f.get_future().get() << std::endl;
	return 0;
}
#endif