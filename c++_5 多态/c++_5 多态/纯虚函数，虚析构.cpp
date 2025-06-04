#include<iostream>
#include<string>
using namespace std;

class Base//只要有一个纯虚函数，就是抽象类
		  //无法实例化对象（不可以用来创建对象)
		  //子类必须重写纯虚函数，不然也是抽象类
		  //但是可以用这个类创建一个指针，也就是非实例化
{
public:
	virtual void func() = 0;//纯虚函数
	Base() //父类中有含参构造，则父类中必须也有默认构造，否则子类不可以有默认构造
		   //子类中有含参构造，则子类中必须也有默认构造，否则父类不可以有默认构造
	{
		cout << "Base的默认构造函数" << endl;
	
	}
	//virtual ~Base()//虚析构
	//{
	//	cout << "Base的析构函数" << endl;
	//}
	virtual ~Base() = 0;//纯虚析构，但是必须有实现
						//有了纯虚析构，这个类也是抽象类
						//父类有纯虚析构，子类可以不写虚析构
						

};
Base::~Base()//纯虚析构的实现
{
	cout << "Base的纯虚析构" << endl;
}
class Element : public Base
{
public:
	string* m_name;
	virtual void func()
	{
		cout << *m_name <<" Element的Base纯虚构函数的重写 " << endl;
	}
	Element()
	{
		cout << "Element的默认构造函数" << endl;
	}
	Element(string name)
	{
		m_name = new string(name);
		cout << "Element的构造函数" << endl;
	}
	
	~Element()
	{
		if (m_name != NULL)
		{
			delete m_name;
			m_name = NULL;
			cout << "Element的析构函数" << endl;
		}
		
	}
};
void test02()
{
	Base* p = new Element("hello");
	p->func();
	delete p;//和虚函数一样，
			 //Base创建的指针释放时会选择走Base的析构函数，而不走Element的析构函数,导致内存泄露

}
//int main()
//{
//	
//	test02();
//
//	system("pause");
//	return 0;
//}