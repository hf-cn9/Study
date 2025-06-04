#include<iostream>
using namespace std;

//多态：
//静态多态：函数重载和运算符重载（编译时地址确定）
//动态多态：派生类和虚函数实现运行时多态（运行时地址确定）
class Animal
{
public:
	virtual void speak() //此时Animal中存储的是指向vftable的指针
						 //基类定义为虚函数，派生类自动定义为虚函数
						 //vftable中会存储&Animal::speak，也就是存储的是函数地址
	{
		cout << "Animal speak" << endl;
	}
};
class Cat : public Animal
{
public:
	void speak()//子类重写父类函数，此时在子类的vftable中会覆盖父类的speak()的入口地址
				//这样使用父类的指针或引用，去调用子类的对象时，会发生多态
				//从vftable中找到正确的函数接口地址进入，这样可以正确输出需要的内容
	{
		cout << "Cat speak" << endl;
	}
};
void doSpeak(Animal& animal)//等价于Animal& animal = cat;
							//c++允许父子类的类型直接转换，不需要强制类型转换
{	
	animal.speak();
}
void test01()
{
	Cat cat;
	doSpeak(cat);
	//因为编译时地址已经确定，此时调用的是父类的函数
	//可以通过给基类speak()函数加上virtual，实现多态，就可以正确输出
}

int main()
{
	test01();
	system("pause");
	return 0;
}