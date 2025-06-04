#include<iostream>
#include<string>

using namespace std;
//string本质是一个类
void test11()
{
	string s1;//默认构造
	string s2("hello");//含参构造
	string s3(s2);//拷贝构造
	string s4(10, 'a');//含参构造
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}
//赋值
void test12()
{
	string s1;
	s1 = "hello";//operator=
	string s2;
	s2 = s1;//operator=
	string s3;
	s3.assign("abcdefg");//assign()赋值
	string s4;
	s4.assign("abcdefg", 5);//只取前5个字符
	string s5;
	s5.assign(s4,2,5);//从第2个位置开始，赋值到第五个字符；
	string s6;
	s6.assign(5, 'a');//五个a
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
}
//追加
void test13()
{
	string s1 = "我";
	s1 += "爱玩游戏";//operator+=字符串
	cout << s1 << endl;
	s1 +=':';//operator+=一个字符
	cout << s1 << endl;
	string s2 = "LOL";
	s1 += s2;//operator+=一个对象
	cout << s1 << endl;
	s1.append("和王者");//append()函数追加；
	cout << s1 << endl;
	s1.append("hhhhhhhh",5);//追加前五个字符
	cout << s1 << endl;
	s1.append(s2, 1, 2);//从第1个位置开始，追加两个字符
	cout << s1 << endl;
	s1.append(s2);//追加对象
	cout << s1 << endl;
	
}
//查找和替换
void test14()
{
	string s1 = "hello world";
	int pos = s1.find("llo", 2);//从第二个位置开始查找“llo”//不写默认为0；//查不到返回-1
	cout << pos << endl;
	pos = s1.rfind("o");//rfind 从右往左查找
	cout << pos << endl;
	s1.replace(0, 5, "HELLOA");//从第0个位置开始的5个字符替换成HELLOA，整体增加了一个字符
	cout << s1 << endl;
}
//比较
void test15()
{
	string s1 = "hallo world";
	string s2 = "hello world";
	if (s1.compare(s2) == 0)//compare 逐字符比较，直到完全相等，返回0 
	{
		cout << "s1 = s2" << endl;
	}
	else if (s1.compare(s2) > 0)//compare 逐字符比较，直到出现第一个不一样，返回1
	{
		cout << "s1 > s2" << endl;
	}
	else if (s1.compare(s2) < 0)//compare 逐字符比较，直到出现第一个不一样，返回-1
	{
		cout << "s1 < s2" << endl;
	}
}
//存取
void test16()
{
	string s1 = "Hello World";
	cout << s1[0] << endl;//operator[]直接访问
	cout << s1.at(0) << endl;//at()函数读取
	cout << s1.size() << endl;//返回s1 的大小
	s1[0] = 'A';//直接修改
	cout << s1 << endl;
	s1.at(0) = 'B';
	cout << s1 << endl;
}
//插入删除
void test17()
{
	string s1 = "Hello World";
	s1.insert(1,"ENY",2);//在第一个位置插入ENY中的两个字符EN，不写默认为全部插入
	cout << s1 << endl;
	s1.erase(1, 3);//从第一个位置删除三个字符
	cout << s1 << endl;
}
//求子串
void test18()
{
	string s1 = "Hello World";
	string s2 = s1.substr(1, 3);//从1号位置起，截取3个字符:ello
	cout << s2 << endl;
	int ops = s1.find(' ');
	s2 = s1.substr(0, ops);//截取空格前的字符
	cout << s2 << endl;
}
int main2()
{
	test17();
	system("pause");
	return 0;
}