#include<functional>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#if 0
using namespace std;
//�ڽ��������������º���
//negate һԪȡ���º�����
void test31()
{
	negate<int> n;
	cout << n(50) << endl;
}
//plus ��Ԫ�ӷ��º�����
void test32()
{
	plus<int>p;//Ĭ�ϴ�ͬ���͵ģ�ֻ����дһ��
	cout << p(10, 20) << endl;
}
//�ڽ��������󣬹�ϵ�º���
//greater  ���ڷº���
void test33()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(40);
	//����
	sort(v1.begin(), v1.end(), greater<int>());//���մ�������
	for (int i = 0;i < 4;i++)
	{
		cout << v1[i] << endl;
	}
}
//�ڽ����������߼��º���
//�߼��� logical_not
void test34()
{
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(false);
	v1.push_back(true);
	
	vector<bool>v2;
	v2.resize(v1.size());
	//�����㷨,����Ҫ��ǰ���ٿռ�
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