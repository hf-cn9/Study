#include<iostream>
#include<list>

using namespace std;
#if 0
//list容器,链表
void lisPrint(const list<int>& lis)
{
	for (list<int>::const_iterator it = lis.begin();it != lis.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test51()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	//按照区间的构造函数
	list<int>l1(l.begin(),l.end());
	//拷贝构造
	list<int>l2(l);
	//n个elem;
	list<int>l3(10, 100);

}
//赋值和交换
void test52()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	list<int > l1;
	//operator=
	l1 = l;
	//assign
	list<int>l2;
	l2.assign(l.begin(),l.end());
	//n个elem
	list<int>l3;
	l3.assign(10, 100);
	//交换
	l.swap(l1);//list容器内自带的swap
}
//大小操作
void test53()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	if (!l.empty())
	{
		cout << "no empty" << endl;
	}
	cout << l.size() << endl;
	l.resize(7, 10);//重定大小
	lisPrint(l);
}
//插入删除
void test54()
{
	list<int>l;
	//尾插
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	//头插
	l.push_front(20);
	lisPrint(l);
	//尾删
	l.pop_back();
	//头删
	l.pop_front();
	//插入
	list<int>::iterator it = l.begin();

	l.insert(++it, 100);//list不能直接用begin()+num的方式直接,迭代器不支持跳跃式访问，仅支持双向
	//删除
	l.erase(++it);
	//根据值移除
	l.remove(20);//移除所有的20
	//清空
	l.clear();

}
//数据存取
void test55()
{
	list<int>l;
	//尾插
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	//仅有两种存取方式,非线性空间,不支持[]和at();
	//访问头部元素
	cout << l.front() << endl;
	//访问尾部元素
	cout << l.back() << endl;
}
//逆序实现：
bool Mycompare(int v1,int v2)
{
	return v1 > v2;
}
//反转和排序
void test56()
{
	list<int>l;
	//尾插
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	//反转整个链表
	l.reverse();
	lisPrint(l);
	//排序
	l.sort();
	//所有不支持随机访问的容器，不支持algorithm的算法
	//内部会提供一些自带的算法
	lisPrint(l);
	l.sort(Mycompare);//提供相应的函数实现降序
	lisPrint(l);
}

int main()
{
	
	system("pause");
	return 0;
}
#endif