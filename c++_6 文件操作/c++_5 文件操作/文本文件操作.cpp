#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//用文本对文件进行读写操作
void write01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::trunc);
	ofs << "你好"<<endl;
	ofs << "世界";
	ofs.close();
}
void read01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败"<<endl;
		return;
	}
	
	char test1[1024] = { 0 };
	//第一种
	/*while (ifs >> test)
	{
		cout << test << endl;
	}*/
	//第二种
	/*while (ifs.getline(test1, sizeof(test1)))
	{
		cout << test1 << endl;
	}*/
	//第三种
	/*string file1;
	while (getline(ifs, file1))
	{
		cout << file1 << endl;
	}*/
	//第四种
	/*char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}*/
	ifs.close();
}
//用二进制对文件进行读写操作
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
	Person p1 = { "张三", 18, "123456" };
	ofs.write((const char*)&p1, sizeof(p1));
	ofs.close();
}
void read02()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
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