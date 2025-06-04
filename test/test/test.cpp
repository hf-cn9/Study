#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int main()
{
	///*int i = 0;
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//for (i = 0; i <= 12; i++)
	//{
	//	arr[i] = 0;
	//	printf("%d",i);
	//}*/
	//unsigned char a = -1;
	//printf("%d", a);
	/*int a = 10;
	int b = 2;
	a = a - b;
	b = a + b;
	a = b - a;
	printf("%d %d", a, b);*/
	/*int a1 = 200;
	int a2 = 2;
	char* a1_p = (char*)&a1;
	char* a2_p = (char*)&a2;
	printf("%d", *a1_p);
	char temp = *a1_p;
	*a1_p = *a2_p;
	*a2_p = temp;*/
	/*int a[10] = { 1,2,3,4,5,6 };
	int(*p)[10] = &a;
	printf("%d", (*p)[1]);*/
	int a = 100;
	int* p = &a; 
	int b = !a;
	printf("%p\n", p );
	printf("%p\n", (int)p);
	printf("%d", b);
	return 0;
}



