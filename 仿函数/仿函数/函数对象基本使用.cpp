#include<iostream>
#include<string>
#if 1
using namespace std;
//�º����������Լ��ķ���ֵ�������в���
class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
//������ͨ�����ĸ���������Լ���״̬:(�����¼���������˶��ٴΣ��������ڲ�ֱ�Ӵ���һ���������ڼ�¼)
class MyPrint
{
public:
	void operator()(string test)
	{
		cout << test << endl;
	}
};
//���������������ڴ���
void Print(MyPrint& m, string& s)
{
	m(s);
}
void test11()
{
	MyAdd ma;
	cout << ma(10, 20) << endl;
	MyPrint()("2020");
}
int main()
{
	test11();
	
	system("pause");
	return 0;
}
#endif