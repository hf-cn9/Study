#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//谓词：返回bool类型的仿函数
//如果operator()()接受一个参数是一元谓词
class GreateFive
{
public:
	bool operator()(int v)
	{
		return v > 5;
	}
};
void test21()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator ops = find_if(v.begin(), v.end(), GreateFive());//匿名函数对象，寻找第一个大于5的数字，返回迭代器
	if (ops != v.end())
	{
		cout << *ops << endl;
	}
}
//如果operator()()接受俩个参数是二元谓词
class MySort
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
void test22()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end(), MySort());
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main2()
{
	test22();
	system("pause");
	return 0;
}