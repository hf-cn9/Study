#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//���ı����ļ����ж�д����
void write01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::trunc);
	ofs << "���"<<endl;
	ofs << "����";
	ofs.close();
}
void read01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʧ��"<<endl;
		return;
	}
	
	char test1[1024] = { 0 };
	//��һ��
	/*while (ifs >> test)
	{
		cout << test << endl;
	}*/
	//�ڶ���
	/*while (ifs.getline(test1, sizeof(test1)))
	{
		cout << test1 << endl;
	}*/
	//������
	/*string file1;
	while (getline(ifs, file1))
	{
		cout << file1 << endl;
	}*/
	//������
	/*char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}*/
	ifs.close();
}
//�ö����ƶ��ļ����ж�д����
class Person
{
public:
	char m_name[64];
	int age;
	char m_id[20];
};
void write02()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out |ios:: binary | ios::trunc);
	Person p1 = { "����", 18, "123456" };
	ofs.write((const char*)&p1, sizeof(p1));
	ofs.close();
}
void read02()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "��ʧ��" << endl;
		return;
	}
	Person p2;
	ifs.read((char*) &p2,sizeof(p2));
	cout << p2.m_name << "\n"
		<< p2.age << "\n"
		<< p2.m_id << endl;
	ifs.close();
}
int main()
{
	write01();
	read01();
	write02();
	read02();

	system("pause");
	return 0;
}