#include<iostream>
using namespace std;

//���ô��ݺ����Ĳ�����
#if 1
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int& test()
{
	static int a = 10;
	return a;
}
void show(const int& value)//����Ҫ��ӡvalue��ֵ������Ҫ�ı�value��ֵ������ռ�ã��ֲ���ı�ֵ��
{
	cout << "value=" <<value<< endl;
}


int main()
{
	//���ã��������������
	int a = 10;
	int& b = a;//b��a�ı��������õı�����ָ�볣��
	//�ȼ���int* const p = &a;ָ�볣��ָ��ĵ�ַ�����Ըı䣻
	//���ñ����ʼ����int& b; //error:���ñ����ʼ����
	//int& b = 10; //error:���ò���������������
	//����һ����ʼ���󣬲����Ը��ģ�
	int c = 20;
	b = c; //�ǰ�c��ֵ����aָ����ڴ棬�����ǰ�bָ��c��
	//�ȼ���*p = c;

	int d = 30;
	
	swap(c, d);//c��d��ֵ������


	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	int& e = test();//e��a�ı�����
	test() = 100;//a��ֵ��Ϊ100���������ÿ�����Ϊ��ֵ��
	cout << "e = " << e << endl;
	

	//�������ã�ָ���ֵ�����Ըı䣻
	const int& f = 10;//fָ�򴢴�10���ڴ棬����f�����Ըı�10��ֵ��
	//�ȼ���int temp = 10; const int& f = temp;
	//f = 20; //error:�������ò����Ըı�ֵ��
	//���ã���ֹ�������
	show(f);//value=10

	system("pause");
	return 0;
}
#endif