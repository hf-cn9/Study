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
	//构造函数
	Manager();
	//初始化容器
	void InitSpeech();
	//创建选手
	void InitSpeaker();
	//析构函数
	~Manager();
	//菜单界面
	void Menu();
	//开始比赛
	void Speech();
	//抽签
	void speechDraw(vector<int>& v);
	//比赛进程
	void pro_Speech(vector<int>& v);
	//记录比赛
	void saveRecord();
	//查看往届记录
	void loadRecord();
	//清空记录
	void clearRecord();
	//退出功能
	void Exit();
private:
	//第一轮选手编号
	vector<int>v1;
	//第二轮选手编号
	vector<int>v2;
	//胜者选手编号
	vector<int>v3;
	//存放编号和选手
	map<int, Speaker>m_speaker;
	//比赛轮数
	int m_index;
	//往届记录
	map<int, vector<string>>m_record;
};

