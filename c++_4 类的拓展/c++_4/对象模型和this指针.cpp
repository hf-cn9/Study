#include<iostream>
#if 0
using namespace std;

//��Ա�����ͳ�Ա�����ֿ��洢
class A
{
public:
	static int a; //��̬��Ա����,�����ڶ���,�����౾��,��ռ�ö�����ڴ�ռ�
	int b;
	void func() 
	{
		cout << "A" << endl;
	}//��Ա������ռ�ö����ڴ�
};

//thisָ��
//1,������Ƴ�ͻ

//2,���ض�����
class B
{
public:
	int a;
	//������Ƴ�ͻ
	B(int a)
	{
		this->a = a; 
	}
	//���ض�����
	//����������ã����ص���һ�����ÿ������캯������ʱ����
	//ʹ�����õĺ��������ص���ԭ�����һ������������ֱ�Ӳ���ԭ����
	B& Add_person(B& p)
	{
		this->a += p.a; 
		return *this;
	}
	void func()
	{
		if (this == NULL)
		{
			return;//��ֹ��ָ����ò�����Ա�����ĳ�Ա����
		}
		cout << "B" << endl;
	}
};

//��ָ��ֱ�ӵ��ó�Ա����
void test01()
{
	B* p = NULL;
	B p1(10);
	p->func(); //��ָ����ó�Ա����,���ǵ��ò�����Ա�����ĺ����ᱨ��
	//p->Add_person(p1); //��ָ����ó�Ա����������

}

class C
{
public:
	int m_a;
	mutable int m_b;//�ɱ��Ա����:����const���εĳ�Ա�������޸�
	void Add_C(int i) const//const���εĳ�Ա������
						   //�����޸Ķ���ĳ�Ա�������ȼ��� const C* const this
	{
		//this������һ��ָ�볣����ָ��Ķ��󲻿��޸ļ��ȼ��� C* const this
		//m_a = 100�ᱨ���ȼ���this->m_a = 100;
		m_b = 100;

	}
	void func() {}
};
void test()
{
	const C c;//������
	//c.m_a = 10;//��ͨ��Ա���������޸�
	c.m_b = 20;//�ɱ��Ա���������޸�
	c.Add_C(10);//���Ե���const���εĳ�Ա����
	//c.func();//�����Ե�����ͨ��Ա����
}
int main()
{	
	//�ն�������һ���ֽڵ��ڴ棬Ϊ�����ֿն���ռ�ڴ��λ��
	cout << "sizeof(A) = " << sizeof(A) << endl;
	//this��ָ������ָ��
	B p1(10);
	cout << "p1.a = " << p1.a << endl;
	B p2(20);
	p1.Add_person(p2).Add_person(p2).Add_person(p2);//ͨ��*thisָ�뷵�ض�����
	cout << "p1.a = " << p1.a << endl;
	system("pause");
	return 0;
}
#endif