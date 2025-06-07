#include<iostream>
#include<string>
using namespace std;
#if 0
//模板的局限：
//无法直接操作自定义的数据类型;
//可以通过具体化来实现；
class Person
{
public:
	string name;
	int id;
};
template<class T>
bool company(T& a, T& b)//但是这里无法对于Person进行实现，会出现报错
{
	return (a == b);
}
template<>bool company(Person & a, Person & b)//通过特定的实现就可以对Person进行操作
{
	return (a.id == b.id && a.name == b.name);
}
void test_10()
{
	int a = 10;
	int b = 20;
	bool ret = company(a, b);
	if (ret)
	{
		cout << a << "=" << b << endl;
	}
	else if(!ret)
	{
		cout << a << "!=" << b << endl;
	}
}
void test_20()
{
	Person a = { "张三",14 };
	Person b = { "张三",15 };
	bool ret = company(a, b);
	if (ret)
	{
		cout << "a = b" << endl;
	}
	else if (!ret)
	{
		cout <<"a != b" << endl;
	}
}
//类模板
//类模板无法进行自动类型推导
//类模板在参数列表中可以有默认参数;例如：
// <class T1 = string,class T2>，此时使用Person<int>就可以直接调用类模板
//类模板的成员函数，是在调用时才创建；
//普通类的成员函数，则是在创建对象时就创建了；
template<class T1 ,class T2>
class Animal
{
public:
	Animal(T1 NAME, T2 AGE);

	T1 name;
	T2 age;
	void showInfo()
	{
		cout << this->age << "\n"
			<< this->name << endl;
	}
};
void test_30()
{
	Animal<string ,int> dog("dog", 18);//必须确定类型，无法进行推导
	cout << dog.age << dog.name << endl;
}
//类模板作为函数参数时的调用方法
//直接写清楚类型//最常用的类型
void showMEG_1(Animal<string,int>&p)
{
	p.showInfo();
}
//参数模板化
template<class T1, class T2>
void showMEG_2(Animal<T1, T2>& p)
{
	p.showInfo();
	cout << typeid(T1).name() << endl;//查看推导的数据类型
	cout << typeid(T2).name() << endl;
}
//整个类型模板化
template<class T>
void showMEG_3(T& p)
{
	p.showInfo();
	cout << typeid(T).name() << endl;
}
void test_40()
{
	Animal<string, int> p("张三",14);
	showMEG_1(p);
	showMEG_2(p);
	showMEG_3(p);
}
//子类继承父类模板时，在声明时必须指定类型
//不指定无法分配内存

class dog: public Animal<string, int>
{

};
//如果想灵活的指出父类模板，则子类也必须变成类模板
template<class T1,class T2>
class cat : public Animal<T1, T2>
{

};
//类模板的成员函数类外实现：
template<class T1,class T2>
Animal<T1,T2>::Animal(T1 NAME, T2 AGE)
{
	this->age = AGE;
	this->name = NAME;
}
int main()
{
	test_10();
	test_20();
	test_40();
	system("pause");
	return 0;
}
#endif