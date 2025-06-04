#include"演讲比赛管理系统.h"
#pragma once

//构造函数
Manager::Manager()
{
	//初始化容器
	this->InitSpeech();
	//创建选手
	this->InitSpeaker();
	
	
}
//初始化容器
void Manager::InitSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_speaker.clear();
	this->m_index = 0;
}
//创建选手
void Manager::InitSpeaker()
{
	string order = "ABCDEFGHIJKL";
	
	for (int i = 0;i < order.length();i++)
	{
		//选手名字
		string name = "选手";
		name+=order[i];
		Speaker sp;
		sp.name = name;
		for (int i = 0;i < 2;i++)
		{
			sp.score[i] = 0;
		}
		//选手编号
		this->v1.push_back( 10001 + i);
		//导入选手信息 
		this->m_speaker.insert(make_pair(this->v1[i], sp));
	}
}
//析构函数
Manager::~Manager()
{
}
//菜单
void Manager::Menu()
{
	cout << "-----------------------------" << "\n"
		<< "    欢迎参加演讲比赛" << "\n"
		<< "     1,开始演讲比赛" << "\n"
		<< "     2,查看历史记录" << "\n"
		<< "     3,清空历史记录" << "\n"
		<< "     0,退出比赛系统" << "\n"
		<< "-----------------------------" << endl;
}
//开始比赛
void Manager::Speech()
{
	srand((unsigned int)time(NULL));
	if (this->m_index > 1)
	{
		cout << "比赛已结束" << endl;
		return;
	}
	//第一轮比赛开始
	system("cls");
	cout << "-----------------------------" << endl;
	this->m_index++;
	//抽签分组
	this->speechDraw(v1);
	//比赛结束评分
	this->pro_Speech(v1);
	//第二轮比赛开始
	system("cls");
	cout << "-----------------------------" << endl;
	this->m_index++;
	//抽签分组
	this->speechDraw(v2);
	//比赛结束评分
	this->pro_Speech(v2);
	//显示最终结果
	cout << "恭喜以下选手获得胜利：" << endl;
	for (vector<int>::iterator it = v3.begin();it != v3.end();it++)
	{
		cout << "编号：" << *it << "\t"
			<< "姓名：" << this->m_speaker[*it].name << "\t"
			<< "第1轮比赛分数：" << this->m_speaker[*it].score[0] << "\t"
			<< "第2轮比赛分数：" << this->m_speaker[*it].score[1] << endl;
	}
	//保存记录
	this->saveRecord();
}
//抽签
void Manager::speechDraw(vector<int>& v)
{
	cout << "-----------------------------" << endl;
	cout << "第" << this->m_index << "轮比赛选手正在抽签" << endl;
	//打乱顺序
	random_shuffle(v.begin(), v.end());
	Sleep(0);
	//显示结果
	if (this->m_index == 1)
	{
		cout << "抽签结果如下：" << endl;
		cout << "第一组:" << endl;
		int num = 0;
		for (vector<int>::iterator it = v.begin();it != v.end();it++)
		{
			cout << *it << " ";
			num++;
			if (num == v.size() / 2)
				break;
		}
		cout << endl;
		cout << "第二组:" << endl;
		for (vector<int>::iterator it = v.begin() + num;it != v.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "抽签结果如下：" << endl;
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	system("cls");
}
//比赛进程
void Manager::pro_Speech(vector<int>& v)
{
	//创建一个map用于排序评分
	multimap<double, int, greater<double>>mu_map;
	cout << "-----------------------------" << endl;
	cout << "第" << this->m_index << "轮比赛正式开始" << endl;
	Sleep(0);
	cout << "比赛结束，评委打分：" << endl;
	Sleep(0);
	//评分
	int num = 0;
	deque<double>score;
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		for (int i = 0;i < 10;i++)
		{
			double score1 = (rand() % 401 + 600) / 10.0f;
			score.push_back(score1);
		}
		//排序
		sort(score.begin(), score.end());
		//去掉最低分，去掉最高分
		score.pop_back();
		score.pop_front();
		//计算平均值
		double accu = 0;
		double score2 = 0;
		accu = accumulate(score.begin(), score.end(), 0.0f);
		score2 = accu / score.size();
		this->m_speaker[*it].score[this->m_index - 1] = score2;
		mu_map.insert(make_pair(score2, *it));//按分数排序，记录编号和成绩
		num++;
		
		if (num % 6 == 0)
		{
			if(num ==6)
				cout << "比赛结果如下：" << endl;
			cout << "第"<<num/6<<"组:" << endl;
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = mu_map.begin();
				it != mu_map.end();it++)
			{
				cout << "编号：" << it->second << "\t"
					<< "姓名：" << this->m_speaker[it->second].name << "\t"
					<< "第1轮比赛分数：" << this->m_speaker[it->second].score[0] << "\t"
					<< "第2轮比赛分数：" << this->m_speaker[it->second].score[1] << endl;
				if (count < 3)
				{
					if (this->m_index == 1)
					{
						this->v2.push_back(it->second);
					}
					else if (this->m_index == 2)
					{
						this->v3.push_back(it->second);
					}
				}
				count++;
				if (count % 6 == 0)
				{
					mu_map.clear();
					break;
				}			
			}

		}
	}
	system("pause");
	system("cls");
}
//记录比赛
void Manager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = v3.begin();it != v3.end();it++)
	{
		ofs << *it << ","
			<< this->m_speaker[*it].name << ","
			<< this->m_speaker[*it].score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已存储" << endl;
}
//查看往届记录
void  Manager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//判断是否是文件尾
	{
		cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	ifs.putback(ch);//读取回已读走的字符
	string data;
	int index = 0;
	
	while (ifs >> data)
	{
		int pos = -1;
		int start = 0;
		vector<string>v;
		while (true)
		{
			pos = data.find(',', start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			start = pos + 1;
			v.push_back(temp);
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	for (map<int, vector<string>>::iterator it = m_record.begin();it != m_record.end();it++)
	{
		cout << "第" << it->first + 1 << "届：\n"
			<< "冠军：" << it->second[0] << " " << it->second[1] << " " << it->second[2] << "\n"
			<< "亚军：" << it->second[3] << " " << it->second[4] << " " << it->second[5] << "\n"
			<< "季军：" << it->second[6] << " " << it->second[7] << " " << it->second[8] << endl;
	}
}
//清空记录
void Manager::clearRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//判断是否是文件尾
	{
		cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	ifs.close();
	cout << "请确认是否删除" << "\n"
		<< "   1,是" << "\n"
		<< "   2,否" << endl;
	int option = 0;
	cin >> option;
	if (option == 1)
	{
		
		ofstream ofs("speech.csv", ios::trunc);
		cout << "清空成功" << endl;
		ofs.close();
	}
}
//退出功能
void Manager::Exit()
{
	cout << "  退出成功" << "\n"
		<< "欢迎下次使用" << endl;
	exit(0);
}