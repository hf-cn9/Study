#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

//deque双端数组,可以对头部进行插入和删除的操作
//vector对头部进行插入和删除的效率低于deque
//vector访问的速度快于deque
void deqPrint(const deque<int>& d)//const防止修改左值
{
	for (deque<int>::const_iterator it = d.begin();it != d.end();it++)//需要对应的迭代器const_iterator
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test21()
{
	deque<int>d1;//默认构造
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	deqPrint(d1);
	deque<int>d2(d1.begin(), d1.end());//构造
	deque<int>d3(3, 100);//3个100
	deque<int>d4(d3);//拷贝构造
}
//赋值
void test22()
{
	deque<int>d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	//operator=
	deque<int>d2;
	d2 = d1;
	//assign
	deque<int>d3;
	d3.assign(d1.begin(),d1.end());
	deque<int>d4;
	d4.assign(10, 100);//十个100
}
//大小操作
void test23()
{
	deque<int>d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	if (!d1.empty())
	{
		cout << "no empty" << endl;
	}
	cout << d1.size() << endl;
	d1.resize(15, 1);
	//d1没有容量的概念
}
//插入删除
void test24()
{
	deque<int>d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);//尾插
	}
	deque<int>d2;
	d2.push_back(10);
	d1.push_front(10);//头插
	d1.pop_front();//头删
	d1.pop_back();//尾删
	d1.insert(d1.begin() + 1, 2, 10);//在1这个位置插入两个10;
	d1.insert(d1.begin(), d2.begin(), d2.end());//在头部插入整个d2;
	d1.erase(d1.begin(), d1.end());//按照区间删除
	d1.clear();//清空
}
//数据存取
//只可访问，不可赋值
void test25()
{
	deque<int> d1;
	for (int i = 0;i < 10; i++)
	{
		d1.push_back(i);
	}
	//operator[]重载
	cout << d1[0] << endl;
	//at(index)
	cout << d1.at(0) << endl;
	//front()获取第一个元素
	cout << d1.front() << endl;
	//back()返回最后一个元素
	cout << d1.back() << endl;
}
//排序
void test26()
{
	deque<int> d1;
	for (int i = 10;i > 0; i--)
	{
		d1.push_back(i);
	}
	deqPrint(d1);
	sort(d1.begin(), d1.end());//algorithm自带的排序算法
	deqPrint(d1);
}

int main3()
{
	test26();
	system("pause");
	return 0;
}