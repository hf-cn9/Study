#include<iostream>
#include<stack>
#include<algorithm>//�㷨ͷ�ļ�

using namespace std;


//stack������ջ����
//ջ�����������ֻ�ܷ���ջ��Ԫ�أ�

void test31()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	//ֻҪջ��Ϊ�գ��Ͳ鿴ջ��
	//��������
	stack<int>s1(s);
	//operator=
	stack<int>s2 = s;
	while (!s.empty())
	{
		//�鿴ջ��
		cout << s.top() << endl;
		//��ջ
		s.pop();
	}
	cout<<s.size()<<endl;
}
int main4()
{
	test31();

	system("pause");
	return 0;
}