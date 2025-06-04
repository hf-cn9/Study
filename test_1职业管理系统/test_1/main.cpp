#pragma once
#include "workerManager.h"

int main()
{
	workerManager company;

	while (1)
	{
		int option = 0;
		company.showMenu();
		cout << "请输出你需要进行的操作:" << endl;
		cin >> option;
		switch (option)
		{
		case 0://退出
			company.exitMenu();
			break;
		case 1://增加
			company.addStaff();
			break;
		case 2://删除
			company.del_Staff();
			break;
		case 3://修改
			company.rev_Staff();
			break;
		case 4://查找
			company.scr_Staff();
			break;
		case 5://显示
			company.showInfo();
			break;
		case 6://排序
			company.sort_Staff();
			break;
		case 7://清空
			company.cle_Staff();
			break;
		}
	}
	system("pause");
	return 0;
}