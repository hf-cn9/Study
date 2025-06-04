#include<iostream>
#include<set>
#include<algorithm>
#include<string>

using namespace std;

//set容器，二叉树数据类型
void setPrint(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin();it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test61()
{
	set<int>s1;
	//没有尾插，只能用insert插入
	//所有元素都会自动升序排列
	//不允许插入相同元素,不会报错，但是不会插入成功
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);
	s1.insert(40);
	//拷贝构造
	set<int>s2(s1);
	//operator=
	set<int>s3;
	s3 = s1;

}
//大小和交换
void test62()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	if (!s1.empty())
	{
		cout << "no empty" << endl;
	}
	//大小
	//不支持重定义大小
	cout << s1.size() << endl;
	set<int>s2;
	//交换
	s2.swap(s1);
}
//插入和删除
void test63()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//删除
	s1.erase(s1.begin());
	//直接删除指定的值
	s1.erase(20);
	s1.erase(s1.begin(), s1.end());
	//清空
	s1.clear();
}
//查找和统计
void test64()
{
	set<int>s1;
	//插入
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//查找
	//找不到返回s1.end();
	set<int>::iterator ops = s1.find(30);
	if (ops != s1.end())
	{
		cout << "找到了" << endl;
	}
	//统计
	int num = s1.count(30);//统计30的个数
}
//set和multiset的区别
void test65()
{
	//set
	set<int>s1;
	//插入
	//会判断是否插入成功，同时一个对组的数据类型：迭代器和bool
	pair<set<int>::iterator , bool> ret = s1.insert(10);
	if (ret.second)
	{
		cout << "success" << endl;
	}
	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//multiset
	//不会判断是否插入成功，直接返回迭代器
	multiset<int>m_s1;
	m_s1.insert(10);
	m_s1.insert(10);
	m_s1.insert(10);
	m_s1.insert(10);
	for (multiset<int>::const_iterator it = m_s1.begin();it != m_s1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
//对组
void test66()
{
	//第一种创建方法
	pair<string, int>p1("Tom", 20);
	cout << p1.first << " " << p1.second << endl;
	//第二种创建方法
	pair<string, int>p2 = make_pair("Tom", 20);
	cout << p2.first << " " << p2.second << endl;
}
//set容器改变排序
//仿函数
class MyCompare
{
public:
	bool operator()(int v1, int v2) const//vs更新
	{
		return v1 > v2;
	}
};
void test67()
{
	set<int,MyCompare>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	for (set<int,MyCompare>::iterator it = s1.begin();it != s1.end();it++)
	{
		cout << *it << " ";
	}
}
//set容器导入自定义类型
//由于无法使用内置的排序方式，必须使用自己创建的排序方式
class Person
{
public:
	string name;
	int age;
};
class MC
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.age < p2.age;
	}
};
void test68()
{
	Person p1 = { "张三1",14 };
	Person p2 = { "张三2",15 };
	Person p3 = { "张三3",16 };
	Person p4 = { "张三4",17 };
	set<Person,MC>s1;
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	for (set<Person, MC>::iterator it = s1.begin();it != s1.end();it++)
	{
		cout <<it->name<<" " <<it->age<<endl;
	}


}
int main7()
{
	test68();
	system("pause");
	return 0;
}