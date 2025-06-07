#include<iostream>
#if 0 
using namespace std;

class Math
{
	friend ostream& operator<<(ostream& cout, const Math& m); //友元函数声明
public:
	int m_a;
	int m_b;
	Math() {} //默认构造函数
	
	
	Math operator+(const Math& m) //成员函数重载+运算符
	{
		Math temp;
		temp.m_a = this->m_a + m.m_a; 
		temp.m_b = this->m_b + m.m_b;
		return temp; //返回一个新的对象
		
	}
	//左移运算符重载，通常不用成员函数实现

	//成员函数重载前置++运算符
	Math& operator++()
	{
		m_a++;
		m_b++;
		return *this; //返回当前对象
	}
	//成员函数重载后置++运算符
	Math operator++(int)//int作为占位参数，实现函数重载，区分前置和后置++运算符
	{
		Math temp = *this; //保存当前对象
		m_a++;
		m_b++;
		return temp; //返回当前对象，局部对象不应该返回它的引用
	}
	//成员函数重载关系运算符
	bool operator==(const Math& m)
	{
		if (this->m_a == m.m_a && this->m_b == m.m_b)
			return true;
		else
			return false;
	}
	bool operator!=(const Math& m)
	{
		if (this->m_a == m.m_a && this->m_b == m.m_b)
			return false;
		else
			return true;
	}
};
class Math2
{
public:
	int* m_c;
	Math2(int c)
	{
		m_c = new int(c);
	}
	~Math2() //析构函数
	{
		if (m_c != NULL)
		{
			delete m_c; //释放内存
			m_c = NULL;
		}
	}
	//成员函数重载前置=运算符
	//正常情况下,创建一个类，会自动生成一个默认的赋值运算符函数即p2 = p1;
	//但是其实这个函数是浅拷贝的，如果有成员创建在堆区，可能会出现问题
	Math2& operator=(const Math2& m)
	{
		if (m_c != NULL)
		{
			delete m_c; //释放内存
			m_c = NULL;
		}
		m_c = new int(*m.m_c); //深拷贝
		return *this;//为了实现连等的操作，返回对象本身
	}
};
class MyPrint
{
public:
	//重载函数调用运算符(仿函数)
	void operator()(string m)
	{
		cout << m << endl;
	}
};
Math operator+(const Math& m1, const int m2) //全局函数重载+运算符
{
	Math temp;
	temp.m_a = m1.m_a + m2;
	temp.m_b = m1.m_b + m2;
	return temp; //返回一个新的对象
}
ostream& operator<<(ostream &cout, const Math& m) //全局函数重载<<运算符
											 // cout是输出流对象,全局仅能有一个,编译器内部已经定义好了
{
	cout << "m_a = " << m.m_a << endl;
	cout << "m_b = " << m.m_b << endl;
	return cout; //返回输出流对象
}

int main()
{
	Math A;
	A.m_a = 10;
	A.m_b = 20;
	Math B;
	B.m_a = 30;
	B.m_b = 40;
	Math C = A + B; //编译器会自动调用operator+函数,优先调用成员函数,没有则调用全局函数
	cout << "A.m_a + B.m_a = " << C.m_a << endl;
	cout << "A.m_b + B.m_b = " << C.m_b << endl;
	Math D = A + 100; //编译器会自动调用operator+函数,根据参数调用全局函数；
	cout << "A.m_a + 100 = " << D.m_a << endl;
	cout << "A.m_b + 100 = " << D.m_b << endl;
	cout << A << endl;//调用重载<<运算符输出对象A
	cout << ++A << endl;
	cout << A++ << endl;
	cout << A << endl;
	Math2 p1(10);
	Math2 p2(20);
	Math2 p3(30);
	p1 = p2 = p3; //调用重载=运算符
	cout << "p1.m_c = " << *p1.m_c << endl;
	cout << "p2.m_c = " << *p2.m_c << endl;
	cout << "p3.m_c = " << *p3.m_c << endl;
	if (A == B)
	{
		cout << "A == B" << endl;
	}
	else if(A != B)
	{
		cout << "A != B" << endl;
	}
	MyPrint x;
	x("Hello World");
	MyPrint()("Hello World"); //匿名对象调用重载函数
	system("pause");
	return 0;
}
#endif