#include "test.h"

#define Day 7 //����곣���������޸�
#if 1
int main() 
{ 
/*
cout��ʹ��
*/
	//cout << "hello world" << endl;//cout���hello world
	
/*
����a�Ĵ���
��cout�е�ʹ��
*/

	/*int a = 10;
	cout << "a = " << a << endl;

	const int months = 12;*///const���α����ǳ����������޸�
/*
������ʹ��
*/
	/*cout << "һ����·ݣ�" << months<<"\n"
		<< "һ�ܵ�������" << Day << endl;*/
/*
sizeof��ʹ��
���ڲ鿴�������������͵Ĵ�С
*/
	/*cout << sizeof(int) << endl;*/
/*
string �����ַ�������
*/
	//string st = "hello world";//Ҫ��stringͷ�ļ�
	//cout << st << endl;
/*
��cin��������
*/
	/*cout << "������һ���ַ�����" ;
	cin >> st;
	cout << st << endl;*/

/*
��Ŀ�����?:
*/
	/*int b = 20;
	cout << (a > b ? a : b) << endl;*/

/*
srandʱ���������������
*/
	//srand((unsigned int)time(NULL));//��Ҫ��ctimeͷ�ļ�����ȡϵͳʱ��
	//int c = rand() % 100 + 1; //����1��100���������
	//cout << c << endl;
/*
while()�У������ڵ�i++��++i��ͬ
i++���ȶ�ȡi��ֵ���жϣ�Ȼ����������ӣ�֮�����ѭ��
++i�ȼ���i += 1 �������������жϣ�֮�����ѭ��
*/
	struct student //�ṹ��vs��Ĭ�϶�����Ϊ8
	{
		string name;//string���ʹ�СΪ40
		int age;//int���ʹ�СΪ4
		char a;//char���ʹ�СΪ1
	};
	cout << sizeof(student) << endl;//ѡȡĬ�϶��������ڴ��С����С����Ϊ������
								//ͬʱ���ṹ���ڴ��СΪ����������������
	int arr[5] = { 1,2,3,4,5 };
	int(*p)[5] = &arr;//����ָ�룬�洢�����ָ��
	int* p1[5] = { arr,arr + 1,arr + 2,arr + 3,arr + 4 };//ָ�����飬�洢ָ�������
	cout << sizeof(p) << endl;
	system("pause");
	return 0;
}
#endif