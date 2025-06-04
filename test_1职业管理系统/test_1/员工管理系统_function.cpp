#include "workerManager.h"

workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILELAME, ios::in);
	if(!ifs.is_open())
	{
		this->m_file = true;
		this->work_number = 0;
		this->m_Array = NULL;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;//��ȡ���ļ��Ľ�β��
	if (ifs.eof())
	{
		this->m_file = true;
		this->work_number = 0;
		this->m_Array = NULL;
		ifs.close();
		return;
	}
	this->work_number = this->get_Filenum();//��ȡ��Ҫ���ٵĿռ��С
	this->m_Array = new Worker* [this->work_number];//���ٿռ�
	this->init_File();
}
workerManager::~workerManager()
{
	if (this->m_Array != NULL)
	{
		for (int i = 0;i < this->work_number;i++)
		{
			if (this->m_Array[i] = NULL)
				delete this->m_Array[i];
		}
		delete[] this->m_Array;
		this->m_Array = NULL;
	}
}
void workerManager::showMenu()
{
	cout << "------------------------------" << "\n"
		<< "-----��ӭʹ��Ա������ϵͳ-----" << "\n"
		<< "\t" << "0���˳�����ϵͳ" << "\n"
		<< "\t" << "1������Ա����Ϣ" << "\n"
		<< "\t" << "2��ɾ��Ա����Ϣ" << "\n"
		<< "\t" << "3���޸�Ա����Ϣ" << "\n"
		<< "\t" << "4������Ա����Ϣ" << "\n"
		<< "\t" << "5����ʾԱ����Ϣ" << "\n"
		<< "\t" << "6�����ձ������" << "\n"
		<< "\t" << "7�����������Ϣ" << "\n"
		<< "------------------------------" << endl;
}
void workerManager::exitMenu()
{
	system("cls");
	cout << "--�˳��ɹ�--" << "\n"
		 << "��ӭ�ٴ�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workerManager::addStaff()
{
	cout << "����������Ա��������" << endl;
	int add_number = 0;//�����û���������
	cin >> add_number;
	if (add_number > 0)
	{
		//��ӣ�
		
		//��������ӵĴ�С��
		int new_size = this->work_number + add_number;
		//�����¿ռ�:
		Worker** newspace = new Worker * [new_size];
		//��ԭ���ռ����ݿ������¿ռ�:
		if (this->m_Array != NULL)
		{
			for (int i = 0;i < (this->work_number);i++)
			{
				newspace[i] = this->m_Array[i];
			}
		}
		for (int i = 0; i < add_number;i++)
		{
			int a = 0;
			string b = "";
			int c = 0;
			while(1)
			{
				cout << "�������¼���ĵ�" << i + 1 << "��Ա���ı��" << endl;
				cin >> a;
				if (src_1Staff(a) != -1)
				{
					cout << "�Ѵ��ڸ�Ա�����" << endl;
					continue;
				}
				break;

			}
			
			cout << "�������¼���ĵ�" << i + 1 << "��Ա��������" << endl;
			cin >> b;
			cout << "�������¼���ĵ�" << i + 1 << "��Ա���ĸ�λ���" << "\n"
				<< "\t" << "1,Ա��" << "\n"
				<< "\t" << "2,����" << "\n"
				<< "\t" << "3,�ϰ�" << endl;
			cin >> c;
			Worker* worker = NULL;
			switch (c)
			{
			case 1:
				worker = new Employee(a, b, c);
				break;
			case 2:
				worker = new Manger(a, b, c);
				break;
			case 3:
				worker = new Boss(a, b, c);
				break;
			default:
				cout << "��������" << endl;
				break;
			}
			newspace[i + this->work_number] = worker;
			system("cls");
			this->showMenu();
		}
		delete[]this->m_Array;
		this->m_Array = newspace;
		this->work_number = new_size;
		cout << "�ɹ������" << add_number << "��ְ��" << endl;
		this->m_file = false;//��ʱ���ݺ��ļ���Ϊ��
		//���浽�ļ���
		this->saveFile();

	}
	else
	{
		cout << "��������"<< endl;
	}
	system("pause");
	system("cls");
}
void workerManager::saveFile()
{
	ofstream ofs;
	ofs.open(FILELAME,ios::out);
	for (int i = 0; i < this->work_number;i++)
	{
		ofs <<this->m_Array[i]->m_id << "\t"
			<<this->m_Array[i]->m_name << "\t"
			<<this->m_Array[i]->m_number<< endl;
	}
	ofs.close();
}
int workerManager::get_Filenum()
{
	ifstream ifs;
	ifs.open(FILELAME, ios::in);
	int id;
	string name;
	int location;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> location)
	{
		num++;
	}
	return num;
	ifs.close();
}
void workerManager::init_File()
{
	ifstream ifs;
	ifs.open(FILELAME, ios::in);
	int id;
	string name;
	int location;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> location)
	{
		Worker* worker = NULL;
		switch (location)
		{
		case 1:
			worker = new Employee(id, name, location);
			break;
		case 2:
			worker = new Manger(id, name, location);
			break;
		case 3:
			worker = new Boss(id, name, location);
			break;
		}
		this->m_Array[index] = worker;
		index++;
	}
	this->m_file = false;
	ifs.close();

}
void workerManager::del_Staff()
{
	if (this->m_file)
	{
		cout << "�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	int option = 0;
	cout << "ѡ��ɾ���ķ�ʽ��" << "\n"
		 << "1,ͨ��Ա�����" << "\n"
		 << "2,ͨ��Ա������" << endl;
	cin >> option;
	if(option == 1)
	{
		cout << "����Ҫɾ����Ա�����:" << endl;
		int option1 = 0;
		cin >> option1;
		int number = src_1Staff(option1);
		if (number == -1)
		{
			cout << "δ�ҵ���Ա��" << endl;
		}
		else
		{
			cout << "�Ƿ�Ҫɾ����Ա����1����  2����" << endl;
			this->m_Array[number]->showInfo();
			int option2 = 0;
			cin >> option2;
			if (option2 == 1)
			{
				for (int i = number;i < this->work_number - 1;i++)
				{
					this->m_Array[i] = this->m_Array[i + 1];
				}
				this->work_number--;
				this->saveFile();
				cout << "ɾ���ɹ�" << endl;
			}
			else if (option2 == 2)
			{
				cout << "ȡ��ɾ��" << endl;
			}
			else
			{
				cout << "�������" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	else if (option == 2)
	{
		cout << "����Ҫɾ����Ա������:" << endl;
		string option1 = "";
		cin >> option1;
		vector<int>a = this->src_2Staff(option1);
		if (a.empty())
		{
			cout << "δ�ҵ���Ա��" << endl;
		}
		else
		{
			int b = 0;
			cout << "������Ҫɾ��Ա���ı�ţ�" << endl;
			for (int i = 0;i < a.size(); i++)
			{
				this->m_Array[a.at(i)]->showInfo();
			}
			cin >> b;
			int c = src_1Staff(b);
			if (c == -1)
			{
				cout << "��Ŵ���" << endl;
				system("pause");
				system("cls");
				return;
			}
			cout << "�Ƿ�Ҫɾ����Ա����1����  2����" << endl;
			this->m_Array[c]->showInfo();
			int option2 = 0;
			cin >> option2;
			if (option2 == 1)
			{
				for (int i = c;i < this->work_number - 1;i++)
				{
					this->m_Array[i] = this->m_Array[i + 1];
				}
				this->work_number--;
				this->saveFile();
				cout << "ɾ���ɹ�" << endl;
			}
			else if (option2 == 2)
			{
				cout << "ȡ��ɾ��" << endl;
			}
			else
			{
				cout << "�������" << endl;
			}
		}
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}
int workerManager::src_1Staff(int a)
{
	for (int i = 0;i < this->work_number;i++)
	{
		if (a == this->m_Array[i]->m_id)
		{
			return i;
		}
	}
	return -1;
}
vector<int> workerManager::src_2Staff(string name)
{
	vector<int> indices;
	for (int i = 0;i < this->work_number;i++)
	{
		if (name == this->m_Array[i]->m_name)
		{
			indices.push_back(i);
		}
	}
	return indices;
}
void workerManager::rev_Staff()
{
	if (this->m_file)
	{
		cout << "�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	int option = 0;
	cout << "ѡ����ҵķ�ʽ��" << "\n"
		<< "1,ͨ��Ա�����" << "\n"
		<< "2,ͨ��Ա������" << endl;
	cin >> option;
	if (option == 1)
	{
		cout << "����Ҫ�޸ĵ�Ա�����:" << endl;
		int option1 = 0;
		cin >> option1;
		int number = src_1Staff(option1);
		if (number == -1)
		{
			cout << "δ�ҵ���Ա��" << endl;
		}
		else
		{
			cout << "�Ƿ�Ҫ�޸ĸ�Ա����1����  2����" << endl;
			this->m_Array[number]->showInfo();
			int option2 = 0;
			cin >> option2;
			if (option2 == 1)
			{
				while (1)
				{
					int a = 0;
					cout << "�������Ա�����±��" << endl;
					cin >> a;
					if (this->src_1Staff(a) != -1 && a != option1)
					{
						cout << "�Ѵ��ڸ�Ա�����" << endl;
						continue;
					}
					this->m_Array[number]->m_id = a;
					break;

				}
				cout << "�����Ա����������" << endl;
				cin >> this->m_Array[number]->m_name;
				cout << "�����Ա�����¸�λ���" << "\n"
					<< "\t" << "1,Ա��" << "\n"
					<< "\t" << "2,����" << "\n"
					<< "\t" << "3,�ϰ�" << endl;
				cin >> this->m_Array[number]->m_number;
				switch (this->m_Array[number]->m_number)
				{
				case 1:
					this->m_Array[number] = new Employee(this->m_Array[number]->m_id, this->m_Array[number]->m_name, this->m_Array[number]->m_number);
					break;
				case 2:
					this->m_Array[number] = new Manger(this->m_Array[number]->m_id, this->m_Array[number]->m_name, this->m_Array[number]->m_number);
					break;
				case 3:
					this->m_Array[number] = new Boss(this->m_Array[number]->m_id, this->m_Array[number]->m_name, this->m_Array[number]->m_number);
					break;
				default:
					cout << "��������" << endl;
					break;
				}
				this->saveFile();
				cout << "�޸ĳɹ�" << endl;
			}
			else if (option2 == 2)
			{
				cout << "ȡ���޸�" << endl;
			}
			else
			{
				cout << "�������" << endl;
			}
		}
	}
	else if (option == 2)
	{
		cout << "����Ҫ�޸ĵ�Ա������:" << endl;
		string option1 = "";
		cin >> option1;
		vector<int>a = this->src_2Staff(option1);
		if (a.empty())
		{
			cout << "δ�ҵ���Ա��" << endl;
		}
		else
		{
			int b = 0;
			cout << "������Ҫ�޸�Ա���ı�ţ�" << endl;
			for (int i = 0;i < a.size(); i++)
			{
				this->m_Array[a.at(i)]->showInfo();
			}
			cin >> b;
			int c = src_1Staff(b);
			if (c == -1)
			{
				cout << "��Ŵ���" << endl;
				system("pause");
				system("cls");
				return;
			}
			cout << "�Ƿ�Ҫ�޸ĸ�Ա����1����  2����" << endl;
			this->m_Array[c]->showInfo();
			int option2 = 0;
			cin >> option2;
			if (option2 == 1)
			{
				while (1)
				{
					int a = 0;
					cout << "�������Ա�����±��" << endl;
					cin >> a;
					if (src_1Staff(a) != -1 && a != b)
					{
						cout << "�Ѵ��ڸ�Ա�����" << endl;
						continue;
					}
					this->m_Array[c]->m_id = a;
					break;

				}
				cout << "�����Ա����������" << endl;
				cin >> this->m_Array[c]->m_name;
				cout << "�����Ա�����¸�λ���" << "\n"
					<< "\t" << "1,Ա��" << "\n"
					<< "\t" << "2,����" << "\n"
					<< "\t" << "3,�ϰ�" << endl;
				cin >> this->m_Array[c]->m_number;
				switch (this->m_Array[c]->m_number)
				{
				case 1:
					this->m_Array[c] = new Employee(this->m_Array[c]->m_id, this->m_Array[c]->m_name, this->m_Array[c]->m_number);
					break;
				case 2:
					this->m_Array[c] = new Manger(this->m_Array[c]->m_id, this->m_Array[c]->m_name, this->m_Array[c]->m_number);
					break;
				case 3:
					this->m_Array[c] = new Boss(this->m_Array[c]->m_id, this->m_Array[c]->m_name, this->m_Array[c]->m_number);
					break;
				default:
					cout << "��������" << endl;
					break;
				}
				this->saveFile();
				cout << "�޸ĳɹ�" << endl;
			}
			else if (option2 == 2)
			{
				cout << "ȡ���޸�" << endl;
			}
			else
			{
				cout << "�������" << endl;
			}
		}
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}
void workerManager::scr_Staff()
{
	if (this->m_file)
	{
		cout << "�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	int option = 0;
	cout << "ѡ����ҵķ�ʽ��" << "\n"
		<< "1,ͨ��Ա�����" << "\n"
		<< "2,ͨ��Ա������" << endl;
	cin >> option;
	if (option == 1)
	{
		cout << "����Ҫ���ҵ�Ա�����:" << endl;
		int option1 = 0;
		cin >> option1;
		int number = src_1Staff(option1);
		if (number == -1)
		{
			cout << "δ�ҵ���Ա��" << endl;
		}
		else
		{
			cout << "���ҳɹ���" << endl;
			this->m_Array[number]->showInfo();
		}
	}
	else if (option == 2)
	{
		cout << "����Ҫ���ҵ�Ա������:" << endl;
		string option1 = "";
		cin >> option1;
		vector<int> number = src_2Staff(option1);
		if (number.empty())
		{
			cout << "δ�ҵ���Ա��" << endl;
		}
		else
		{
			for (int i = 0;i < number.size();i++)
			{
				cout << "���ҳɹ���" << endl;
				this->m_Array[number.at(i)]->showInfo();
			}
		}
	}
	else
		{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}
void workerManager::showInfo()
{
	if (m_file)
	{
		cout << "�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	for (int i = 0;i < this->work_number;i++)
	{
		this->m_Array[i]->showInfo();
	}
	system("pause");
	system("cls");
}
void workerManager::sort_Staff()
{
	if (m_file)
	{
		cout << "�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ѡ������ʽ" << "\n"
		<< "1,�����������" << "\n"
		<< "2,��Ž�������" << endl;
	int option1 = 0;
	cin >> option1;
	if (option1 == 1)
	{
		int minValue = 0;
		int index = 0;
		for (int i = 0;i < this->work_number - 1;i++)
		{
			minValue = this->m_Array[i]->m_id;
			index = i;
			for (int j = i+1;j < this->work_number;j++)
			{
				if (minValue > this->m_Array[j]->m_id)
				{
					minValue = this->m_Array[j]->m_id;
					index = j;
				}
			}
			if (index != i)
			{
				Worker* temp = this->m_Array[i];
				this->m_Array[i] = this->m_Array[index];
				this->m_Array[index] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->saveFile();
		this->showInfo();
	}
	else if (option1 == 2)
	{
		int maxValue = 0;
		int index = 0;
		for (int i = 0;i < this->work_number - 1;i++)
		{
			maxValue = this->m_Array[i]->m_id;
			index = i;
			for (int j = i;j < this->work_number;j++)
			{
				if (maxValue < this->m_Array[j]->m_id)
				{
					maxValue = this->m_Array[j]->m_id;
					index = j;
				}
			}
			Worker* temp = this->m_Array[i];
			this->m_Array[i] = this->m_Array[index];
			this->m_Array[index] = temp;
		}
		cout << "����ɹ�" << endl;
		this->saveFile();
		this->showInfo();
	}
	else
	{
		cout << "�������" << endl;
		system("pause");
		system("cls");
	}
	
}
void workerManager::cle_Staff()
{
	if (m_file)
	{
		cout << "�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ȷ���Ƿ�ɾ��" << "\n"
		<< "    1,��" << "\n"
		<< "    2,��" << endl;
	int option1 = 0;
	cin >> option1;
	if (option1 == 1)
	{
		ofstream ofs;
		ofs.open(FILELAME, ios::trunc);
		ofs.close();
		if (this->m_Array != NULL)
		{
			for (int i = 0;i < this->work_number;i++)
			{
				if (this->m_Array[i] = NULL)
					delete this->m_Array[i];
			}
			delete[] this->m_Array;
			this->m_file = true;
			this->work_number = 0;
			this->m_Array = NULL;
		}
		cout << "����ɹ�" << endl;
	}
	else if (option1 == 2)
	{
		cout << "ȡ���ɹ�" << endl;
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}