#include<iostream>
#include<set>
#include<algorithm>
#include<string>

using namespace std;

//set��������������������
void setPrint(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin();it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test61()
{
	set<int>s1;
	//û��β�壬ֻ����insert����
	//����Ԫ�ض����Զ���������
	//�����������ͬԪ��,���ᱨ�����ǲ������ɹ�
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);
	s1.insert(40);
	//��������
	set<int>s2(s1);
	//operator=
	set<int>s3;
	s3 = s1;

}
//��С�ͽ���
void test62()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	if (!s1.empty())
	{
		cout << "no empty" << endl;
	}
	//��С
	//��֧���ض����С
	cout << s1.size() << endl;
	set<int>s2;
	//����
	s2.swap(s1);
}
//�����ɾ��
void test63()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//ɾ��
	s1.erase(s1.begin());
	//ֱ��ɾ��ָ����ֵ
	s1.erase(20);
	s1.erase(s1.begin(), s1.end());
	//���
	s1.clear();
}
//���Һ�ͳ��
void test64()
{
	set<int>s1;
	//����
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//����
	//�Ҳ�������s1.end();
	set<int>::iterator ops = s1.find(30);
	if (ops != s1.end())
	{
		cout << "�ҵ���" << endl;
	}
	//ͳ��
	int num = s1.count(30);//ͳ��30�ĸ���
}
//set��multiset������
void test65()
{
	//set
	set<int>s1;
	//����
	//���ж��Ƿ����ɹ���ͬʱһ��������������ͣ���������bool
	pair<set<int>::iterator , bool> ret = s1.insert(10);
	if (ret.second)
	{
		cout << "success" << endl;
	}
	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//multiset
	//�����ж��Ƿ����ɹ���ֱ�ӷ��ص�����
	multiset<int>m_s1;
	m_s1.insert(10);
	m_s1.insert(10);
	m_s1.insert(10);
	m_s1.insert(10);
	for (multiset<int>::const_iterator it = m_s1.begin();it != m_s1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
//����
void test66()
{
	//��һ�ִ�������
	pair<string, int>p1("Tom", 20);
	cout << p1.first << " " << p1.second << endl;
	//�ڶ��ִ�������
	pair<string, int>p2 = make_pair("Tom", 20);
	cout << p2.first << " " << p2.second << endl;
}
//set�����ı�����
//�º���
class MyCompare
{
public:
	bool operator()(int v1, int v2) const//vs����
	{
		return v1 > v2;
	}
};
void test67()
{
	set<int,MyCompare>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	for (set<int,MyCompare>::iterator it = s1.begin();it != s1.end();it++)
	{
		cout << *it << " ";
	}
}
//set���������Զ�������
//�����޷�ʹ�����õ�����ʽ������ʹ���Լ�����������ʽ
class Person
{
public:
	string name;
	int age;
};
class MC
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.age < p2.age;
	}
};
void test68()
{
	Person p1 = { "����1",14 };
	Person p2 = { "����2",15 };
	Person p3 = { "����3",16 };
	Person p4 = { "����4",17 };
	set<Person,MC>s1;
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	for (set<Person, MC>::iterator it = s1.begin();it != s1.end();it++)
	{
		cout <<it->name<<" " <<it->age<<endl;
	}


}
int main7()
{
	test68();
	system("pause");
	return 0;
}