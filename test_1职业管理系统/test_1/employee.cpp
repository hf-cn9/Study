#include"employee.h"

Employee::Employee(int id,string name,int number)
{
	this->m_id = id;
	this->m_name = name;
	this->m_number = number;
}
void Employee::showInfo()
{
	cout << "ְ�����:" << this->m_id << "\t"
		<< "ְ������:" << this->m_name << "\t"
		<< "��λ:" << this->getDeptName() << "\t"
		<< "��λְ��:��ɾ��������" << endl;
}
string Employee::getDeptName()
{
	return string("Ա��");
}

Manger::Manger(int id, string name, int number)
{
	this->m_id = id;
	this->m_name = name;
	this->m_number = number;
}
void Manger::showInfo()
{
	cout << "ְ�����:" << this->m_id << "\t"
		<< "ְ������:" << this->m_name << "\t"
		<< "��λ:" << this->getDeptName() << "\t"
		<< "��λְ��:ָ��Ա��" << endl;
}
string Manger::getDeptName()
{
	return string("����");
}
Boss::Boss(int id, string name, int number)
{
	this->m_id = id;
	this->m_name = name;
	this->m_number = number;
}
void Boss::showInfo()
{
	cout << "ְ�����:" << this->m_id << "\t"
		<< "ְ������:" << this->m_name << "\t"
		<< "��λ:" << this->getDeptName() << "\t"
		<< "��λְ��:������չ·��" << endl;
}
string Boss::getDeptName()
{
	return string("�ϰ�");
}