#include"�ݽ���������ϵͳ.h"

int main()
{
	int option = 0;
	Manager M;
	do {
		M.Menu();
		cout << "��ѡ��";
		cin >> option;
		switch (option)
		{
		case 1://��ʼ����
			M.Speech();
			system("pause");
			break;
		case 2://�鿴��¼
			M.loadRecord();
			system("pause");
			break;
		case 3://��ռ�¼
			M.clearRecord();
			system("pause");
			break;
		case 0://�˳�ϵͳ
			M.Exit();
			break;
		}
		system("cls");
	} while (1);
	return 0;
}