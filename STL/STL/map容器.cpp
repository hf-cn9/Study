#include<iostream>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

//map中所有元素都是pair（对组）
//map的底层是二叉树
//会自动排序，且不允许key值重复
//优点：可以通过key值快速查找value
//multimap:允许有重复的key值
void mapPrint(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin();it != m.end();it++)
	{
		cout << "key:" << (*it).first << " value:" << it->second << "\t";//两种读取方式
	}
	cout << endl;
}
void test71()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	mapPrint(m1);//key值会自动排序；
	map<int, int>m2(m1);//拷贝构造
	map<int, int>m3;
	m3 = m1;//operator=
}
//大小和交换
void test72()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	if (!m1.empty())
	{
		cout << "no empty" << endl;
	}
	cout << m1.size() << endl;
	map<int, int>m2;
	m1.swap(m2);
	mapPrint(m1);
}
//插入和删除
void test73()
{
	map<int, int>m1;
	//插入
	m1.insert(pair<int, int>(1, 10));
	//[]重载
	m1[2] = 20;
	//value_type类型
	m1.insert(map<int,int>::value_type(3, 30));
	//make_pair;
	m1.insert(make_pair(4,40));
	cout << m1[5] << endl;//如果没有5，值会默认为0，不建议使用
	//删除
	m1.erase(++m1.begin());
	m1.erase(3);//按照key删除
	m1.erase(m1.begin(), m1.end());//从开头删到尾
	//清空
	m1.clear();
}
//查找和统计
void test74()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	//查找
	map<int, int>::iterator it = m1.find(1);//根据key查找，没找到返回m.end()
	if (it != m1.end())
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << m1.count(1) << endl;//统计有多少个key值为1；
}
//排序
class Person
{
public:
	int age;
};
//仿函数
class mapSort
{
public:
	bool operator()(const Person& p1, const Person& p2) const//实现自定义类型排序
	{
		return p1.age > p2.age;
	}
};

void test75()
{
	map<Person, string,mapSort>m1;
	Person p1 = { 14 };
	Person p2 = { 15 };
	Person p3 = { 16 };
	Person p4 = { 17 };
	m1.insert(pair<Person, string>(p1, "张三"));
	m1.insert(pair<Person, string>(p2, "李四"));
	m1.insert(pair<Person, string>(p3, "王五"));
	m1.insert(pair<Person, string>(p4, "赵六"));
	for (map<Person, string, mapSort>::const_iterator it = m1.begin();it != m1.end();it++)
	{
		cout << "key:" << it->first.age << " value:" << it->second << "\t";//两种读取方式
	}
	cout << endl;

}
int main8()
{
	system("pause");
	return 0;
}