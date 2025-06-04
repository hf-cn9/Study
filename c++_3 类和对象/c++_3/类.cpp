#include<iostream>
using namespace std;

const double PI = 3.14;
//设计一个圆类，求圆的周长和面积；
class circle
{
	
public:
	//统称成员：
	//属性//成员变量//成员属性
	double radius; //半径
	
	//行为//成员函数//成员方法
	//获取圆的周长和面积；
	double getPerimeter()
	{
		return 2 * PI * radius;
	} 

	//创建对象时，自动调用的函数：
	//构造函数:(一般用于初始化对象的属性)
	//构造函数：创建对象时自动调用的函数；可以有多个构造函数（重载），参数不同；构造函数没有返回值；
	circle() 
	{
		cout << "默认构造函数" << endl;
	}//系统默认构造函数是空实现
	circle(double r)//构造函数重载；
	{
		radius = r; //初始化半径；r是参数；radius是成员变量；
		cout << "含参数构造函数被调用" << endl;
	}

	//拷贝构造函数：
	//拷贝构造函数：创建对象时，使用已有对象初始化新对象时自动调用的函数；参数是引用类型；拷贝构造函数没有返回值；
	circle(const circle& c)
	{
		radius = c.radius; //拷贝半径；
		cout << "拷贝构造函数被调用" << endl;
	}
	//销毁对象时，自动调用的函数：
	//析构函数：
	//析构函数：对象销毁时自动调用的函数；没有参数；析构函数没有返回值；
	~circle() {}//系统默认析构函数是空实现
	
};

class Students
{

	//访问权限：public、protected、private；
	//public：公有成员，类的外部可以访问；类的内部也可以访问；
public:
	//属性
	string name;
	
	//protected：保护成员，类的外部不可以访问；类的内部可以访问；子类也可以访问；
protected:
	int age = 20;
	//private：私有成员，类的外部不可以访问；类的内部可以访问；子类不可以访问；
private:
	int Id = 1001;
public:
	//行为
	void showInfo()
	{
		cout << "姓名：" << name << endl;
		cout << "年龄：" << age << endl;
		cout << "学号：" << Id << endl;
	}
};
//class 和 struct 的区别：
//默认访问权限不同:class 默认是private，struct 默认是public；


class Person
{
public:
	//name可读可写权限；
	void set_name()//可写权限
	{
		cout << "请输入姓名：";
		cin >> m_name;
	}
	string get_name()//可读权限
	{
		return m_name;
	}
	//age只读权限；
	int get_age()//只读权限
	{
		return m_age;
	}
	//id只写权限；
	void set_id(int id)//只写权限
	{
		m_id = id;
	}
private://成员私有化，实现封装；
	string m_name;//
	int m_age;
	int m_id;
};

void test01()//构造函数调用方法
{
	//1,括号法
	circle c1; //创建一个圆对象,半径为0；调用默认构造函数；(注意不能加括号，会认为是函数的声明)
	circle c2(10); //创建一个圆对象；半径为10；调用重载的构造函数；
	circle c3(c2); //创建一个圆对象；复制c2的半径；调用拷贝构造函数；
	//2，显示法
	circle c4 = circle(10); //创建一个圆对象；半径为10；调用重载的构造函数；(匿名对象,当前行执行后就会直接释放)
	circle c5 = circle(c4); //创建一个圆对象；复制c4的半径；调用拷贝构造函数；
	//不能用circle(c4)直接拷贝一个匿名对象，编译器会认为是circle c4的对象声明；
	//3，赋值法
	circle c6 = 10; //创建一个圆对象；半径为10；调用重载的构造函数；等价于circle c6 = circle(10);

}
//拷贝构造函数调用方法
//1,直接传值法
void test02()
{
	circle c1(20); 
	circle c2(c1);

}
//2,引用传值法
void test03(circle c)
{
}
//3,
circle test04()
{
	circle c1;
	cout << &c1 << endl;
	return c1;
}
void test05()
{
	circle c2 = test04();//RVO优化,直接c2直接占用了test04的内存空间；因此没有调用拷贝构造函数；
	cout << &c2 << endl;
}
//如果提供一个有参构造函数，系统就不会提供默认构造函数了；
//如果提供一个拷贝构造函数，系统就不会提供其他构造函数了；

//深拷贝和浅拷贝：
//深拷贝：析构函数释放内存时，不会导致重复释放；
// 实现方法：int *arr = new int[10]; //重新生成一个堆区内存，存储10这个数据；
//（编译器自带的构造函数)浅拷贝：析构函数释放内存时，可能会导致重复释放；

//构造函数初始化列表：
class person
{
public:	
	int m_age;
	int m_id;
	person(int age, int id) : m_age(age), m_id(id) //构造函数初始化列表；
	{
		cout << "构造函数被调用" << endl;
	}

};
//创建对象时，如果包含了其他类的对象，就会优先调用其他类的构造函数
//其他类的构造函数调用顺序是从上到下；
//析构和构造函数的调用顺序是相反的；
//其他类的对象叫做对象成员；

//静态成员：所有对象共享同一份数据（内存地址相同，后续一旦修改，所有对象都修改）；
//1，类内声明，类外初始化；
//2，编译阶段会为静态成员分配内存；
class Student
{
public:
	static int m_age;//静态成员变量；类内声明；（可以通过Student::m_age这样的类名直接访问）；
	int m_id; //普通成员变量；类内声明；（只能通过对象访问）；
	//静态成员函数：
	//所有对象共享一份函数；
	//只能访问静态成员变量；
	static void showInfo()
	{
		//cout << "身份卡：" << m_id << endl;会报错，不能在静态成员函数中访问非静态成员变量；(不清楚对象的身份)
		cout << "年龄：" << m_age << endl;
	}
};
int Student::m_age = 20; //类外初始化；仅能在类外初始化一次；Student表示在Student作用域下；


int main()
{
	circle c1; //创建一个圆对象；
	c1.radius = 10; //设置半径；
	cout << "周长：" << c1.getPerimeter() << endl;

	Students student1; //创建一个学生对象；
	student1.name = "张三";
	student1.showInfo(); //调用成员函数，打印学生信息；

	//test01();
	//test02();
	//test03(c1);
	test05();

	system("pause");
	return 0;
}