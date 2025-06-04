#pragma once
#include"worker.h"

class Employee : public Worker
{
public:
	//构造函数
	Employee(int id, string name,int number);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
class Manger : public Worker
{
public:
	//构造函数
	Manger(int id, string name, int number);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
class Boss : public Worker
{
public:
	//构造函数
	Boss(int id, string name, int);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};