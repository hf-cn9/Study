#include<iostream>

using namespace std;
#if 0
//��ͨ�������Է�����ʽ����ת��
//ģ�庯��������������ͣ����ᷢ����ʽ����ת����
//��������и��õ�ƥ�䣨Ҳ������ͨ����������intʱ������Ĳ�����char���������������������ת������ֱ�ӵ��ú���ģ�壻

//��ͨ������ģ�庯�������Ե���ʱ�����ȵ�����ͨ������
//����ͨ����ģ��ǿ�Ƶ���ģ�庯����myswap<>(a,b)���ǿ�ģ�壬���������ͣ�
//������������������ʵ��ģ�庯�����أ�


template<typename T>//����һ��ģ�壬���߱��������ں����T���ᱨ��
void myswap(T& dg1, T& dg2)//T���Զ����������Ƶ�
{
	T temp = dg2;
	dg2 = dg1;
	dg1 = temp;
}
template<class T> 
void Sort_Arr(T arr1[],int b)
{
	for (int i = 0;i < b - 1;i++)
	{
		int index = i;
		for (int j = i + 1; j < b;j++)
		{
			if (arr1[index] > arr1[j])
			{
				index = j;
			}
		}
		if (index == i)
		{
			continue;
		}
		myswap(arr1[i], arr1[index]);
	}
}
void test_1()
{
	int arr[] = { 2,4,2,1,6,4,2,1,6 };
	int number = sizeof(arr) / sizeof(arr[0]);
	Sort_Arr(arr ,number);
	for (int i = 0;i < number; i++)
	{
		cout << arr[i] << endl;
	}
}
int main()
{
	int a = 10;
	int b = 20;
	////T�Զ��Ƶ�����,(���Ǳ����Ƶ���һ�µ�T����)
	//myswap(a, b);
	////��ȷT������,(T�����ͱ���ȷ������ʹ�ã�������ṩ����������ʹ��<type>����ȷ���ͣ������޷�����)
	//myswap<int>(a, b);

	//cout << a << endl;
	//cout << b << endl;
	test_1();
	system("pause");
	return 0;
}
#endif