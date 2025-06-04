#include<stdio.h>
int main()
{
	int sj[3][4]={{1,3,5,7},{2,3,6,7},{4,5,6,7}},jl[3]={0};
	int jg=0,a=1,b;

	printf("现在开始你可以从1—7中想一个数字，我将猜出你心中所想\n");
	printf("接下来我将分三次给出三组，每组四个数字，你只需要回答，你想的数字是否在这组里面\n");
	do
	{
    b=0;
	for(int i=0;i<3;i++)
	{ 
		printf("第%d组数:",i+1);
		for(int j=0;j<4;j++)
		{
			printf("%d,",sj[i][j]);
		}
    	printf("\n请回答有或者没有(有:1,没有:0):");
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
			printf("输入错误！请重头开始\n\n\n\n");
			b=1;
			break;
		}
	}
	}while(b==1);
	printf("所以你想的数字为%d\n",jg);
	return 0;
}