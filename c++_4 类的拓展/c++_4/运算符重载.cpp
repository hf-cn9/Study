#include<iostream>
#if 0 
using namespace std;

class Math
{
	friend ostream& operator<<(ostream& cout, const Math& m); //��Ԫ��������
public:
	int m_a;
	int m_b;
	Math() {} //Ĭ�Ϲ��캯��
	
	
	Math operator+(const Math& m) //��Ա��������+�����
	{
		Math temp;
		temp.m_a = this->m_a + m.m_a; 
		temp.m_b = this->m_b + m.m_b;
		return temp; //����һ���µĶ���
		
	}
	//������������أ�ͨ�����ó�Ա����ʵ��

	//��Ա��������ǰ��++�����
	Math& operator++()
	{
		m_a++;
		m_b++;
		return *this; //���ص�ǰ����
	}
	//��Ա�������غ���++�����
	Math operator++(int)//int��Ϊռλ������ʵ�ֺ������أ�����ǰ�úͺ���++�����
	{
		Math temp = *this; //���浱ǰ����
		m_a++;
		m_b++;
		return temp; //���ص�ǰ���󣬾ֲ�����Ӧ�÷�����������
	}
	//��Ա�������ع�ϵ�����
	bool operator==(const Math& m)
	{
		if (this->m_a == m.m_a && this->m_b == m.m_b)
			return true;
		else
			return false;
	}
	bool operator!=(const Math& m)
	{
		if (this->m_a == m.m_a && this->m_b == m.m_b)
			return false;
		else
			return true;
	}
};
class Math2
{
public:
	int* m_c;
	Math2(int c)
	{
		m_c = new int(c);
	}
	~Math2() //��������
	{
		if (m_c != NULL)
		{
			delete m_c; //�ͷ��ڴ�
			m_c = NULL;
		}
	}
	//��Ա��������ǰ��=�����
	//���������,����һ���࣬���Զ�����һ��Ĭ�ϵĸ�ֵ�����������p2 = p1;
	//������ʵ���������ǳ�����ģ�����г�Ա�����ڶ��������ܻ��������
	Math2& operator=(const Math2& m)
	{
		if (m_c != NULL)
		{
			delete m_c; //�ͷ��ڴ�
			m_c = NULL;
		}
		m_c = new int(*m.m_c); //���
		return *this;//Ϊ��ʵ�����ȵĲ��������ض�����
	}
};
class MyPrint
{
public:
	//���غ������������(�º���)
	void operator()(string m)
	{
		cout << m << endl;
	}
};
Math operator+(const Math& m1, const int m2) //ȫ�ֺ�������+�����
{
	Math temp;
	temp.m_a = m1.m_a + m2;
	temp.m_b = m1.m_b + m2;
	return temp; //����һ���µĶ���
}
ostream& operator<<(ostream &cout, const Math& m) //ȫ�ֺ�������<<�����
											 // cout�����������,ȫ�ֽ�����һ��,�������ڲ��Ѿ��������
{
	cout << "m_a = " << m.m_a << endl;
	cout << "m_b = " << m.m_b << endl;
	return cout; //�������������
}

int main()
{
	Math A;
	A.m_a = 10;
	A.m_b = 20;
	Math B;
	B.m_a = 30;
	B.m_b = 40;
	Math C = A + B; //���������Զ�����operator+����,���ȵ��ó�Ա����,û�������ȫ�ֺ���
	cout << "A.m_a + B.m_a = " << C.m_a << endl;
	cout << "A.m_b + B.m_b = " << C.m_b << endl;
	Math D = A + 100; //���������Զ�����operator+����,���ݲ�������ȫ�ֺ�����
	cout << "A.m_a + 100 = " << D.m_a << endl;
	cout << "A.m_b + 100 = " << D.m_b << endl;
	cout << A << endl;//��������<<������������A
	cout << ++A << endl;
	cout << A++ << endl;
	cout << A << endl;
	Math2 p1(10);
	Math2 p2(20);
	Math2 p3(30);
	p1 = p2 = p3; //��������=�����
	cout << "p1.m_c = " << *p1.m_c << endl;
	cout << "p2.m_c = " << *p2.m_c << endl;
	cout << "p3.m_c = " << *p3.m_c << endl;
	if (A == B)
	{
		cout << "A == B" << endl;
	}
	else if(A != B)
	{
		cout << "A != B" << endl;
	}
	MyPrint x;
	x("Hello World");
	MyPrint()("Hello World"); //��������������غ���
	system("pause");
	return 0;
}
#endif