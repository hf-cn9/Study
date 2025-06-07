#include<iostream>
#include<list>

using namespace std;
#if 0
//list����,����
void lisPrint(const list<int>& lis)
{
	for (list<int>::const_iterator it = lis.begin();it != lis.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test51()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	//��������Ĺ��캯��
	list<int>l1(l.begin(),l.end());
	//��������
	list<int>l2(l);
	//n��elem;
	list<int>l3(10, 100);

}
//��ֵ�ͽ���
void test52()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	list<int > l1;
	//operator=
	l1 = l;
	//assign
	list<int>l2;
	l2.assign(l.begin(),l.end());
	//n��elem
	list<int>l3;
	l3.assign(10, 100);
	//����
	l.swap(l1);//list�������Դ���swap
}
//��С����
void test53()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	if (!l.empty())
	{
		cout << "no empty" << endl;
	}
	cout << l.size() << endl;
	l.resize(7, 10);//�ض���С
	lisPrint(l);
}
//����ɾ��
void test54()
{
	list<int>l;
	//β��
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	//ͷ��
	l.push_front(20);
	lisPrint(l);
	//βɾ
	l.pop_back();
	//ͷɾ
	l.pop_front();
	//����
	list<int>::iterator it = l.begin();

	l.insert(++it, 100);//list����ֱ����begin()+num�ķ�ʽֱ��,��������֧����Ծʽ���ʣ���֧��˫��
	//ɾ��
	l.erase(++it);
	//����ֵ�Ƴ�
	l.remove(20);//�Ƴ����е�20
	//���
	l.clear();

}
//���ݴ�ȡ
void test55()
{
	list<int>l;
	//β��
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	//�������ִ�ȡ��ʽ,�����Կռ�,��֧��[]��at();
	//����ͷ��Ԫ��
	cout << l.front() << endl;
	//����β��Ԫ��
	cout << l.back() << endl;
}
//����ʵ�֣�
bool Mycompare(int v1,int v2)
{
	return v1 > v2;
}
//��ת������
void test56()
{
	list<int>l;
	//β��
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	//��ת��������
	l.reverse();
	lisPrint(l);
	//����
	l.sort();
	//���в�֧��������ʵ���������֧��algorithm���㷨
	//�ڲ����ṩһЩ�Դ����㷨
	lisPrint(l);
	l.sort(Mycompare);//�ṩ��Ӧ�ĺ���ʵ�ֽ���
	lisPrint(l);
}

int main()
{
	
	system("pause");
	return 0;
}
#endif