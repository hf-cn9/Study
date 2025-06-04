#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "worker.h"
#include"employee.h"
#define FILELAME "manager.txt"

using namespace std;

class workerManager
{
public:
	//记录员工人数
	int work_number;
	//员工数组指针
	Worker** m_Array;
	//记录文件是否为空；
	bool m_file;
public:
	workerManager();
	//显示菜单：
	void showMenu();
	//退出功能：
	void exitMenu();
	//增加信息
	void addStaff();
	//保存文件
	void saveFile();
	//统计员工人数
	int get_Filenum();
	//初始化文件内容
	void init_File();
	//删除员工
	void del_Staff();
	//查找员工
	int src_1Staff(int);
	vector<int> src_2Staff(string);
	void scr_Staff();
	//修改员工
	void rev_Staff();
	//显示员工
	void showInfo();
	//按编号排
	void sort_Staff();
	//清空文件
	void cle_Staff();


	~workerManager(); 

};
