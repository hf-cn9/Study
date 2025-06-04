#include"�ݽ���������ϵͳ.h"
#pragma once

//���캯��
Manager::Manager()
{
	//��ʼ������
	this->InitSpeech();
	//����ѡ��
	this->InitSpeaker();
	
	
}
//��ʼ������
void Manager::InitSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_speaker.clear();
	this->m_index = 0;
}
//����ѡ��
void Manager::InitSpeaker()
{
	string order = "ABCDEFGHIJKL";
	
	for (int i = 0;i < order.length();i++)
	{
		//ѡ������
		string name = "ѡ��";
		name+=order[i];
		Speaker sp;
		sp.name = name;
		for (int i = 0;i < 2;i++)
		{
			sp.score[i] = 0;
		}
		//ѡ�ֱ��
		this->v1.push_back( 10001 + i);
		//����ѡ����Ϣ 
		this->m_speaker.insert(make_pair(this->v1[i], sp));
	}
}
//��������
Manager::~Manager()
{
}
//�˵�
void Manager::Menu()
{
	cout << "-----------------------------" << "\n"
		<< "    ��ӭ�μ��ݽ�����" << "\n"
		<< "     1,��ʼ�ݽ�����" << "\n"
		<< "     2,�鿴��ʷ��¼" << "\n"
		<< "     3,�����ʷ��¼" << "\n"
		<< "     0,�˳�����ϵͳ" << "\n"
		<< "-----------------------------" << endl;
}
//��ʼ����
void Manager::Speech()
{
	srand((unsigned int)time(NULL));
	if (this->m_index > 1)
	{
		cout << "�����ѽ���" << endl;
		return;
	}
	//��һ�ֱ�����ʼ
	system("cls");
	cout << "-----------------------------" << endl;
	this->m_index++;
	//��ǩ����
	this->speechDraw(v1);
	//������������
	this->pro_Speech(v1);
	//�ڶ��ֱ�����ʼ
	system("cls");
	cout << "-----------------------------" << endl;
	this->m_index++;
	//��ǩ����
	this->speechDraw(v2);
	//������������
	this->pro_Speech(v2);
	//��ʾ���ս��
	cout << "��ϲ����ѡ�ֻ��ʤ����" << endl;
	for (vector<int>::iterator it = v3.begin();it != v3.end();it++)
	{
		cout << "��ţ�" << *it << "\t"
			<< "������" << this->m_speaker[*it].name << "\t"
			<< "��1�ֱ���������" << this->m_speaker[*it].score[0] << "\t"
			<< "��2�ֱ���������" << this->m_speaker[*it].score[1] << endl;
	}
	//�����¼
	this->saveRecord();
}
//��ǩ
void Manager::speechDraw(vector<int>& v)
{
	cout << "-----------------------------" << endl;
	cout << "��" << this->m_index << "�ֱ���ѡ�����ڳ�ǩ" << endl;
	//����˳��
	random_shuffle(v.begin(), v.end());
	Sleep(0);
	//��ʾ���
	if (this->m_index == 1)
	{
		cout << "��ǩ������£�" << endl;
		cout << "��һ��:" << endl;
		int num = 0;
		for (vector<int>::iterator it = v.begin();it != v.end();it++)
		{
			cout << *it << " ";
			num++;
			if (num == v.size() / 2)
				break;
		}
		cout << endl;
		cout << "�ڶ���:" << endl;
		for (vector<int>::iterator it = v.begin() + num;it != v.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ǩ������£�" << endl;
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	system("cls");
}
//��������
void Manager::pro_Speech(vector<int>& v)
{
	//����һ��map������������
	multimap<double, int, greater<double>>mu_map;
	cout << "-----------------------------" << endl;
	cout << "��" << this->m_index << "�ֱ�����ʽ��ʼ" << endl;
	Sleep(0);
	cout << "������������ί��֣�" << endl;
	Sleep(0);
	//����
	int num = 0;
	deque<double>score;
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		for (int i = 0;i < 10;i++)
		{
			double score1 = (rand() % 401 + 600) / 10.0f;
			score.push_back(score1);
		}
		//����
		sort(score.begin(), score.end());
		//ȥ����ͷ֣�ȥ����߷�
		score.pop_back();
		score.pop_front();
		//����ƽ��ֵ
		double accu = 0;
		double score2 = 0;
		accu = accumulate(score.begin(), score.end(), 0.0f);
		score2 = accu / score.size();
		this->m_speaker[*it].score[this->m_index - 1] = score2;
		mu_map.insert(make_pair(score2, *it));//���������򣬼�¼��źͳɼ�
		num++;
		
		if (num % 6 == 0)
		{
			if(num ==6)
				cout << "����������£�" << endl;
			cout << "��"<<num/6<<"��:" << endl;
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = mu_map.begin();
				it != mu_map.end();it++)
			{
				cout << "��ţ�" << it->second << "\t"
					<< "������" << this->m_speaker[it->second].name << "\t"
					<< "��1�ֱ���������" << this->m_speaker[it->second].score[0] << "\t"
					<< "��2�ֱ���������" << this->m_speaker[it->second].score[1] << endl;
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
//��¼����
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
	cout << "��¼�Ѵ洢" << endl;
}
//�鿴�����¼
void  Manager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//�ж��Ƿ����ļ�β
	{
		cout << "�ļ�Ϊ��" << endl;
		ifs.close();
		return;
	}
	ifs.putback(ch);//��ȡ���Ѷ��ߵ��ַ�
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
		cout << "��" << it->first + 1 << "�죺\n"
			<< "�ھ���" << it->second[0] << " " << it->second[1] << " " << it->second[2] << "\n"
			<< "�Ǿ���" << it->second[3] << " " << it->second[4] << " " << it->second[5] << "\n"
			<< "������" << it->second[6] << " " << it->second[7] << " " << it->second[8] << endl;
	}
}
//��ռ�¼
void Manager::clearRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//�ж��Ƿ����ļ�β
	{
		cout << "�ļ�Ϊ��" << endl;
		ifs.close();
		return;
	}
	ifs.close();
	cout << "��ȷ���Ƿ�ɾ��" << "\n"
		<< "   1,��" << "\n"
		<< "   2,��" << endl;
	int option = 0;
	cin >> option;
	if (option == 1)
	{
		
		ofstream ofs("speech.csv", ios::trunc);
		cout << "��ճɹ�" << endl;
		ofs.close();
	}
}
//�˳�����
void Manager::Exit()
{
	cout << "  �˳��ɹ�" << "\n"
		<< "��ӭ�´�ʹ��" << endl;
	exit(0);
}