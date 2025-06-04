#pragma once
#include<iostream>
#include<string>

using namespace std;

class Worker
{
public:
	//编号
	int m_id;
	//姓名
	string m_name;
	//部门编号
	int m_number;
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

};