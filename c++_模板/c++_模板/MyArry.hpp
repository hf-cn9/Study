#pragma once
#include<iostream>
#include<fstream>

using namespace std;

template<class T>
class MyArry
{
public:
	//����
	MyArry(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->Address = new T[this->m_capacity];
		//cout<<"�в�"<<endl;
	}
	//����
	MyArry(const MyArry& c)
	{
		this->m_capacity = c.m_capacity;
		this->m_size = c.m_size;
		//���
		this->Address = new T[c.m_capacity];
		//��������
		for (int i = 0;i < this->m_size; i++)
		{
			this->Address[i] = c.Address[i];
		}
		//cout << "����" << endl;
	}
	//���� =
	MyArry& operator=(const MyArry& c)//�������ã��൱�ڷ����䱾��
	{
		if (this->Address != NULL)//���ԭ�����ݣ��Դ����¸�ֵ
		{
			delete[] this->Address;
			this->Address = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = c.m_capacity;
		this->m_size = c.m_size;
		//���
		this->Address = new T[c.m_capacity];
		//��������
		for (int i = 0;i < this->m_size; i++)
		{
			this->Address[i] = c.Address[i];
		}
		return *this;
	}
	//����[]ʵ���±�ֱ�ӷ���
	T& operator[](const int& index)
	{
		return this->Address[index];
	}
	//������������;
	int get_capacity()
	{
		return this->m_capacity;
	}
	int get_size()
	{
		return this->m_size;
	}
	//β��
	void Push_Back(const T& value)
	{
		if (this->m_capacity == this->m_size)
		{
			cout << "�����������޷����" << endl;
			return;
		}
		this->Address[this->m_size] = value;
		this->m_size++;
	}
	//βɾ
	void Pop_Back()
	{
		if (this->m_size == 0)
		{
			cout << "�����ѿգ��޷�ɾ��" << endl;
			return;
		}
		this->m_size--;
	}
	//����
	~MyArry()
	{
		if (Address != NULL)
		{
			delete[] this->Address;
			this->Address = NULL;
			
		}
		//cout << "����" << endl;
	}
private:
	T* Address;//��ַ
	int m_capacity;//���������ٵĿռ�
	int m_size;//��С����ǰ�Ĵ�С
};
class Person
{
public:
	string name;
	int age;

};
//cout����
ostream& operator<<(ostream& cout, const Person& m)
{
	cout << m.name << "\t" << m.age << endl;
	return cout;
}
template<class T>
void printMyArray(MyArry<T>& c)
{
	for (int i = 0; i < c.get_size();i++)
	{
		cout << c[i] << endl;;
	}
}