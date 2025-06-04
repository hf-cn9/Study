#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

//deque˫������,���Զ�ͷ�����в����ɾ���Ĳ���
//vector��ͷ�����в����ɾ����Ч�ʵ���deque
//vector���ʵ��ٶȿ���deque
void deqPrint(const deque<int>& d)//const��ֹ�޸���ֵ
{
	for (deque<int>::const_iterator it = d.begin();it != d.end();it++)//��Ҫ��Ӧ�ĵ�����const_iterator
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test21()
{
	deque<int>d1;//Ĭ�Ϲ���
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	deqPrint(d1);
	deque<int>d2(d1.begin(), d1.end());//����
	deque<int>d3(3, 100);//3��100
	deque<int>d4(d3);//��������
}
//��ֵ
void test22()
{
	deque<int>d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	//operator=
	deque<int>d2;
	d2 = d1;
	//assign
	deque<int>d3;
	d3.assign(d1.begin(),d1.end());
	deque<int>d4;
	d4.assign(10, 100);//ʮ��100
}
//��С����
void test23()
{
	deque<int>d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	if (!d1.empty())
	{
		cout << "no empty" << endl;
	}
	cout << d1.size() << endl;
	d1.resize(15, 1);
	//d1û�������ĸ���
}
//����ɾ��
void test24()
{
	deque<int>d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);//β��
	}
	deque<int>d2;
	d2.push_back(10);
	d1.push_front(10);//ͷ��
	d1.pop_front();//ͷɾ
	d1.pop_back();//βɾ
	d1.insert(d1.begin() + 1, 2, 10);//��1���λ�ò�������10;
	d1.insert(d1.begin(), d2.begin(), d2.end());//��ͷ����������d2;
	d1.erase(d1.begin(), d1.end());//��������ɾ��
	d1.clear();//���
}
//���ݴ�ȡ
//ֻ�ɷ��ʣ����ɸ�ֵ
void test25()
{
	deque<int> d1;
	for (int i = 0;i < 10; i++)
	{
		d1.push_back(i);
	}
	//operator[]����
	cout << d1[0] << endl;
	//at(index)
	cout << d1.at(0) << endl;
	//front()��ȡ��һ��Ԫ��
	cout << d1.front() << endl;
	//back()�������һ��Ԫ��
	cout << d1.back() << endl;
}
//����
void test26()
{
	deque<int> d1;
	for (int i = 10;i > 0; i--)
	{
		d1.push_back(i);
	}
	deqPrint(d1);
	sort(d1.begin(), d1.end());//algorithm�Դ��������㷨
	deqPrint(d1);
}

int main3()
{
	test26();
	system("pause");
	return 0;
}