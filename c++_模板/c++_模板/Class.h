#pragma once
#include<iostream>
#include<string>

using namespace std;

template<class T1,class T2>
class Person
{
public:
	T1 m_id;
	T2 m_name;
	Person(T1 id, T2 name);
	void showInfo();
};
