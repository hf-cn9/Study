#include"employee.h"

Employee::Employee(int id,string name,int number)
{
	this->m_id = id;
	this->m_name = name;
	this->m_number = number;
}
void Employee::showInfo()
{
	cout << "职工编号:" << this->m_id << "\t"
		<< "职工姓名:" << this->m_name << "\t"
		<< "岗位:" << this->getDeptName() << "\t"
		<< "岗位职责:完成经理的任务" << endl;
}
string Employee::getDeptName()
{
	return string("员工");
}

Manger::Manger(int id, string name, int number)
{
	this->m_id = id;
	this->m_name = name;
	this->m_number = number;
}
void Manger::showInfo()
{
	cout << "职工编号:" << this->m_id << "\t"
		<< "职工姓名:" << this->m_name << "\t"
		<< "岗位:" << this->getDeptName() << "\t"
		<< "岗位职责:指挥员工" << endl;
}
string Manger::getDeptName()
{
	return string("经理");
}
Boss::Boss(int id, string name, int number)
{
	this->m_id = id;
	this->m_name = name;
	this->m_number = number;
}
void Boss::showInfo()
{
	cout << "职工编号:" << this->m_id << "\t"
		<< "职工姓名:" << this->m_name << "\t"
		<< "岗位:" << this->getDeptName() << "\t"
		<< "岗位职责:分析发展路线" << endl;
}
string Boss::getDeptName()
{
	return string("老板");
}