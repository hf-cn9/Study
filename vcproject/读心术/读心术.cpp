#include<stdio.h>
int main()
{
	int sj[3][4]={{1,3,5,7},{2,3,6,7},{4,5,6,7}},jl[3]={0};
	int jg=0,a=1,b;

	printf("���ڿ�ʼ����Դ�1��7����һ�����֣��ҽ��³�����������\n");
	printf("�������ҽ������θ������飬ÿ���ĸ����֣���ֻ��Ҫ�ش�����������Ƿ�����������\n");
	do
	{
    b=0;
	for(int i=0;i<3;i++)
	{ 
		printf("��%d����:",i+1);
		for(int j=0;j<4;j++)
		{
			printf("%d,",sj[i][j]);
		}
    	printf("\n��ش��л���û��(��:1,û��:0):");
    	scanf("%d",&jl[i]);
		if(jl[i]==1)
		{
			jg+=a;
			a*=2;
		}
		else if(jl[i]==0)
		{
			a*=2;
		}
		else
		{
			printf("�����������ͷ��ʼ\n\n\n\n");
			b=1;
			break;
		}
	}
	}while(b==1);
	printf("�������������Ϊ%d\n",jg);
	return 0;
}