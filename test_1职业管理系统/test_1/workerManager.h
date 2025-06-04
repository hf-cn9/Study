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
	//��¼Ա������
	int work_number;
	//Ա������ָ��
	Worker** m_Array;
	//��¼�ļ��Ƿ�Ϊ�գ�
	bool m_file;
public:
	workerManager();
	//��ʾ�˵���
	void showMenu();
	//�˳����ܣ�
	void exitMenu();
	//������Ϣ
	void addStaff();
	//�����ļ�
	void saveFile();
	//ͳ��Ա������
	int get_Filenum();
	//��ʼ���ļ�����
	void init_File();
	//ɾ��Ա��
	void del_Staff();
	//����Ա��
	int src_1Staff(int);
	vector<int> src_2Staff(string);
	void scr_Staff();
	//�޸�Ա��
	void rev_Staff();
	//��ʾԱ��
	void showInfo();
	//�������
	void sort_Staff();
	//����ļ�
	void cle_Staff();


	~workerManager(); 

};
