#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//ν�ʣ�����bool���͵ķº���
//���operator()()����һ��������һԪν��
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
	vector<int>::iterator ops = find_if(v.begin(), v.end(), GreateFive());//������������Ѱ�ҵ�һ������5�����֣����ص�����
	if (ops != v.end())
	{
		cout << *ops << endl;
	}
}
//���operator()()�������������Ƕ�Ԫν��
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