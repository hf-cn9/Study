#include<iostream>
#include<string>
#if 0
using namespace std;

class Building;
class GoodFriend3
{
public:
	GoodFriend3();//���ڱ������Ǵ��ϵ��±���ģ�����Ҫ�Ѷ�Building�Ĳ�������Building�������

	void visit();//���ڱ������Ǵ��ϵ��±���ģ�����Ҫ�Ѷ�Building�Ĳ�������Building�������

	Building* friend3;
};
class Building
{
	friend void GoodFriend1(Building* b); //������Ԫ����
	friend class GoodFriend2; //������Ԫ��
	friend void GoodFriend3::visit(); //������Ԫ��Ա����
public:
	Building()
	{
		m_hall = "����";
		m_bedroom = "����";
	}
public:
	string m_hall;
private:
	string m_bedroom;
};

//��Ԫȫ�ֺ������Է���˽�г�Ա����
void GoodFriend1(Building* b)
{
	cout << "��Ԫȫ�ֺ�������:" << endl;
	cout << b->m_bedroom << endl; //��Ԫȫ�ֺ������Է���˽�г�Ա����
}

//��Ԫ����Է���˽�г�Ա����
class GoodFriend2
{
public:	
	void visit(Building* b)
	{
		cout << "��Ԫ����ʣ�" << endl;
		cout << b->m_bedroom << endl; //��Ԫ����Է���˽�г�Ա����
	}

};

//��Ԫ��Ա�������Է���˽�г�Ա����
GoodFriend3::GoodFriend3()
{
	friend3 = new Building();
}
void GoodFriend3::visit()
{
	cout << "��Ԫ��Ա�������ʣ�" << endl;
	cout << friend3->m_bedroom << endl; //��Ԫ��Ա�������Է���˽�г�Ա����
}
int main()
{
	Building T1;
	GoodFriend1(&T1); //������Ԫ����
	GoodFriend2 T2; //������Ԫ��
	T2.visit(&T1); //������Ԫ��
	GoodFriend3 T3; //������Ԫ��Ա����
	T3.visit(); //������Ԫ��Ա����
	system("pause");
	return 0;
}
#endif