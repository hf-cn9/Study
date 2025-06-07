#include<iostream>
#include<string>
#if 1
using namespace std;
//仿函数可以有自己的返回值，可以有参数
class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
//超出普通函数的概念，可以有自己的状态:(例如记录函数调用了多少次，可以在内部直接创建一个变量用于记录)
class MyPrint
{
public:
	void operator()(string test)
	{
		cout << test << endl;
	}
};
//可以用作参数用于传递
void Print(MyPrint& m, string& s)
{
	m(s);
}
void test11()
{
	MyAdd ma;
	cout << ma(10, 20) << endl;
	MyPrint()("2020");
}
int main()
{
	test11();
	
	system("pause");
	return 0;
}
#endif