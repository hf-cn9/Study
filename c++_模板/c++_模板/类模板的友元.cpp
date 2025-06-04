#pragma once
#include<iostream>
#include<string>

using namespace std;

template<class T1, class T2>
class Person;//��ΪPerson���·�ʹ�ã�������ǰ����
template<class T1, class T2>
void showInfo2(Person<T1, T2> p)//��Ҫ�ñ�����֪��ʵ�֣�����������������
{
	cout << p.m_id << "\n"
		<< p.m_name << endl;
}


template<class T1, class T2>
class Person
{
	friend void showInfo1(Person<T1, T2> p)//ȫ�ֺ���������ʵ�֣�����Ԫ��������ȷ����ȫ�ֺ���
	{
		cout << p.m_id << "\n"
			<< p.m_name << endl;
	}
	friend void showInfo2<>(Person<T1, T2> p);//ȫ�ֺ���������ʵ��showInfo2<>������һ������ģ���ʵ��
public:
	Person(T1 id, T2 name)
	{
		this->m_id = id;
		this->m_name = name;
	}
	
private:
	T1 m_id;
	T2 m_name;
};
void test_12()
{
	Person<int, string>p1(14,"����");
	showInfo1(p1);
	showInfo2(p1);
}
int main3()
{
	test_12();
	system("pause");
	return 0;
}
