#include<iostream>
#include<string>
#if 0
using namespace std;

class Building;
class GoodFriend3
{
public:
	GoodFriend3();//由于编译器是从上到下编译的，所以要把对Building的操作放在Building类的下面

	void visit();//由于编译器是从上到下编译的，所以要把对Building的操作放在Building类的下面

	Building* friend3;
};
class Building
{
	friend void GoodFriend1(Building* b); //声明友元函数
	friend class GoodFriend2; //声明友元类
	friend void GoodFriend3::visit(); //声明友元成员函数
public:
	Building()
	{
		m_hall = "大厅";
		m_bedroom = "卧室";
	}
public:
	string m_hall;
private:
	string m_bedroom;
};

//友元全局函数可以访问私有成员变量
void GoodFriend1(Building* b)
{
	cout << "友元全局函数访问:" << endl;
	cout << b->m_bedroom << endl; //友元全局函数可以访问私有成员变量
}

//友元类可以访问私有成员变量
class GoodFriend2
{
public:	
	void visit(Building* b)
	{
		cout << "友元类访问：" << endl;
		cout << b->m_bedroom << endl; //友元类可以访问私有成员变量
	}

};

//友元成员函数可以访问私有成员变量
GoodFriend3::GoodFriend3()
{
	friend3 = new Building();
}
void GoodFriend3::visit()
{
	cout << "友元成员函数访问：" << endl;
	cout << friend3->m_bedroom << endl; //友元成员函数可以访问私有成员变量
}
int main()
{
	Building T1;
	GoodFriend1(&T1); //调用友元函数
	GoodFriend2 T2; //调用友元类
	T2.visit(&T1); //调用友元类
	GoodFriend3 T3; //调用友元成员函数
	T3.visit(); //调用友元成员函数
	system("pause");
	return 0;
}
#endif