
#include "test.h"
#if 0
int main()
{
//ˮ�ɻ���
	/*
	int score = 100;
	int score_1 = 0;
	int score_2 = 0;
	int score_3 = 0;
	

	while (score < 1000)
	{
		score_1 = score / 100;
		score_2 = score % 100 / 10;
		score_3 = score % 10;
		if (score == pow(score_3, 3) + pow(score_2, 3) + pow(score_1, 3))
		{
			cout << score << endl;
		}
		score++;
	}
	*/
//������
	/*
	for (int i = 1; i < 101;i++)
	{
		if (i % 10 ==7 || i /10 == 7 || i % 7 == 0)
		{
			cout << "������" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}
	*/
//�˷���
	/*
	for (int i = 1; i < 10;i++)
	{

		for (int j = 1; j <= i; j++)
		{
			cout <<j<<" * "<<i<<" = " << i * j<<"  ";
		}
		cout << endl;
	}
	*/
//��������
	/*
	int arr[] = { 1,2,3,4,5 };
	int* a = arr;
	int* b = (int*)(&arr + 1) - 1;
	int leight = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < leight/2; i++)
	{
		int c = 0;
		c = *a;
		*a = *b; 
		*b = c;
		b--;
		a++;

	}
	for (int i = 0;i < 5;i++)
	{
		cout << arr[i]<<endl;
	}
	*/


//ð������
	/*
	int arr[] = {8,7,6,5,4,3,2,1};
	int leight = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, leight);
	for (int i = 0; i < leight;i++)
	{
		cout << arr[i] << endl;
	}
	*/
//�ṹ������
	struct list {
		string name;
		int age;
		string sex;
	};
	list heros[] = { 
		"�ŷ�",28,"��",
		"����",25,"��",
		"����",30,"��",
		"����",26,"��",
		"����",24,"��" };
	int leight = sizeof(heros) / sizeof(heros[0]);
	for (int i = 0;i < leight - 1; i++)
	{
		for (int j = 0;j < leight - i - 1;j++)
		{
			if (heros[j].age > heros[j + 1].age)
			{
				list temp = heros[j];
				heros[j] = heros[j + 1];
				heros[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < leight; i++)
	{
		cout << "������" << heros[i].name
			<< " ���䣺" << heros[i].age
			<< " �Ա�" << heros[i].sex << endl;
	};
	system("pause");
	return 0;
}
//ð��������
void bubble_sort(int arr[], int leight)
{
	for (int i = 0; i < leight - 1;i++)
	{
		for (int j = 0; j < leight - i - 1;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
#endif



