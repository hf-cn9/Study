#include<iostream>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

//map������Ԫ�ض���pair�����飩
//map�ĵײ��Ƕ�����
//���Զ������Ҳ�����keyֵ�ظ�
//�ŵ㣺����ͨ��keyֵ���ٲ���value
//multimap:�������ظ���keyֵ
void mapPrint(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin();it != m.end();it++)
	{
		cout << "key:" << (*it).first << " value:" << it->second << "\t";//���ֶ�ȡ��ʽ
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
	mapPrint(m1);//keyֵ���Զ�����
	map<int, int>m2(m1);//��������
	map<int, int>m3;
	m3 = m1;//operator=
}
//��С�ͽ���
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
//�����ɾ��
void test73()
{
	map<int, int>m1;
	//����
	m1.insert(pair<int, int>(1, 10));
	//[]����
	m1[2] = 20;
	//value_type����
	m1.insert(map<int,int>::value_type(3, 30));
	//make_pair;
	m1.insert(make_pair(4,40));
	cout << m1[5] << endl;//���û��5��ֵ��Ĭ��Ϊ0��������ʹ��
	//ɾ��
	m1.erase(++m1.begin());
	m1.erase(3);//����keyɾ��
	m1.erase(m1.begin(), m1.end());//�ӿ�ͷɾ��β
	//���
	m1.clear();
}
//���Һ�ͳ��
void test74()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	//����
	map<int, int>::iterator it = m1.find(1);//����key���ң�û�ҵ�����m.end()
	if (it != m1.end())
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << m1.count(1) << endl;//ͳ���ж��ٸ�keyֵΪ1��
}
//����
class Person
{
public:
	int age;
};
//�º���
class mapSort
{
public:
	bool operator()(const Person& p1, const Person& p2) const//ʵ���Զ�����������
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
	m1.insert(pair<Person, string>(p1, "����"));
	m1.insert(pair<Person, string>(p2, "����"));
	m1.insert(pair<Person, string>(p3, "����"));
	m1.insert(pair<Person, string>(p4, "����"));
	for (map<Person, string, mapSort>::const_iterator it = m1.begin();it != m1.end();it++)
	{
		cout << "key:" << it->first.age << " value:" << it->second << "\t";//���ֶ�ȡ��ʽ
	}
	cout << endl;

}
int main8()
{
	system("pause");
	return 0;
}