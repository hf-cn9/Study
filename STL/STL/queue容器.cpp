#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
//queue，队列容器：队头出，队尾进,只能访问队头和队尾

void test41()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	//拷贝构造
	queue<int>q1(q);
	//operator=
	queue<int>q2 = q;
	while (!q.empty())
	{
		cout << q.front() << endl;//查看队头元素
		cout << q.back() << endl;//查看队尾元素
		q.pop();//出队
	}
	cout<<q.size()<<endl;

}
int main()
{
	test41();
	system("pause");
	return 0;
}