#pragma once
#include<iostream>
#include<string>

using namespace std;

template<class T1, class T2>
class Person;//因为Person在下方使用，必须提前声明
template<class T1, class T2>
void showInfo2(Person<T1, T2> p)//需要让编译器知道实现，后续才能正常声明
{
	cout << p.m_id << "\n"
		<< p.m_name << endl;
}


template<class T1, class T2>
class Person
{
	friend void showInfo1(Person<T1, T2> p)//全局函数在类内实现，加友元来声明，确保是全局函数
	{
		cout << p.m_id << "\n"
			<< p.m_name << endl;
	}
	friend void showInfo2<>(Person<T1, T2> p);//全局函数在类外实现showInfo2<>声明是一个函数模板的实现
public:
	Person(T1 id, T2 name)
	{
		this->m_id = id;
		this->m_name = name;
	}
	
private:
	T1 m_id;
	T2 m_name;
};
void test_12()
{
	Person<int, string>p1(14,"张三");
	showInfo1(p1);
	showInfo2(p1);
}
int main3()
{
	test_12();
	system("pause");
	return 0;
}
