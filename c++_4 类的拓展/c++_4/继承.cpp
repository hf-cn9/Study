#include<iostream>
#include<string>
#if 1
using namespace std;

//继承实现页面

class BasePage//  父类/基类
{
public:
	static int m_b;
	int m_a = 10;
	void header()
	{
		cout << "公共的头" << endl;
	}
	void footer()
	{
		cout << "公共的尾" << endl;
	}
};
int BasePage::m_b = 30;
class Member_LoginPage : public BasePage//  子类/派生类
{
public:
	static int m_b;
	int m_a = 20;
	void member()
	{
		cout << "会员登录页面" << endl;
	}
	
};
int Member_LoginPage::m_b = 40;
class Normal_LoginPage : public BasePage
{
public:
	void normal()
	{
		cout << "普通登录页面" << endl;
	}
};
//子类继承了所有父类的成员，私有成员变量会被隐藏
//但是子类的内存会包含父类的所有成员变量

//所有继承都无法访问父类的私有成员变量
//公共继承：父类在子类中的成员权限不变
//保护继承：父类的公共和保护成员在子类中变为保护成员
//私有继承：父类的公共和保护成员在子类中变为私有成员

//创建子类对象时，会先调用父类的构造函数
//析构函数的顺序是先调用子类的析构函数，再调用父类的析构函数
//这和类包含类的构造函数顺序相同
void test02()
{
	Member_LoginPage m;
	m.header();
	m.footer();
	m.member();
	Normal_LoginPage n;
	n.header();
	n.footer();
	n.normal();
}
void test03()
{
	Member_LoginPage m;
	cout << m.m_a << endl;//子父类同名成员变量，子类的成员变量会覆盖父类的成员变量
	cout << m.BasePage::m_a << endl;//访问父类的成员变量,需要加作用域；成员函数同理
	//子类有同名成员函数，父类的成员函数会被隐藏（即使是重构函数也无法访问，必须加作用域才能访问）

}
//静态成员变量可以通过对象和类名访问
//子类在同名成员变量中，利用类名访问父类的同名静态成员变量可以用:
void test04()
{
	//通过对象访问静态成员变量
	Member_LoginPage m;
	cout << m.m_b << endl;//访问子类的静态成员变量
	cout << m.BasePage::m_b << endl;//访问父类的静态成员变量
	//通过类名访问静态成员变量
	cout << Member_LoginPage::m_b << endl;//访问子类的静态成员变量
	cout << Member_LoginPage::BasePage::m_b << endl;//访问父类的静态成员变量
}
//一个子类可以继承多个父类，访问父类中的同名成员变量时，需要用作用域来区分；
class father1 {};
class father2 {};
class son : public father1, public father2
{};
//子类会包含继承的所有的父类成员变量，这在内存中有体现

//菱形继承/钻石继承
class A
{
public:
	int m_a;
};
class A1 : virtual public A 
{};//A1继承A
class A2 : virtual public A 
{};//A2继承A
class B : public A1, public A2 
{};//B继承A1和A2//
//此时B中有两个m_a，而我们只需要一个m_a;
//利用虚继承来解决这个问题,继承时加上virtual关键字,A此时称为虚基类
//这是通过指针来实现的，A1,A1中存储的是m_a的指针，通过对应的vbtable中的偏移量来实现访问
void test05()
{
	B b;
	b.A2::m_a = 20;
	b.A1::m_a = 30;
	cout << b.m_a << endl;//此时只有一个m_a,不会出现不明确,且两次操作都是对同一个m_a的操作
}
int main()
{

	test02();
	test03();
	test04();
	test05();

	system("pause");
	return 0;
}
#endif 