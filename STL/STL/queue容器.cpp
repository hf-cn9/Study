#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
//queue��������������ͷ������β��,ֻ�ܷ��ʶ�ͷ�Ͷ�β

void test41()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	//��������
	queue<int>q1(q);
	//operator=
	queue<int>q2 = q;
	while (!q.empty())
	{
		cout << q.front() << endl;//�鿴��ͷԪ��
		cout << q.back() << endl;//�鿴��βԪ��
		q.pop();//����
	}
	cout<<q.size()<<endl;

}
int main()
{
	test41();
	system("pause");
	return 0;
}