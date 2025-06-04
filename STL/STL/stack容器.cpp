#include<iostream>
#include<stack>
#include<algorithm>//算法头文件

using namespace std;


//stack容器，栈容器
//栈不允许遍历（只能访问栈顶元素）

void test31()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	//只要栈不为空，就查看栈顶
	//拷贝构造
	stack<int>s1(s);
	//operator=
	stack<int>s2 = s;
	while (!s.empty())
	{
		//查看栈顶
		cout << s.top() << endl;
		//出栈
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