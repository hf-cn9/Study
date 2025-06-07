#include<iostream>

using namespace std;
#if 0
//普通函数可以发生隐式类型转换
//模板函数如果不声明类型，不会发生隐式类型转换；
//但是如果有更好的匹配（也就是普通函数参数是int时，导入的参数是char），编译器不会进行类型转换而是直接调用函数模板；

//普通函数和模板函数都可以调用时，优先调用普通函数；
//可以通过空模板强制调用模板函数；myswap<>(a,b)就是空模板，不声明类型；
//可以利用增减参数来实现模板函数重载；


template<typename T>//声明一个模板，告诉编译器对于后面的T不会报错
void myswap(T& dg1, T& dg2)//T会自动进行类型推导
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
	////T自动推导类型,(但是必须推导出一致的T类型)
	//myswap(a, b);
	////明确T的类型,(T的类型必须确定才能使用，如果不提供参数，必须使用<type>来明确类型，否则无法调用)
	//myswap<int>(a, b);

	//cout << a << endl;
	//cout << b << endl;
	test_1();
	system("pause");
	return 0;
}
#endif