#include "function.h"

int main()
{
	int select = 0;
	PersonAddressBook personbook = {};
	do {
		showMenu();
		cout << "����������ѡ��" ;
		cin >> select;
		switch (select)
		{
		case 0://�˳�ͨѶ¼
			cout << "�˳��ɹ�����ӭ�´�ʹ��" << endl;
			break;
		case 1://�����ϵ��
			addperson( &personbook);
			system("pause");
			system("cls");
			break;
		case 2://��ʾ��ϵ��
			showperson(&personbook);
			system("pause");
			system("cls");
			break;
		case 3://ɾ����ϵ��
			delectperson(&personbook);
			system("cls");
			break;
		case 4://������ϵ��
			findperson(&personbook);
			system("cls");
			break;
		case 5://�޸���ϵ��
			modifyperson(&personbook);
			system("cls");
			break;
		case 6://�����ϵ��
			clearperson(&personbook);
			system("cls");
			break;
		}
	} while (select);
	

	system("pause");
	return 0;
}