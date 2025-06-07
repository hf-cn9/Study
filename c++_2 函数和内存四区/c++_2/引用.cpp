#include<iostream>
using namespace std;

//引用传递函数的参数；
#if 1
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int& test()
{
	static int a = 10;
	return a;
}
void show(const int& value)//仅需要打印value的值，不需要改变value的值；减少占用，又不会改变值；
{
	cout << "value=" <<value<< endl;
}


int main()
{
	//引用：给变量起别名；
	int a = 10;
	int& b = a;//b是a的别名；引用的本质是指针常量
	//等价于int* const p = &a;指针常量指向的地址不可以改变；
	//引用必须初始化；int& b; //error:引用必须初始化；
	//int& b = 10; //error:引用不能引用字面量；
	//引用一旦初始化后，不可以更改；
	int c = 20;
	b = c; //是把c的值赋给a指向的内存，而不是把b指向c；
	//等价于*p = c;

	int d = 30;
	
	swap(c, d);//c和d的值交换；


	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	int& e = test();//e是a的别名；
	test() = 100;//a的值变为100；函数调用可以作为左值；
	cout << "e = " << e << endl;
	

	//常量引用：指向的值不可以改变；
	const int& f = 10;//f指向储存10的内存，但是f不可以改变10的值；
	//等价于int temp = 10; const int& f = temp;
	//f = 20; //error:常量引用不可以改变值；
	//作用：防止误操作；
	show(f);//value=10

	system("pause");
	return 0;
}
#endif