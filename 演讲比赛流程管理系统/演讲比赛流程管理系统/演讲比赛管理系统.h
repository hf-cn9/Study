#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"speaker.h"
#include<map>
#include<algorithm>
#include<windows.h>
#include<deque>
#include<numeric>
#include<fstream>

using namespace std;

class Manager
{
public:
	//���캯��
	Manager();
	//��ʼ������
	void InitSpeech();
	//����ѡ��
	void InitSpeaker();
	//��������
	~Manager();
	//�˵�����
	void Menu();
	//��ʼ����
	void Speech();
	//��ǩ
	void speechDraw(vector<int>& v);
	//��������
	void pro_Speech(vector<int>& v);
	//��¼����
	void saveRecord();
	//�鿴�����¼
	void loadRecord();
	//��ռ�¼
	void clearRecord();
	//�˳�����
	void Exit();
private:
	//��һ��ѡ�ֱ��
	vector<int>v1;
	//�ڶ���ѡ�ֱ��
	vector<int>v2;
	//ʤ��ѡ�ֱ��
	vector<int>v3;
	//��ű�ź�ѡ��
	map<int, Speaker>m_speaker;
	//��������
	int m_index;
	//�����¼
	map<int, vector<string>>m_record;
};

