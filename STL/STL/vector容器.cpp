#include<iostream>
#include<vector>
#include<algorithm>//算法头文件
using namespace std;
#if 1
//STL六大组件：
//容器：各种数据结构
//算法：各种常用算法
//迭代器：容器与算法的胶合剂
//仿函数：行为类似函数（重载小括号）
//适配器(配接器)：用于修饰仿函数，迭代器或容器接口的东西
//空间配置器：负责空间的配置与管理
void myPrint(int val)
{
	cout << val << endl;
}
void vecPrint(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//vector动态扩展：重新找一个更大的空间，将原本数据和需要增加的数据赋值到这个新空间；（一般比新增的多几个，取决于内部算法）
void test01()
{
	//vector容器，类似数组；
	vector<int>v;//无参构造
	vector<int>v2(v.begin(), v.end());//拷贝v1中的所有元素(构造函数)
	vector<int>v3(10, 100);//10个100用与初始化
	vector<int>v4(v3);//拷贝构造
	//push_back函数，用于尾插数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	//第一种算法
	
	//vector<int>::iterator 拿到容器vector<int>的迭代器类型
	////begin()迭代器，用于指向数组第一个元素位置，rbegin()可以指向最后一个元素；
	//vector<int>::iterator itBegin = v.begin();
	////end()迭代器，用于指向数组最后一个元素的后一个位置，rend()可以指向第一个元素的前一个位置；
	//vector<int>::iterator itEnd = v.end();
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	
	//第二种循环方法：
	/*for (vector<int>::iterator itBegin = v.begin();itBegin != v.end();itBegin++)
	{
		cout << *itBegin << endl;
	}*/

	//第三种
	
	//利用算法中的for_each;
	for_each(v.begin(), v.end(),myPrint);//利用回调技术
}
//容器嵌套容器
void test02()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	for (int i = 0; i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
		v3.push_back(i+2);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	for (vector<vector<int>>::iterator it = v.begin();it != v.end();it++)
	{
		for (vector<int>::iterator it1 = (*it).begin();it1 != (*it).end();it1++)
		{
			cout << *it1 << " ";
		}
		cout << endl;
	}
}
//赋值
void test03()
{
	//push_back()赋值
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	//operator=赋值
	vector<int>v2;
	v2 = v;
	//assign
	vector<int>v3;
	v3.assign(v.begin(), v.end());
	//n个elem
	vector<int>v4;
	v4.assign(10, 100);//10个100
}
//容量和大小
void test04()
{
	vector<int>v;
	for (int i = 0;i < 10; i++)
	{
		v.push_back(i);
	}
	vecPrint(v);
	//判断是否为空
	if (!v.empty())//返回bool
	{
		cout << "noempty" << endl;
	}
	cout << v.capacity() << endl;//返回容量
	cout << v.size() << endl;//返回大小
	v.resize(15, 10);//重新指定大小，多的用10补（不写默认是0），少的删尾部；但是不会重置容量

}
//插入删除
void  test05()
{
	vector<int> v1;
	//尾插
	for (int i = 0;i < 10; i++)
	{
		v1.push_back(i);
	}
	//尾删
	v1.pop_back();
	//插入
	v1.insert(v1.begin()+2, 2, 100);// 第一个参数要求是迭代器(可以直接用+号，因为已经被重构过了)
									// 第二个参数是数量，不写默认为1
									// 第三个参数是插入的内容
	//删除
	v1.erase(v1.begin(),v1.begin()+3);//删除前3个元素（后面元素不写，则只删除一个）；
	//清空
	v1.clear();
}
//存取
//不可以用来赋值，只可以用来访问
void test06()
{
	vector<int> v1;
	for (int i = 0;i < 10; i++)
	{
		v1.push_back(i);
	}
	//operator[]重载
	cout << v1[0] << endl;
	//at(index)
	cout << v1.at(0) << endl;
	//front()获取第一个元素
	cout << v1.front() << endl;
	//back()返回最后一个元素
	cout << v1.back() << endl;
}
//互换容器
void test07()
{
	vector<int> v1;
	for (int i = 0;i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	for (int i = 10;i > 0; i--)
	{
		v2.push_back(i);
	}
	v1.swap(v2);//交换
	vecPrint(v1);
	vecPrint(v2);
	//收缩容量；
	v1.resize(5);
	vector<int>(v1).swap(v1);// 匿名对象创建了一个新v，用v1的数据初始化
							 // swap进行容器交换,使得v1指向了新v的空间，新v指向v1
							 // 新v是匿名对象，本行执行完后，系统自动删除；
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
}
//预留空间,减少扩展次数，减少内存的重新的分配的次数，增加效率
void test08()
{
	vector<int> v1;
	v1.reserve(10000);//预留了10000的空间
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 10000;i++)
	{
		v1.push_back(i);
		if (p != &v1[0])//计算重新开辟空间的次数
		{
			p = &v1[0];
			num++;
		}
	}
	cout << num << endl;
}
int main()
{
	test08();
	system("pause");
	return 0;
}
#endif