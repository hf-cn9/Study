#include<iostream>
#include<string>
using namespace std;

class Base//ֻҪ��һ�����麯�������ǳ�����
		  //�޷�ʵ�������󣨲�����������������)
		  //���������д���麯������ȻҲ�ǳ�����
		  //���ǿ���������ഴ��һ��ָ�룬Ҳ���Ƿ�ʵ����
{
public:
	virtual void func() = 0;//���麯��
	Base() //�������к��ι��죬�����б���Ҳ��Ĭ�Ϲ��죬�������಻������Ĭ�Ϲ���
		   //�������к��ι��죬�������б���Ҳ��Ĭ�Ϲ��죬�����಻������Ĭ�Ϲ���
	{
		cout << "Base��Ĭ�Ϲ��캯��" << endl;
	
	}
	//virtual ~Base()//������
	//{
	//	cout << "Base����������" << endl;
	//}
	virtual ~Base() = 0;//�������������Ǳ�����ʵ��
						//���˴��������������Ҳ�ǳ�����
						//�����д���������������Բ�д������
						

};
Base::~Base()//����������ʵ��
{
	cout << "Base�Ĵ�������" << endl;
}
class Element : public Base
{
public:
	string* m_name;
	virtual void func()
	{
		cout << *m_name <<" Element��Base���鹹��������д " << endl;
	}
	Element()
	{
		cout << "Element��Ĭ�Ϲ��캯��" << endl;
	}
	Element(string name)
	{
		m_name = new string(name);
		cout << "Element�Ĺ��캯��" << endl;
	}
	
	~Element()
	{
		if (m_name != NULL)
		{
			delete m_name;
			m_name = NULL;
			cout << "Element����������" << endl;
		}
		
	}
};
void test02()
{
	Base* p = new Element("hello");
	p->func();
	delete p;//���麯��һ����
			 //Base������ָ���ͷ�ʱ��ѡ����Base������������������Element����������,�����ڴ�й¶

}
//int main()
//{
//	
//	test02();
//
//	system("pause");
//	return 0;
//}