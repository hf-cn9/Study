#include "test.h"

#define Day 7 //定义宏常量，不可修改
#if 1
int main() 
{ 
/*
cout的使用
*/
	//cout << "hello world" << endl;//cout输出hello world
	
/*
变量a的创建
在cout中的使用
*/

	/*int a = 10;
	cout << "a = " << a << endl;

	const int months = 12;*///const修饰变量是常量，不可修改
/*
常量的使用
*/
	/*cout << "一年的月份：" << months<<"\n"
		<< "一周的天数：" << Day << endl;*/
/*
sizeof的使用
用于查看变量或数据类型的大小
*/
	/*cout << sizeof(int) << endl;*/
/*
string 定义字符串变量
*/
	//string st = "hello world";//要用string头文件
	//cout << st << endl;
/*
用cin输入数据
*/
	/*cout << "请输入一个字符串：" ;
	cin >> st;
	cout << st << endl;*/

/*
三目运算符?:
*/
	/*int b = 20;
	cout << (a > b ? a : b) << endl;*/

/*
srand时间种子生产随机数
*/
	//srand((unsigned int)time(NULL));//需要用ctime头文件，读取系统时间
	//int c = rand() % 100 + 1; //生成1—100的随机数字
	//cout << c << endl;
/*
while()中，括号内的i++和++i不同
i++会先读取i的值做判断，然后进行自增加，之后进入循环
++i等价于i += 1 ，先自增，再判断，之后进入循环
*/
	struct student //结构体vs中默认对齐数为8
	{
		string name;//string类型大小为40
		int age;//int类型大小为4
		char a;//char类型大小为1
	};
	cout << sizeof(student) << endl;//选取默认对齐数和内存大小中最小的作为对齐数
								//同时，结构体内存大小为最大对齐数的整数倍
	int arr[5] = { 1,2,3,4,5 };
	int(*p)[5] = &arr;//数组指针，存储数组的指针
	int* p1[5] = { arr,arr + 1,arr + 2,arr + 3,arr + 4 };//指针数组，存储指针的数组
	cout << sizeof(p) << endl;
	system("pause");
	return 0;
}
#endif