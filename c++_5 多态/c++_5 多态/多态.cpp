#include<iostream>
using namespace std;

//��̬��
//��̬��̬���������غ���������أ�����ʱ��ַȷ����
//��̬��̬����������麯��ʵ������ʱ��̬������ʱ��ַȷ����
class Animal
{
public:
	virtual void speak() //��ʱAnimal�д洢����ָ��vftable��ָ��
						 //���ඨ��Ϊ�麯�����������Զ�����Ϊ�麯��
						 //vftable�л�洢&Animal::speak��Ҳ���Ǵ洢���Ǻ�����ַ
	{
		cout << "Animal speak" << endl;
	}
};
class Cat : public Animal
{
public:
	void speak()//������д���ຯ������ʱ�������vftable�лḲ�Ǹ����speak()����ڵ�ַ
				//����ʹ�ø����ָ������ã�ȥ��������Ķ���ʱ���ᷢ����̬
				//��vftable���ҵ���ȷ�ĺ����ӿڵ�ַ���룬����������ȷ�����Ҫ������
	{
		cout << "Cat speak" << endl;
	}
};
void doSpeak(Animal& animal)//�ȼ���Animal& animal = cat;
							//c++�������������ֱ��ת��������Ҫǿ������ת��
{	
	animal.speak();
}
void test01()
{
	Cat cat;
	doSpeak(cat);
	//��Ϊ����ʱ��ַ�Ѿ�ȷ������ʱ���õ��Ǹ���ĺ���
	//����ͨ��������speak()��������virtual��ʵ�ֶ�̬���Ϳ�����ȷ���
}

int main()
{
	test01();
	system("pause");
	return 0;
}