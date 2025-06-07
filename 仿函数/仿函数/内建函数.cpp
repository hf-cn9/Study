#include<functional>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#if 0
using namespace std;
//内建函数对象，算术仿函数
//negate 一元取反仿函数；
void test31()
{
	negate<int> n;
	cout << n(50) << endl;
}
//plus 二元加法仿函数；
void test32()
{
	plus<int>p;//默认传同类型的，只允许写一个
	cout << p(10, 20) << endl;
}
//内建函数对象，关系仿函数
//greater  大于仿函数
void test33()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(40);
	//排序
	sort(v1.begin(), v1.end(), greater<int>());//按照大于排序
	for (int i = 0;i < 4;i++)
	{
		cout << v1[i] << endl;
	}
}
//内建函数对象，逻辑仿函数
//逻辑非 logical_not
void test34()
{
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(false);
	v1.push_back(true);
	
	vector<bool>v2;
	v2.resize(v1.size());
	//搬运算法,必须要提前开辟空间
	transform(v1.begin(), v1.end(), v2.begin(),logical_not<int>());
	for (int i = 0;i < 4;i++)
	{
		cout << v2[i] << endl;
	}
}
int main()
{
	test34();
	system("pause");
	return 0;
}
#endif