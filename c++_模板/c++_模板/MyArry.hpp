#pragma once
#include<iostream>
#include<fstream>

using namespace std;

template<class T>
class MyArry
{
public:
	//构造
	MyArry(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->Address = new T[this->m_capacity];
		//cout<<"有参"<<endl;
	}
	//拷贝
	MyArry(const MyArry& c)
	{
		this->m_capacity = c.m_capacity;
		this->m_size = c.m_size;
		//深拷贝
		this->Address = new T[c.m_capacity];
		//拷贝数据
		for (int i = 0;i < this->m_size; i++)
		{
			this->Address[i] = c.Address[i];
		}
		//cout << "拷贝" << endl;
	}
	//重载 =
	MyArry& operator=(const MyArry& c)//返回引用，相当于返回其本身
	{
		if (this->Address != NULL)//清空原本数据，以待重新赋值
		{
			delete[] this->Address;
			this->Address = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = c.m_capacity;
		this->m_size = c.m_size;
		//深拷贝
		this->Address = new T[c.m_capacity];
		//拷贝数据
		for (int i = 0;i < this->m_size; i++)
		{
			this->Address[i] = c.Address[i];
		}
		return *this;
	}
	//重载[]实现下标直接访问
	T& operator[](const int& index)
	{
		return this->Address[index];
	}
	//返回数组容量;
	int get_capacity()
	{
		return this->m_capacity;
	}
	int get_size()
	{
		return this->m_size;
	}
	//尾插
	void Push_Back(const T& value)
	{
		if (this->m_capacity == this->m_size)
		{
			cout << "数组已满，无法添加" << endl;
			return;
		}
		this->Address[this->m_size] = value;
		this->m_size++;
	}
	//尾删
	void Pop_Back()
	{
		if (this->m_size == 0)
		{
			cout << "数组已空，无法删除" << endl;
			return;
		}
		this->m_size--;
	}
	//析构
	~MyArry()
	{
		if (Address != NULL)
		{
			delete[] this->Address;
			this->Address = NULL;
			
		}
		//cout << "析构" << endl;
	}
private:
	T* Address;//地址
	int m_capacity;//容量，开辟的空间
	int m_size;//大小，当前的大小
};
class Person
{
public:
	string name;
	int age;

};
//cout重载
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