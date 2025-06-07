#pragma once
#include<iostream>
#include<string>
#include"Class.cpp"//类模板创建对象不会创建成员函数，如果包含的是Class.h，编译器不知道成员函数的具体实现
//但是一般不包含源码cpp,对于类模板一般在头文件中写成.hpp文件，将类模板中的代码全写在一起；

#if 0
using namespace std;

//由于类模板的成员函数是在调用时创建，导致分文件编写时调用不到
void test_11()
{
	Person<string, int> p("张三", 14);
	p.showInfo();
}
int main()
{
	test_11();
	system("pause");
	return 0;
}
#endif