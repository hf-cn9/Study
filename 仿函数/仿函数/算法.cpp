#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<ctime>
#if 0
using namespace std;
//for_each(����������������������º���)���ڱ���
void print01(int v)
{
	cout << v << " ";
}
class print02
{
public:
	void operator()(int v)
	{
		cout << v << " ";
	}
};
void MyPrint(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test41()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(40);
	for_each(v1.begin(), v1.end(), print01);//����һ��������
	for_each(v1.begin(), v1.end(), print02());//����һ������
}
//transform(����������������������º���)������������һ������
int func1(int v)
{
	return v;
}
void test42()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(40);
	vector<int>v2;
	v2.resize(v1.size());//reserve������Ԥ���ռ䣬��������������Ԫ�ض���
						 //resize�Ǹı������Ĵ�С�����Ҵ�����������Ӧ����resize
	transform(v1.begin(), v1.end(), v2.begin(), func1);
	for_each(v2.begin(), v2.end(), print01);
}
//�����㷨
class find1//ν��
{
public:
	bool operator()(int val)
	{
		return val > 10;
	}
};
void test43()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	// find����,�ҵ����ض�Ӧ��������û�ҵ�����end();
	// �Զ���������Ҫ���ط���bool��==�ţ����ڸ��ߵײ��������ж�
	vector<int>::iterator it = find(v1.begin(), v1.end(), 10);
	cout << *it << endl;
	// find_if����,�������ң��ҵ����ض�Ӧ��������û�ҵ�����end()��������������Ҫһ��ν��
	it = find_if(v1.begin(), v1.end(), find1());
	cout << *it << endl;
	// adjacent_find,���������ظ�Ԫ�أ��ҵ����������ظ��ĵ�һ��Ԫ�صĵ�������û�ҵ�����end��
	it = adjacent_find(v1.begin(), v1.end());
	cout << *it << endl;
	// binary_search,���ֲ��ҷ����Ƿ�������Ԫ�أ�����bool���������ڲ������������
	bool ret = binary_search(v1.begin(), v1.end(), 20);
	if (ret)
	{
		cout << "ok!" << endl;
	}
	// countͳ��Ԫ�ظ���
	// �Զ���������Ҫ���ط���bool��==�ţ����ڸ��ߵײ��������ж�
	int num = count(v1.begin(), v1.end(), 10);
	cout << num << endl;
	// count_if���������ҷ���Ҫ���Ԫ�صĸ���
	// ��Ҫһ��ν��
	num = count_if(v1.begin(), v1.end(), find1());
	cout << num << endl;
}
//����
void test44()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	//random_shuffle ����Ԫ�أ�ʹ������Ԫ������
	random_shuffle(v1.begin(), v1.end());
	MyPrint(v1);
	//sort ��Ԫ������,���Ԫ�ز���Ĭ��������Ļ���Ҫ��һ��ν��
	sort(v1.begin(), v1.end());
	MyPrint(v1);
	//merge ��������������кϲ���һ�����������,������ͬ�򣨼�ͬΪ�������
	vector<int>v2;
	vector<int>targe1;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), func1);
	targe1.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(),targe1.begin());
	MyPrint(targe1);
	//reverse ��ת����������ʵ�����򣨷�����
	reverse(v1.begin(), v1.end());
	MyPrint(v1);
}
//�������滻
void test45()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	vector<int>v2;
	v2.resize(v1.size());//��ǰ���ٿռ�
	//copy ����
	copy(v1.begin(), v1.end(), v2.begin());
	MyPrint(v2);
	//replace �滻��Ԫ��Ϊ��Ԫ��
	replace(v1.begin(), v1.end(), 10, 30);//���е�10����30��û�ҵ������滻��Ҳ���ᱨ��
	MyPrint(v1);
	//replace_if ����������Ԫ�ػ�����Ԫ��
	replace_if(v1.begin(), v1.end(), find1(), 10);//���д���10�Ķ�����10;
	MyPrint(v1);
	//swap ������������(ͬ���Ͳſ���)
	swap(v1, v2);
	MyPrint(v1);
}
//�������������㷨(numeric����㷨)
void test46()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	//accumulate �����ۼӺ�(��������������ʼ�ۼ�ֵ)
	int num = accumulate(v1.begin(), v1.end(), 0);
	cout << num << endl;
	//fill ��ָ�������ڵ�Ԫ�أ����Ϊָ������
	fill(v1.begin(), v1.end(), 10);
	MyPrint(v1);
}
//���ü����㷨
void test47()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	vector<int>v2;
	vector<int>v3;
	v2.push_back(20);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	//��Ŀ����ȡ��С
	v3.resize((v2.size() > v1.size() ? v1.size() : v2.size()));
	//min�㷨ȡ��С
	v3.resize(min(v1.size(), v2.size()));
	//set_intersection ��ȡ�������ϵĽ���,����һ��������
	//��������������
	vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),v3.begin());
	//����ʱ�������ĵ�����ʹ�û�ȡ�ĵ���������Ϊ���ٿռ�ʱ���п��ܴ���δ��ʹ�ö����Ϊ0�Ŀռ�
	for_each(v3.begin(), itend, print01);
	cout << endl;
	// set_union ��ȡ�������ϵĲ���������һ��������
	// ��������������
	v3.clear();
	v3.resize(v1.size() + v2.size());
	itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itend, print01);
	cout << endl;
	// set_difference ��ȡ�������ϵĲ,����һ��������
	// ��������������
	v3.clear();
	v3.resize(v1.size());
	itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());//v1 - v2�����
	for_each(v3.begin(), itend, print01);
	cout << endl;
}
int main()
{
	srand((unsigned int)time(NULL));
	test47();
	system("pause");
	return 0;
}
#endif