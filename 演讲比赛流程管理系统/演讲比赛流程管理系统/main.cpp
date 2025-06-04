#include"演讲比赛管理系统.h"

int main()
{
	int option = 0;
	Manager M;
	do {
		M.Menu();
		cout << "请选择：";
		cin >> option;
		switch (option)
		{
		case 1://开始比赛
			M.Speech();
			system("pause");
			break;
		case 2://查看记录
			M.loadRecord();
			system("pause");
			break;
		case 3://清空记录
			M.clearRecord();
			system("pause");
			break;
		case 0://退出系统
			M.Exit();
			break;
		}
		system("cls");
	} while (1);
	return 0;
}