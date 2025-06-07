#include<iostream>
#if 0
using namespace std;

//成员变量和成员函数分开存储
class A
{
public:
	static int a; //静态成员变量,不属于对象,属于类本身,不占用对象的内存空间
	int b;
	void func() 
	{
		cout << "A" << endl;
	}//成员函数不占用对象内存
};

//this指针
//1,解决名称冲突

//2,返回对象本身
class B
{
public:
	int a;
	//解决名称冲突
	B(int a)
	{
		this->a = a; 
	}
	//返回对象本身
	//如果不是引用，返回的是一个调用拷贝构造函数的临时对象
	//使用引用的函数，返回的是原对象的一个别名，可以直接操作原对象
	B& Add_person(B& p)
	{
		this->a += p.a; 
		return *this;
	}
	void func()
	{
		if (this == NULL)
		{
			return;//防止空指针调用操作成员变量的成员函数
		}
		cout << "B" << endl;
	}
};

//空指针直接调用成员函数
void test01()
{
	B* p = NULL;
	B p1(10);
	p->func(); //空指针调用成员函数,但是调用操作成员变量的函数会报错
	//p->Add_person(p1); //空指针调用成员变量，报错

}

class C
{
public:
	int m_a;
	mutable int m_b;//可变成员变量:可在const修饰的成员函数中修改
	void Add_C(int i) const//const修饰的成员函数，
						   //不能修改对象的成员变量即等价于 const C* const this
	{
		//this本身是一个指针常量，指向的对象不可修改即等价于 C* const this
		//m_a = 100会报错，等价于this->m_a = 100;
		m_b = 100;

	}
	void func() {}
};
void test()
{
	const C c;//常对象
	//c.m_a = 10;//普通成员变量不能修改
	c.m_b = 20;//可变成员变量可以修改
	c.Add_C(10);//可以调用const修饰的成员函数
	//c.func();//不可以调用普通成员函数
}
int main()
{	
	//空对象会分配一个字节的内存，为了区分空对象占内存的位置
	cout << "sizeof(A) = " << sizeof(A) << endl;
	//this是指向对象的指针
	B p1(10);
	cout << "p1.a = " << p1.a << endl;
	B p2(20);
	p1.Add_person(p2).Add_person(p2).Add_person(p2);//通过*this指针返回对象本身
	cout << "p1.a = " << p1.a << endl;
	system("pause");
	return 0;
}
#endif