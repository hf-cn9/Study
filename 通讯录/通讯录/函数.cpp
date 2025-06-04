#include "function.h"
// 显示菜单
void showMenu()
{
	cout << "**************************" << endl;
	cout << "***** 1.添加联系人 *******" << endl;
	cout << "***** 2.显示联系人 *******" << endl;
	cout << "***** 3.删除联系人 *******" << endl;
	cout << "***** 4.查找联系人 *******" << endl;
	cout << "***** 5.修改联系人 *******" << endl;
	cout << "***** 6.清空联系人 *******" << endl;
	cout << "***** 0.退出通讯录 *******" << endl;
	cout << "**************************" << endl;
}

//添加联系人
void addperson(PersonAddressBook* personbook)
{
	if (personbook->size >= MAX)
	{
		cout << "联系人数量已达上限，无法添加" << endl;
		return;
	}
	cout << "请输入联系人姓名：" << endl;
	cin >> personbook->personArray[personbook->size].name;
	cout << "请输入联系人性别：" << endl;
	cout << "   1.男 2.女" << endl;
	int i = 0;
	cin >> i;
	string sex[3] = { "男","女","保密"};
	while (1)
	{
		if (i != 1 && i != 2 && i != 3)
		{
			cout << "输入有误，请重新输入:" ;
			cin >> i;
		}
		else
			break;
	}
	personbook->personArray[personbook->size].sex = sex[i - 1];
	cout << "请输入联系人年龄：" << endl;
	cin >> personbook->personArray[personbook->size].age;
	cout << "请输入联系人电话：" << endl;
	cin >> personbook->personArray[personbook->size].phone;
	cout << "请输入联系人地址：" << endl;
	cin >> personbook->personArray[personbook->size].address;
	cout << "添加成功" << endl;
	personbook->size++;
	cout << "通讯录中目前有" << personbook->size << "个联系人" << endl;
}

//显示联系人
void showperson(PersonAddressBook* personbook)  
{  
   if (personbook->size == 0)  
   {  
       cout << "通讯录为空" << endl;  
       return;  
   }  
   for (int i = 0; i < personbook->size; i++)
   {  
       cout << i + 1 << ","  
           << "姓名：" << personbook->personArray[i].name
           << " \t性别：" << personbook->personArray[i].sex
           << " \t年龄：" << personbook->personArray[i].age
           << " \t电话：" << personbook->personArray[i].phone
           << " \t地址：" << personbook->personArray[i].address << endl;
   }  
}



//删除联系人
void delectperson(PersonAddressBook* personbook)
{
	
	int option_2 = 0;
	int option_3 = 0;
	int option_4 = 0;
	do{
		restart:
		int option_1 = findperson_1(personbook);
		if (option_1 == -2)
		{
			cout << "无此联系人，删除失败" << endl;
			while (1)
			{
				do {
					cout << "1,重新输入 0，返回上一级" << endl;
					cin >> option_4;
				} while (option_4 != 0 && option_4 != 1);
				if (option_4 == 1)
				{
					system("cls");
					goto restart;
				}
				else
				{
					return;
				}
			}
		}
		if (option_1 == -1)
		{
			cout << "通讯录为空"<<endl;
			system("pause");
			return;
		}
		do{
			cout << "请确认是否删除该联系人："
				<<     "1，是；0，否" << endl;
			cin >> option_2;
		} while (option_2 != 0 && option_2 != 1);
		
		if (option_2 == 1)
		{
			for (int i = option_1;i < personbook->size;i++)
			{
				personbook->personArray[i] = personbook->personArray[i + 1];
				personbook->size--;
				cout << "删除成功" << endl;
				system("pause");
				return;
			}
		}
		cout <<      "取消删除\n" 
			<< "1.重新输入 0.返回上一级" << endl;
		cin >> option_3;
		system("cls");
	} while (option_3);
}

//查找联系人
void findperson(PersonAddressBook* personbook)
{
	int option = 0;
	do{
		int find = findperson_1(personbook);
		if (find == -2)
		{
			do {
				cout <<"1,重新输入 2，返回上一级"<< endl;
				cin >> option;
			} while (option != 0 && option != 1);
			system("cls");
			continue;
		}
		if (find == -1)
		{
			cout << "通讯录为空"<<endl;
			system("pause");
			return;
		}
		system("pause");
		return;
	} while (option);
}

//修改联系人
void modifyperson(PersonAddressBook* personbook)
{
	int option = 0;
	int option_1 = 0;
	do {
		int find = findperson_1(personbook);
		if (find == -2)
		{
			cout << "无此联系人，请确认姓名是否正确" << endl;
			do {
				cout << "1,重新输入 0，返回上一级" << endl;
				cin >> option;
			} while (option != 0 && option != 1);
			system("cls");
			continue;
		}
		else if(find == -1)
		{
			cout << "通讯录为空" << endl;
			system("pause");
			return;
		}
		else
		{
			do {
				cout << "请确认是否修改该联系人："
					<< "1，是；0，否" << endl;
				cin >> option_1;
			} while (option_1 != 0 && option_1 != 1);
			if (option_1 == 0)
			{
				cout << "取消修改" << endl;
				system("pause");
				return;
			}
		}
		cout << "请输入联系人姓名：" << endl;
		cin >> personbook->personArray[find].name;
		cout << "请输入联系人性别：" << endl;
		cout << "   1.男 2.女" << endl;
		int i = 0;
		cin >> i;
		string sex[3] = { "男","女","保密" };
		while (1)
		{
			if (i != 1 && i != 2 && i != 3)
			{
				cout << "输入有误，请重新输入:";
				cin >> i;
			}
			else
				break;
		}
		personbook->personArray[find].sex = sex[i - 1];
		cout << "请输入联系人年龄：" << endl;
		cin >> personbook->personArray[find].age;
		cout << "请输入联系人电话：" << endl;
		cin >> personbook->personArray[find].phone;
		cout << "请输入联系人地址：" << endl;
		cin >> personbook->personArray[find].address;
		cout << "修改成功" << endl;
		return;
	} while (option);
}

//清空联系人
void clearperson(PersonAddressBook* personbook)
{
	int option = 0;
	do {
		cout << "请确认是否清空通讯录："
			<< "1，是；0，否" << endl;
		cin >> option;
	} while (option != 0 && option != 1);
	if (option == 0)
	{
		cout << "取消清空" << endl;
		system("pause");
		return;
	}
	personbook->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
}
	
//查找函数
int findperson_1(PersonAddressBook* personbook)
{
	if (personbook->size == 0)
	{
		return -1;
	}
	int option = 0;
	cout << "请输入联系人姓名：";
	string name;
	cin >> name;
	for (int i = 0;i < personbook->size;i++)
	{
		if (name == personbook->personArray[i].name)
		{
			cout << i + 1 << ","
				<< "姓名：" << personbook->personArray[i].name
				<< " \t性别：" << personbook->personArray[i].sex
				<< " \t年龄：" << personbook->personArray[i].age
				<< " \t电话：" << personbook->personArray[i].phone
				<< " \t地址：" << personbook->personArray[i].address << endl;
			return i;
		}
	}
	return -2;
}