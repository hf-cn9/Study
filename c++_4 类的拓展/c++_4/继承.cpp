#include<iostream>
#include<string>
#if 1
using namespace std;

//�̳�ʵ��ҳ��

class BasePage//  ����/����
{
public:
	static int m_b;
	int m_a = 10;
	void header()
	{
		cout << "������ͷ" << endl;
	}
	void footer()
	{
		cout << "������β" << endl;
	}
};
int BasePage::m_b = 30;
class Member_LoginPage : public BasePage//  ����/������
{
public:
	static int m_b;
	int m_a = 20;
	void member()
	{
		cout << "��Ա��¼ҳ��" << endl;
	}
	
};
int Member_LoginPage::m_b = 40;
class Normal_LoginPage : public BasePage
{
public:
	void normal()
	{
		cout << "��ͨ��¼ҳ��" << endl;
	}
};
//����̳������и���ĳ�Ա��˽�г�Ա�����ᱻ����
//����������ڴ�������������г�Ա����

//���м̳ж��޷����ʸ����˽�г�Ա����
//�����̳У������������еĳ�ԱȨ�޲���
//�����̳У�����Ĺ����ͱ�����Ա�������б�Ϊ������Ա
//˽�м̳У�����Ĺ����ͱ�����Ա�������б�Ϊ˽�г�Ա

//�����������ʱ�����ȵ��ø���Ĺ��캯��
//����������˳�����ȵ�������������������ٵ��ø������������
//����������Ĺ��캯��˳����ͬ
void test02()
{
	Member_LoginPage m;
	m.header();
	m.footer();
	m.member();
	Normal_LoginPage n;
	n.header();
	n.footer();
	n.normal();
}
void test03()
{
	Member_LoginPage m;
	cout << m.m_a << endl;//�Ӹ���ͬ����Ա����������ĳ�Ա�����Ḳ�Ǹ���ĳ�Ա����
	cout << m.BasePage::m_a << endl;//���ʸ���ĳ�Ա����,��Ҫ�������򣻳�Ա����ͬ��
	//������ͬ����Ա����������ĳ�Ա�����ᱻ���أ���ʹ���ع�����Ҳ�޷����ʣ��������������ܷ��ʣ�

}
//��̬��Ա��������ͨ���������������
//������ͬ����Ա�����У������������ʸ����ͬ����̬��Ա����������:
void test04()
{
	//ͨ��������ʾ�̬��Ա����
	Member_LoginPage m;
	cout << m.m_b << endl;//��������ľ�̬��Ա����
	cout << m.BasePage::m_b << endl;//���ʸ���ľ�̬��Ա����
	//ͨ���������ʾ�̬��Ա����
	cout << Member_LoginPage::m_b << endl;//��������ľ�̬��Ա����
	cout << Member_LoginPage::BasePage::m_b << endl;//���ʸ���ľ�̬��Ա����
}
//һ��������Լ̳ж�����࣬���ʸ����е�ͬ����Ա����ʱ����Ҫ�������������֣�
class father1 {};
class father2 {};
class son : public father1, public father2
{};
//���������̳е����еĸ����Ա�����������ڴ���������

//���μ̳�/��ʯ�̳�
class A
{
public:
	int m_a;
};
class A1 : virtual public A 
{};//A1�̳�A
class A2 : virtual public A 
{};//A2�̳�A
class B : public A1, public A2 
{};//B�̳�A1��A2//
//��ʱB��������m_a��������ֻ��Ҫһ��m_a;
//������̳�������������,�̳�ʱ����virtual�ؼ���,A��ʱ��Ϊ�����
//����ͨ��ָ����ʵ�ֵģ�A1,A1�д洢����m_a��ָ�룬ͨ����Ӧ��vbtable�е�ƫ������ʵ�ַ���
void test05()
{
	B b;
	b.A2::m_a = 20;
	b.A1::m_a = 30;
	cout << b.m_a << endl;//��ʱֻ��һ��m_a,������ֲ���ȷ,�����β������Ƕ�ͬһ��m_a�Ĳ���
}
int main()
{

	test02();
	test03();
	test04();
	test05();

	system("pause");
	return 0;
}
#endif 