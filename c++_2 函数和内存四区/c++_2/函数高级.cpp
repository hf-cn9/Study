#include<iostream>
#if 0
using namespace std;

int fuc(int a, int b = 20, int c = 30)
//int fuc(int a, int b = 20, int c)//error:Ĭ�ϲ���ֻ�ܴ����������ã�b֮�������Ĭ�ϲ�����
{
	return a + b + c;
}
//int fuc2(int a = 10, int b = 20, int c = 30);//�������ʱ��Ĭ�ϲ���������������Ĭ�ϲ�����
int fuc2(int a = 10, int b = 20, int c = 30)//�������ʱ��Ĭ�ϲ��������岻����Ĭ�ϲ�����
{
	return a + b + c;
}
int fuc3(int a, int)//ռλ����
{
	cout << "a = " << a << endl;
	return 0;
}
//�������أ���������ͬ�������б�ͬ����߸����ԣ�
//������������������
//1.��������ͬ��
//2.�����б�ͬ�������������ͬ����������Ͳ�ͬ�������˳��ͬ��
//3.ͬһ���������£�
int fuc3(int a)//���أ�����������ͬ������ͬ��
{
	cout << "a = " << a << endl;
	return 0;
}
//��������ע�����
//1.������Ϊ����������
void fuc4(int& a)//int& a = 10;error:���ñ������ñ�����
{
	cout << "&a " << endl;
}
void fuc4(const int& a)//const int& a = 10;�Ϸ���
{
	cout << "const &a " << endl;
}
//2.������������Ĭ�ϲ�����
void fuc5(int a, int b = 10)//���кϷ������Ե���fuc5(10,10);
{
	cout << "a��b " << endl;
}
void fuc5(int a)//���кϷ������ǵ���fuc5(10)�ᱨ��;
{
	cout << "a " << endl;
}


int main()
{
	fuc(10, 20, 30);//60
	fuc(10, 20);//60
	fuc(10);//60
	fuc(10, 30);//70������ʹ�ô���Ĳ�����
	//fuc2();����ִ�б�����Ϊ�ض�����Ĭ�ϲ�����
	fuc3(10, 10);//����Ҫ�еڶ���������
	fuc3(20);//a = 10
	int a = 10;
	fuc4(a);//��Ϊa�Ǳ��������Ե���int&�ĺ�����
	fuc4(10);//��Ϊ10�ǳ��������Ե���const int&�ĺ�����
	//fuc5(10);//���ñ�����Ϊ��������ʱ������ʱ����ȷ��


	system("pause");
	return 0;

}
#endif