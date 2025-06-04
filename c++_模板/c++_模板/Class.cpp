#include"Class.h"

template<class T1,class T2>
Person<T1, T2>::Person(T1 id, T2 name)
{
	this->m_id = id;
	this->m_name = name;
}
template<class T1,class T2>
void Person<T1, T2>::showInfo()
{
	cout << this->m_id << "\n"
		<< this->m_name << endl;
}