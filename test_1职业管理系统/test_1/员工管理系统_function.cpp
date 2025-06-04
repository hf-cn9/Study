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
	ifs >> ch;//读取掉文件的结尾标
	if (ifs.eof())
	{
		this->m_file = true;
		this->work_number = 0;
		this->m_Array = NULL;
		ifs.close();
		return;
	}
	this->work_number = this->get_Filenum();//获取需要开辟的空间大小
	this->m_Array = new Worker* [this->work_number];//开辟空间
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
		<< "-----欢迎使用员工管理系统-----" << "\n"
		<< "\t" << "0，退出管理系统" << "\n"
		<< "\t" << "1，增加员工信息" << "\n"
		<< "\t" << "2，删除员工信息" << "\n"
		<< "\t" << "3，修改员工信息" << "\n"
		<< "\t" << "4，查找员工信息" << "\n"
		<< "\t" << "5，显示员工信息" << "\n"
		<< "\t" << "6，按照编号排序" << "\n"
		<< "\t" << "7，清空所有信息" << "\n"
		<< "------------------------------" << endl;
}
void workerManager::exitMenu()
{
	system("cls");
	cout << "--退出成功--" << "\n"
		 << "欢迎再次使用" << endl;
	system("pause");
	exit(0);
}
void workerManager::addStaff()
{
	cout << "请输入增加员工数量：" << endl;
	int add_number = 0;//保存用户输入数量
	cin >> add_number;
	if (add_number > 0)
	{
		//添加：
		
		//计算新添加的大小：
		int new_size = this->work_number + add_number;
		//开辟新空间:
		Worker** newspace = new Worker * [new_size];
		//将原来空间数据拷贝到新空间:
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
				cout << "请输入新加入的第" << i + 1 << "个员工的编号" << endl;
				cin >> a;
				if (src_1Staff(a) != -1)
				{
					cout << "已存在该员工编号" << endl;
					continue;
				}
				break;

			}
			
			cout << "请输入新加入的第" << i + 1 << "个员工的姓名" << endl;
			cin >> b;
			cout << "请输入新加入的第" << i + 1 << "个员工的岗位编号" << "\n"
				<< "\t" << "1,员工" << "\n"
				<< "\t" << "2,经理" << "\n"
				<< "\t" << "3,老板" << endl;
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
				cout << "输入有误" << endl;
				break;
			}
			newspace[i + this->work_number] = worker;
			system("cls");
			this->showMenu();
		}
		delete[]this->m_Array;
		this->m_Array = newspace;
		this->work_number = new_size;
		cout << "成功添加了" << add_number << "名职工" << endl;
		this->m_file = false;//此时内容和文件不为空
		//保存到文件中
		this->saveFile();

	}
	else
	{
		cout << "数量有误"<< endl;
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
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	int option = 0;
	cout << "选择删除的方式：" << "\n"
		 << "1,通过员工编号" << "\n"
		 << "2,通过员工姓名" << endl;
	cin >> option;
	if(option == 1)
	{
		cout << "输入要删除的员工编号:" << endl;
		int option1 = 0;
		cin >> option1;
		int number = src_1Staff(option1);
		if (number == -1)
		{
			cout << "未找到该员工" << endl;
		}
		else
		{
			cout << "是否要删除该员工：1，是  2，否" << endl;
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
				cout << "删除成功" << endl;
			}
			else if (option2 == 2)
			{
				cout << "取消删除" << endl;
			}
			else
			{
				cout << "输入错误" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	else if (option == 2)
	{
		cout << "输入要删除的员工姓名:" << endl;
		string option1 = "";
		cin >> option1;
		vector<int>a = this->src_2Staff(option1);
		if (a.empty())
		{
			cout << "未找到该员工" << endl;
		}
		else
		{
			int b = 0;
			cout << "请输入要删除员工的编号：" << endl;
			for (int i = 0;i < a.size(); i++)
			{
				this->m_Array[a.at(i)]->showInfo();
			}
			cin >> b;
			int c = src_1Staff(b);
			if (c == -1)
			{
				cout << "编号错误" << endl;
				system("pause");
				system("cls");
				return;
			}
			cout << "是否要删除该员工：1，是  2，否" << endl;
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
				cout << "删除成功" << endl;
			}
			else if (option2 == 2)
			{
				cout << "取消删除" << endl;
			}
			else
			{
				cout << "输入错误" << endl;
			}
		}
	}
	else
	{
		cout << "输入错误" << endl;
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
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	int option = 0;
	cout << "选择查找的方式：" << "\n"
		<< "1,通过员工编号" << "\n"
		<< "2,通过员工姓名" << endl;
	cin >> option;
	if (option == 1)
	{
		cout << "输入要修改的员工编号:" << endl;
		int option1 = 0;
		cin >> option1;
		int number = src_1Staff(option1);
		if (number == -1)
		{
			cout << "未找到该员工" << endl;
		}
		else
		{
			cout << "是否要修改该员工：1，是  2，否" << endl;
			this->m_Array[number]->showInfo();
			int option2 = 0;
			cin >> option2;
			if (option2 == 1)
			{
				while (1)
				{
					int a = 0;
					cout << "请输入该员工的新编号" << endl;
					cin >> a;
					if (this->src_1Staff(a) != -1 && a != option1)
					{
						cout << "已存在该员工编号" << endl;
						continue;
					}
					this->m_Array[number]->m_id = a;
					break;

				}
				cout << "输入该员工的新姓名" << endl;
				cin >> this->m_Array[number]->m_name;
				cout << "输入该员工的新岗位编号" << "\n"
					<< "\t" << "1,员工" << "\n"
					<< "\t" << "2,经理" << "\n"
					<< "\t" << "3,老板" << endl;
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
					cout << "输入有误" << endl;
					break;
				}
				this->saveFile();
				cout << "修改成功" << endl;
			}
			else if (option2 == 2)
			{
				cout << "取消修改" << endl;
			}
			else
			{
				cout << "输入错误" << endl;
			}
		}
	}
	else if (option == 2)
	{
		cout << "输入要修改的员工姓名:" << endl;
		string option1 = "";
		cin >> option1;
		vector<int>a = this->src_2Staff(option1);
		if (a.empty())
		{
			cout << "未找到该员工" << endl;
		}
		else
		{
			int b = 0;
			cout << "请输入要修改员工的编号：" << endl;
			for (int i = 0;i < a.size(); i++)
			{
				this->m_Array[a.at(i)]->showInfo();
			}
			cin >> b;
			int c = src_1Staff(b);
			if (c == -1)
			{
				cout << "编号错误" << endl;
				system("pause");
				system("cls");
				return;
			}
			cout << "是否要修改该员工：1，是  2，否" << endl;
			this->m_Array[c]->showInfo();
			int option2 = 0;
			cin >> option2;
			if (option2 == 1)
			{
				while (1)
				{
					int a = 0;
					cout << "请输入该员工的新编号" << endl;
					cin >> a;
					if (src_1Staff(a) != -1 && a != b)
					{
						cout << "已存在该员工编号" << endl;
						continue;
					}
					this->m_Array[c]->m_id = a;
					break;

				}
				cout << "输入该员工的新姓名" << endl;
				cin >> this->m_Array[c]->m_name;
				cout << "输入该员工的新岗位编号" << "\n"
					<< "\t" << "1,员工" << "\n"
					<< "\t" << "2,经理" << "\n"
					<< "\t" << "3,老板" << endl;
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
					cout << "输入有误" << endl;
					break;
				}
				this->saveFile();
				cout << "修改成功" << endl;
			}
			else if (option2 == 2)
			{
				cout << "取消修改" << endl;
			}
			else
			{
				cout << "输入错误" << endl;
			}
		}
	}
	else
	{
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");
}
void workerManager::scr_Staff()
{
	if (this->m_file)
	{
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	int option = 0;
	cout << "选择查找的方式：" << "\n"
		<< "1,通过员工编号" << "\n"
		<< "2,通过员工姓名" << endl;
	cin >> option;
	if (option == 1)
	{
		cout << "输入要查找的员工编号:" << endl;
		int option1 = 0;
		cin >> option1;
		int number = src_1Staff(option1);
		if (number == -1)
		{
			cout << "未找到该员工" << endl;
		}
		else
		{
			cout << "查找成功：" << endl;
			this->m_Array[number]->showInfo();
		}
	}
	else if (option == 2)
	{
		cout << "输入要查找的员工姓名:" << endl;
		string option1 = "";
		cin >> option1;
		vector<int> number = src_2Staff(option1);
		if (number.empty())
		{
			cout << "未找到该员工" << endl;
		}
		else
		{
			for (int i = 0;i < number.size();i++)
			{
				cout << "查找成功：" << endl;
				this->m_Array[number.at(i)]->showInfo();
			}
		}
	}
	else
		{
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");
}
void workerManager::showInfo()
{
	if (m_file)
	{
		cout << "文件为空" << endl;
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
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请选择排序方式" << "\n"
		<< "1,编号升序排列" << "\n"
		<< "2,编号降序排列" << endl;
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
		cout << "排序成功" << endl;
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
		cout << "排序成功" << endl;
		this->saveFile();
		this->showInfo();
	}
	else
	{
		cout << "输入错误" << endl;
		system("pause");
		system("cls");
	}
	
}
void workerManager::cle_Staff()
{
	if (m_file)
	{
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请确认是否删除" << "\n"
		<< "    1,是" << "\n"
		<< "    2,否" << endl;
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
		cout << "清除成功" << endl;
	}
	else if (option1 == 2)
	{
		cout << "取消成功" << endl;
	}
	else
	{
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");
}