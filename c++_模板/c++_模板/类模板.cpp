#include<iostream>
#include<string>
using namespace std;
#if 0
//ģ��ľ��ޣ�
//�޷�ֱ�Ӳ����Զ������������;
//����ͨ�����廯��ʵ�֣�
class Person
{
public:
	string name;
	int id;
};
template<class T>
bool company(T& a, T& b)//���������޷�����Person����ʵ�֣�����ֱ���
{
	return (a == b);
}
template<>bool company(Person & a, Person & b)//ͨ���ض���ʵ�־Ϳ��Զ�Person���в���
{
	return (a.id == b.id && a.name == b.name);
}
void test_10()
{
	int a = 10;
	int b = 20;
	bool ret = company(a, b);
	if (ret)
	{
		cout << a << "=" << b << endl;
	}
	else if(!ret)
	{
		cout << a << "!=" << b << endl;
	}
}
void test_20()
{
	Person a = { "����",14 };
	Person b = { "����",15 };
	bool ret = company(a, b);
	if (ret)
	{
		cout << "a = b" << endl;
	}
	else if (!ret)
	{
		cout <<"a != b" << endl;
	}
}
//��ģ��
//��ģ���޷������Զ������Ƶ�
//��ģ���ڲ����б��п�����Ĭ�ϲ���;���磺
// <class T1 = string,class T2>����ʱʹ��Person<int>�Ϳ���ֱ�ӵ�����ģ��
//��ģ��ĳ�Ա���������ڵ���ʱ�Ŵ�����
//��ͨ��ĳ�Ա�����������ڴ�������ʱ�ʹ����ˣ�
template<class T1 ,class T2>
class Animal
{
public:
	Animal(T1 NAME, T2 AGE);

	T1 name;
	T2 age;
	void showInfo()
	{
		cout << this->age << "\n"
			<< this->name << endl;
	}
};
void test_30()
{
	Animal<string ,int> dog("dog", 18);//����ȷ�����ͣ��޷������Ƶ�
	cout << dog.age << dog.name << endl;
}
//��ģ����Ϊ��������ʱ�ĵ��÷���
//ֱ��д�������//��õ�����
void showMEG_1(Animal<string,int>&p)
{
	p.showInfo();
}
//����ģ�廯
template<class T1, class T2>
void showMEG_2(Animal<T1, T2>& p)
{
	p.showInfo();
	cout << typeid(T1).name() << endl;//�鿴�Ƶ�����������
	cout << typeid(T2).name() << endl;
}
//��������ģ�廯
template<class T>
void showMEG_3(T& p)
{
	p.showInfo();
	cout << typeid(T).name() << endl;
}
void test_40()
{
	Animal<string, int> p("����",14);
	showMEG_1(p);
	showMEG_2(p);
	showMEG_3(p);
}
//����̳и���ģ��ʱ��������ʱ����ָ������
//��ָ���޷������ڴ�

class dog: public Animal<string, int>
{

};
//���������ָ������ģ�壬������Ҳ��������ģ��
template<class T1,class T2>
class cat : public Animal<T1, T2>
{

};
//��ģ��ĳ�Ա��������ʵ�֣�
template<class T1,class T2>
Animal<T1,T2>::Animal(T1 NAME, T2 AGE)
{
	this->age = AGE;
	this->name = NAME;
}
int main()
{
	test_10();
	test_20();
	test_40();
	system("pause");
	return 0;
}
#endif