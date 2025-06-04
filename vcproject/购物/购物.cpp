#include<stdio.h>
#include<string.h>
int main()
{
	int jq,bh,qd,i=0,k=0,sum=0,a,d,e;
	char sp[100][100]={"大米","水果","蔬菜","面包","牛奶"},name[100][100]={0};
	int N[100],n[100],zj[100];
	int bhjg[100][100]={{1238,16},{2456,23},{6538,4},{3456,6},{6384,21}};
	char b,c;
	printf("\t您携带的金额为：");
	scanf("%d",&jq);
	do
	{
		do
		{
			printf("\t--------------商品列表--------------\n");
			printf("\t商品编号\t商品名\t商品价格\n");

			for (bh=0;bh<5;bh++)
				{
					printf("\t%d\t\t%s\t%d\n",bhjg[bh][0],sp[bh],bhjg[bh][1]);
				}
			printf("\t请输入购买商品的编号:");
            scanf("%d",&N[i]);
            printf("\t请输入购买的数量:");
            scanf("%d",&n[i]);
			a=0;
			d=0;
			for(;a<5;a++)
			{   
				if(N[i]==bhjg[a][0])
				{
                    zj[i]=bhjg[a][1]*n[i];
					strcpy(name[i],sp[a]);
                    d=1;
					e=1;
					break;
				}
			}
			    if(d==0)
				{
                    printf("\t请输入正确商品编号\n");
                	printf("\t是否需要重新输入（输入y/n）:");
					scanf("%s",&b);
					if(b=='y')
                    {
                        printf("\t--------------请重新输入购买商品的编号--------------\n\n\n");
                    }
				    continue;
                }
			
			printf("\t是否继续购买（输入y/n）：");
			scanf("%c",&b);
     	    i++;

        }while(b=='y');
		printf("\t-------------购物清单--------------\n");
		if(e==1)
		{
			printf("\t商品编号\t商品名\t商品数量\t单行总价\n");
  	        for (qd=0;qd<i;qd++)
			{
				printf("\t%d\t\t%s\t%d\t\t%d\n",N[qd],name[qd],n[qd],zj[qd]);
				sum = sum+zj[qd];
			}
		}
		else
		{
			printf("您没有买任何东西哦~\n");
		}
   	    printf("\t是否确认购物清单（输入y/n）：");
    	scanf("%s",&c);
    }while(c=='n');
    printf("商品总交易金额为：%d\n",sum);
    if (jq<sum)
        printf("您的余额不足\n");
    else
        printf("交易成功，您的剩余余额为：%d\n",jq-sum);
    return 0;
}