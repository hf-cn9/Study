#pragma once
#include "workerManager.h"

int main()
{
	workerManager company;

	while (1)
	{
		int option = 0;
		company.showMenu();
		cout << "���������Ҫ���еĲ���:" << endl;
		cin >> option;
		switch (option)
		{
		case 0://�˳�
			company.exitMenu();
			break;
		case 1://����
			company.addStaff();
			break;
		case 2://ɾ��
			company.del_Staff();
			break;
		case 3://�޸�
			company.rev_Staff();
			break;
		case 4://����
			company.scr_Staff();
			break;
		case 5://��ʾ
			company.showInfo();
			break;
		case 6://����
			company.sort_Staff();
			break;
		case 7://���
			company.cle_Staff();
			break;
		}
	}
	system("pause");
	return 0;
}