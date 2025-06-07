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
	std::future<int>future_result = std::async(std::launch::async, add);//程序运行，不影响后续的代码执行，
														//即下一段的add()也在运行
	std::cout << add() << "\n";
	std::cout << future_result.get() << "\n";//等待future_result得到值才会运行这段代码；

	std::packaged_task<int()>task(add);//可移动对象
	std::future<int>future_result1 = task.get_future();
	std::thread t(std::move(task));//执行线程把它放在future_result1中
	t.join();
	std::cout << future_result1.get() << std::endl;
	
	std::promise<int> f;//可以在一个线程中产生并获取一个值
	std::thread t1(func, ref(f));
	t1.join();
	std::cout << f.get_future().get() << std::endl;
	return 0;
}
#endif