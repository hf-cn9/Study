#include <stdio.h>
int main()
{
   typedef struct date
    {
        int year;
        int mouth;
        int day;
    }DATE;
   typedef struct student
    	{
            char name[20];
            int id;
            char gender;
            DATE birthday;
            int score[3];
        }stu;
        stu s1={"wangming",229560506,'F',{2005,9,14},{85,89,90}};
    	printf("������%s\n",s1.name);
        printf("ѧ�ţ�%d\n",s1.id);
        printf("�Ա�%c\n",s1.gender);
        printf("�������ڣ�%d-%d-%d\n",s1. birthday.year,s1. birthday.mouth,s1. birthday.day);
        printf("�ɼ���%d\t%d\t%d\n",s1.score[0],s1.score[1],s1.score[2],s1.score[3]);
  	  return 0;
}