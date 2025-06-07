#include<iostream>
#if 0
using namespace std;

int fuc(int a, int b = 20, int c = 30)
//int fuc(int a, int b = 20, int c)//error:默认参数只能从右往左设置；b之后必须有默认参数；
{
	return a + b + c;
}
//int fuc2(int a = 10, int b = 20, int c = 30);//如果定义时有默认参数，声明不能有默认参数；
int fuc2(int a = 10, int b = 20, int c = 30)//如果声明时有默认参数，定义不能有默认参数；
{
	return a + b + c;
}
int fuc3(int a, int)//占位参数
{
	cout << "a = " << a << endl;
	return 0;
}
//函数重载：函数名相同，参数列表不同；提高复用性；
//函数重载满足条件：
//1.函数名相同；
//2.参数列表不同：或参数个数不同，或参数类型不同，或参数顺序不同；
//3.同一个作用域下；
int fuc3(int a)//重载，参数个数不同；其他同理；
{
	cout << "a = " << a << endl;
	return 0;
}
//函数重载注意事项：
//1.引用作为重载条件；
void fuc4(int& a)//int& a = 10;error:引用必须引用变量；
{
	cout << "&a " << endl;
}
void fuc4(const int& a)//const int& a = 10;合法；
{
	cout << "const &a " << endl;
}
//2.函数重载碰到默认参数；
void fuc5(int a, int b = 10)//运行合法，可以调用fuc5(10,10);
{
	cout << "a，b " << endl;
}
void fuc5(int a)//运行合法，但是调用fuc5(10)会报错;
{
	cout << "a " << endl;
}


int main()
{
	fuc(10, 20, 30);//60
	fuc(10, 20);//60
	fuc(10);//60
	fuc(10, 30);//70，优先使用传入的参数；
	//fuc2();程序执行报错，因为重定义了默认参数；
	fuc3(10, 10);//必须要有第二个参数；
	fuc3(20);//a = 10
	int a = 10;
	fuc4(a);//因为a是变量，所以调用int&的函数；
	fuc4(10);//因为10是常量，所以调用const int&的函数；
	//fuc5(10);//调用报错，因为函数重载时，调用时不明确；


	system("pause");
	return 0;

}
#endif