#pragma once
#include<iostream>
#include<string>
#include"Class.cpp"//��ģ�崴�����󲻻ᴴ����Ա�����������������Class.h����������֪����Ա�����ľ���ʵ��
//����һ�㲻����Դ��cpp,������ģ��һ����ͷ�ļ���д��.hpp�ļ�������ģ���еĴ���ȫд��һ��

#if 0
using namespace std;

//������ģ��ĳ�Ա�������ڵ���ʱ���������·��ļ���дʱ���ò���
void test_11()
{
	Person<string, int> p("����", 14);
	p.showInfo();
}
int main()
{
	test_11();
	system("pause");
	return 0;
}
#endif