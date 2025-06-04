#pragma once
#include"worker.h"

class Employee : public Worker
{
public:
	//���캯��
	Employee(int id, string name,int number);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
class Manger : public Worker
{
public:
	//���캯��
	Manger(int id, string name, int number);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
class Boss : public Worker
{
public:
	//���캯��
	Boss(int id, string name, int);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};