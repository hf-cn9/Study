#include "function.h"
// ��ʾ�˵�
void showMenu()
{
	cout << "**************************" << endl;
	cout << "***** 1.�����ϵ�� *******" << endl;
	cout << "***** 2.��ʾ��ϵ�� *******" << endl;
	cout << "***** 3.ɾ����ϵ�� *******" << endl;
	cout << "***** 4.������ϵ�� *******" << endl;
	cout << "***** 5.�޸���ϵ�� *******" << endl;
	cout << "***** 6.�����ϵ�� *******" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *******" << endl;
	cout << "**************************" << endl;
}

//�����ϵ��
void addperson(PersonAddressBook* personbook)
{
	if (personbook->size >= MAX)
	{
		cout << "��ϵ�������Ѵ����ޣ��޷����" << endl;
		return;
	}
	cout << "��������ϵ��������" << endl;
	cin >> personbook->personArray[personbook->size].name;
	cout << "��������ϵ���Ա�" << endl;
	cout << "   1.�� 2.Ů" << endl;
	int i = 0;
	cin >> i;
	string sex[3] = { "��","Ů","����"};
	while (1)
	{
		if (i != 1 && i != 2 && i != 3)
		{
			cout << "������������������:" ;
			cin >> i;
		}
		else
			break;
	}
	personbook->personArray[personbook->size].sex = sex[i - 1];
	cout << "��������ϵ�����䣺" << endl;
	cin >> personbook->personArray[personbook->size].age;
	cout << "��������ϵ�˵绰��" << endl;
	cin >> personbook->personArray[personbook->size].phone;
	cout << "��������ϵ�˵�ַ��" << endl;
	cin >> personbook->personArray[personbook->size].address;
	cout << "��ӳɹ�" << endl;
	personbook->size++;
	cout << "ͨѶ¼��Ŀǰ��" << personbook->size << "����ϵ��" << endl;
}

//��ʾ��ϵ��
void showperson(PersonAddressBook* personbook)  
{  
   if (personbook->size == 0)  
   {  
       cout << "ͨѶ¼Ϊ��" << endl;  
       return;  
   }  
   for (int i = 0; i < personbook->size; i++)
   {  
       cout << i + 1 << ","  
           << "������" << personbook->personArray[i].name
           << " \t�Ա�" << personbook->personArray[i].sex
           << " \t���䣺" << personbook->personArray[i].age
           << " \t�绰��" << personbook->personArray[i].phone
           << " \t��ַ��" << personbook->personArray[i].address << endl;
   }  
}



//ɾ����ϵ��
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
			cout << "�޴���ϵ�ˣ�ɾ��ʧ��" << endl;
			while (1)
			{
				do {
					cout << "1,�������� 0��������һ��" << endl;
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
			cout << "ͨѶ¼Ϊ��"<<endl;
			system("pause");
			return;
		}
		do{
			cout << "��ȷ���Ƿ�ɾ������ϵ�ˣ�"
				<<     "1���ǣ�0����" << endl;
			cin >> option_2;
		} while (option_2 != 0 && option_2 != 1);
		
		if (option_2 == 1)
		{
			for (int i = option_1;i < personbook->size;i++)
			{
				personbook->personArray[i] = personbook->personArray[i + 1];
				personbook->size--;
				cout << "ɾ���ɹ�" << endl;
				system("pause");
				return;
			}
		}
		cout <<      "ȡ��ɾ��\n" 
			<< "1.�������� 0.������һ��" << endl;
		cin >> option_3;
		system("cls");
	} while (option_3);
}

//������ϵ��
void findperson(PersonAddressBook* personbook)
{
	int option = 0;
	do{
		int find = findperson_1(personbook);
		if (find == -2)
		{
			do {
				cout <<"1,�������� 2��������һ��"<< endl;
				cin >> option;
			} while (option != 0 && option != 1);
			system("cls");
			continue;
		}
		if (find == -1)
		{
			cout << "ͨѶ¼Ϊ��"<<endl;
			system("pause");
			return;
		}
		system("pause");
		return;
	} while (option);
}

//�޸���ϵ��
void modifyperson(PersonAddressBook* personbook)
{
	int option = 0;
	int option_1 = 0;
	do {
		int find = findperson_1(personbook);
		if (find == -2)
		{
			cout << "�޴���ϵ�ˣ���ȷ�������Ƿ���ȷ" << endl;
			do {
				cout << "1,�������� 0��������һ��" << endl;
				cin >> option;
			} while (option != 0 && option != 1);
			system("cls");
			continue;
		}
		else if(find == -1)
		{
			cout << "ͨѶ¼Ϊ��" << endl;
			system("pause");
			return;
		}
		else
		{
			do {
				cout << "��ȷ���Ƿ��޸ĸ���ϵ�ˣ�"
					<< "1���ǣ�0����" << endl;
				cin >> option_1;
			} while (option_1 != 0 && option_1 != 1);
			if (option_1 == 0)
			{
				cout << "ȡ���޸�" << endl;
				system("pause");
				return;
			}
		}
		cout << "��������ϵ��������" << endl;
		cin >> personbook->personArray[find].name;
		cout << "��������ϵ���Ա�" << endl;
		cout << "   1.�� 2.Ů" << endl;
		int i = 0;
		cin >> i;
		string sex[3] = { "��","Ů","����" };
		while (1)
		{
			if (i != 1 && i != 2 && i != 3)
			{
				cout << "������������������:";
				cin >> i;
			}
			else
				break;
		}
		personbook->personArray[find].sex = sex[i - 1];
		cout << "��������ϵ�����䣺" << endl;
		cin >> personbook->personArray[find].age;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> personbook->personArray[find].phone;
		cout << "��������ϵ�˵�ַ��" << endl;
		cin >> personbook->personArray[find].address;
		cout << "�޸ĳɹ�" << endl;
		return;
	} while (option);
}

//�����ϵ��
void clearperson(PersonAddressBook* personbook)
{
	int option = 0;
	do {
		cout << "��ȷ���Ƿ����ͨѶ¼��"
			<< "1���ǣ�0����" << endl;
		cin >> option;
	} while (option != 0 && option != 1);
	if (option == 0)
	{
		cout << "ȡ�����" << endl;
		system("pause");
		return;
	}
	personbook->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
}
	
//���Һ���
int findperson_1(PersonAddressBook* personbook)
{
	if (personbook->size == 0)
	{
		return -1;
	}
	int option = 0;
	cout << "��������ϵ��������";
	string name;
	cin >> name;
	for (int i = 0;i < personbook->size;i++)
	{
		if (name == personbook->personArray[i].name)
		{
			cout << i + 1 << ","
				<< "������" << personbook->personArray[i].name
				<< " \t�Ա�" << personbook->personArray[i].sex
				<< " \t���䣺" << personbook->personArray[i].age
				<< " \t�绰��" << personbook->personArray[i].phone
				<< " \t��ַ��" << personbook->personArray[i].address << endl;
			return i;
		}
	}
	return -2;
}