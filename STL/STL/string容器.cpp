#include<iostream>
#include<string>

using namespace std;
//string������һ����
void test11()
{
	string s1;//Ĭ�Ϲ���
	string s2("hello");//���ι���
	string s3(s2);//��������
	string s4(10, 'a');//���ι���
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}
//��ֵ
void test12()
{
	string s1;
	s1 = "hello";//operator=
	string s2;
	s2 = s1;//operator=
	string s3;
	s3.assign("abcdefg");//assign()��ֵ
	string s4;
	s4.assign("abcdefg", 5);//ֻȡǰ5���ַ�
	string s5;
	s5.assign(s4,2,5);//�ӵ�2��λ�ÿ�ʼ����ֵ��������ַ���
	string s6;
	s6.assign(5, 'a');//���a
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
}
//׷��
void test13()
{
	string s1 = "��";
	s1 += "������Ϸ";//operator+=�ַ���
	cout << s1 << endl;
	s1 +=':';//operator+=һ���ַ�
	cout << s1 << endl;
	string s2 = "LOL";
	s1 += s2;//operator+=һ������
	cout << s1 << endl;
	s1.append("������");//append()����׷�ӣ�
	cout << s1 << endl;
	s1.append("hhhhhhhh",5);//׷��ǰ����ַ�
	cout << s1 << endl;
	s1.append(s2, 1, 2);//�ӵ�1��λ�ÿ�ʼ��׷�������ַ�
	cout << s1 << endl;
	s1.append(s2);//׷�Ӷ���
	cout << s1 << endl;
	
}
//���Һ��滻
void test14()
{
	string s1 = "hello world";
	int pos = s1.find("llo", 2);//�ӵڶ���λ�ÿ�ʼ���ҡ�llo��//��дĬ��Ϊ0��//�鲻������-1
	cout << pos << endl;
	pos = s1.rfind("o");//rfind �����������
	cout << pos << endl;
	s1.replace(0, 5, "HELLOA");//�ӵ�0��λ�ÿ�ʼ��5���ַ��滻��HELLOA������������һ���ַ�
	cout << s1 << endl;
}
//�Ƚ�
void test15()
{
	string s1 = "hallo world";
	string s2 = "hello world";
	if (s1.compare(s2) == 0)//compare ���ַ��Ƚϣ�ֱ����ȫ��ȣ�����0 
	{
		cout << "s1 = s2" << endl;
	}
	else if (s1.compare(s2) > 0)//compare ���ַ��Ƚϣ�ֱ�����ֵ�һ����һ��������1
	{
		cout << "s1 > s2" << endl;
	}
	else if (s1.compare(s2) < 0)//compare ���ַ��Ƚϣ�ֱ�����ֵ�һ����һ��������-1
	{
		cout << "s1 < s2" << endl;
	}
}
//��ȡ
void test16()
{
	string s1 = "Hello World";
	cout << s1[0] << endl;//operator[]ֱ�ӷ���
	cout << s1.at(0) << endl;//at()������ȡ
	cout << s1.size() << endl;//����s1 �Ĵ�С
	s1[0] = 'A';//ֱ���޸�
	cout << s1 << endl;
	s1.at(0) = 'B';
	cout << s1 << endl;
}
//����ɾ��
void test17()
{
	string s1 = "Hello World";
	s1.insert(1,"ENY",2);//�ڵ�һ��λ�ò���ENY�е������ַ�EN����дĬ��Ϊȫ������
	cout << s1 << endl;
	s1.erase(1, 3);//�ӵ�һ��λ��ɾ�������ַ�
	cout << s1 << endl;
}
//���Ӵ�
void test18()
{
	string s1 = "Hello World";
	string s2 = s1.substr(1, 3);//��1��λ���𣬽�ȡ3���ַ�:ello
	cout << s2 << endl;
	int ops = s1.find(' ');
	s2 = s1.substr(0, ops);//��ȡ�ո�ǰ���ַ�
	cout << s2 << endl;
}
int main2()
{
	test17();
	system("pause");
	return 0;
}