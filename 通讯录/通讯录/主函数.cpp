#include "function.h"

int main()
{
	int select = 0;
	PersonAddressBook personbook = {};
	do {
		showMenu();
		cout << "请输入您的选择：" ;
		cin >> select;
		switch (select)
		{
		case 0://退出通讯录
			cout << "退出成功，欢迎下次使用" << endl;
			break;
		case 1://添加联系人
			addperson( &personbook);
			system("pause");
			system("cls");
			break;
		case 2://显示联系人
			showperson(&personbook);
			system("pause");
			system("cls");
			break;
		case 3://删除联系人
			delectperson(&personbook);
			system("cls");
			break;
		case 4://查找联系人
			findperson(&personbook);
			system("cls");
			break;
		case 5://修改联系人
			modifyperson(&personbook);
			system("cls");
			break;
		case 6://清空联系人
			clearperson(&personbook);
			system("cls");
			break;
		}
	} while (select);
	

	system("pause");
	return 0;
}