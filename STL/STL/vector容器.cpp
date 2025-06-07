#include<iostream>
#include<vector>
#include<algorithm>//�㷨ͷ�ļ�
using namespace std;
#if 1
//STL���������
//�������������ݽṹ
//�㷨�����ֳ����㷨
//���������������㷨�Ľ��ϼ�
//�º�������Ϊ���ƺ���������С���ţ�
//������(�����)���������ηº������������������ӿڵĶ���
//�ռ�������������ռ�����������
void myPrint(int val)
{
	cout << val << endl;
}
void vecPrint(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//vector��̬��չ��������һ������Ŀռ䣬��ԭ�����ݺ���Ҫ���ӵ����ݸ�ֵ������¿ռ䣻��һ��������Ķ༸����ȡ�����ڲ��㷨��
void test01()
{
	//vector�������������飻
	vector<int>v;//�޲ι���
	vector<int>v2(v.begin(), v.end());//����v1�е�����Ԫ��(���캯��)
	vector<int>v3(10, 100);//10��100�����ʼ��
	vector<int>v4(v3);//��������
	//push_back����������β������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	//��һ���㷨
	
	//vector<int>::iterator �õ�����vector<int>�ĵ���������
	////begin()������������ָ�������һ��Ԫ��λ�ã�rbegin()����ָ�����һ��Ԫ�أ�
	//vector<int>::iterator itBegin = v.begin();
	////end()������������ָ���������һ��Ԫ�صĺ�һ��λ�ã�rend()����ָ���һ��Ԫ�ص�ǰһ��λ�ã�
	//vector<int>::iterator itEnd = v.end();
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	
	//�ڶ���ѭ��������
	/*for (vector<int>::iterator itBegin = v.begin();itBegin != v.end();itBegin++)
	{
		cout << *itBegin << endl;
	}*/

	//������
	
	//�����㷨�е�for_each;
	for_each(v.begin(), v.end(),myPrint);//���ûص�����
}
//����Ƕ������
void test02()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	for (int i = 0; i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
		v3.push_back(i+2);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	for (vector<vector<int>>::iterator it = v.begin();it != v.end();it++)
	{
		for (vector<int>::iterator it1 = (*it).begin();it1 != (*it).end();it1++)
		{
			cout << *it1 << " ";
		}
		cout << endl;
	}
}
//��ֵ
void test03()
{
	//push_back()��ֵ
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	//operator=��ֵ
	vector<int>v2;
	v2 = v;
	//assign
	vector<int>v3;
	v3.assign(v.begin(), v.end());
	//n��elem
	vector<int>v4;
	v4.assign(10, 100);//10��100
}
//�����ʹ�С
void test04()
{
	vector<int>v;
	for (int i = 0;i < 10; i++)
	{
		v.push_back(i);
	}
	vecPrint(v);
	//�ж��Ƿ�Ϊ��
	if (!v.empty())//����bool
	{
		cout << "noempty" << endl;
	}
	cout << v.capacity() << endl;//��������
	cout << v.size() << endl;//���ش�С
	v.resize(15, 10);//����ָ����С�������10������дĬ����0�����ٵ�ɾβ�������ǲ�����������

}
//����ɾ��
void  test05()
{
	vector<int> v1;
	//β��
	for (int i = 0;i < 10; i++)
	{
		v1.push_back(i);
	}
	//βɾ
	v1.pop_back();
	//����
	v1.insert(v1.begin()+2, 2, 100);// ��һ������Ҫ���ǵ�����(����ֱ����+�ţ���Ϊ�Ѿ����ع�����)
									// �ڶ�����������������дĬ��Ϊ1
									// �����������ǲ��������
	//ɾ��
	v1.erase(v1.begin(),v1.begin()+3);//ɾ��ǰ3��Ԫ�أ�����Ԫ�ز�д����ֻɾ��һ������
	//���
	v1.clear();
}
//��ȡ
//������������ֵ��ֻ������������
void test06()
{
	vector<int> v1;
	for (int i = 0;i < 10; i++)
	{
		v1.push_back(i);
	}
	//operator[]����
	cout << v1[0] << endl;
	//at(index)
	cout << v1.at(0) << endl;
	//front()��ȡ��һ��Ԫ��
	cout << v1.front() << endl;
	//back()�������һ��Ԫ��
	cout << v1.back() << endl;
}
//��������
void test07()
{
	vector<int> v1;
	for (int i = 0;i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	for (int i = 10;i > 0; i--)
	{
		v2.push_back(i);
	}
	v1.swap(v2);//����
	vecPrint(v1);
	vecPrint(v2);
	//����������
	v1.resize(5);
	vector<int>(v1).swap(v1);// �������󴴽���һ����v����v1�����ݳ�ʼ��
							 // swap������������,ʹ��v1ָ������v�Ŀռ䣬��vָ��v1
							 // ��v���������󣬱���ִ�����ϵͳ�Զ�ɾ����
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
}
//Ԥ���ռ�,������չ�����������ڴ�����µķ���Ĵ���������Ч��
void test08()
{
	vector<int> v1;
	v1.reserve(10000);//Ԥ����10000�Ŀռ�
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 10000;i++)
	{
		v1.push_back(i);
		if (p != &v1[0])//�������¿��ٿռ�Ĵ���
		{
			p = &v1[0];
			num++;
		}
	}
	cout << num << endl;
}
int main()
{
	test08();
	system("pause");
	return 0;
}
#endif