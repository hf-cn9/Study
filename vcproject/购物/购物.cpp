#include<stdio.h>
#include<string.h>
int main()
{
	int jq,bh,qd,i=0,k=0,sum=0,a,d,e;
	char sp[100][100]={"����","ˮ��","�߲�","���","ţ��"},name[100][100]={0};
	int N[100],n[100],zj[100];
	int bhjg[100][100]={{1238,16},{2456,23},{6538,4},{3456,6},{6384,21}};
	char b,c;
	printf("\t��Я���Ľ��Ϊ��");
	scanf("%d",&jq);
	do
	{
		do
		{
			printf("\t--------------��Ʒ�б�--------------\n");
			printf("\t��Ʒ���\t��Ʒ��\t��Ʒ�۸�\n");

			for (bh=0;bh<5;bh++)
				{
					printf("\t%d\t\t%s\t%d\n",bhjg[bh][0],sp[bh],bhjg[bh][1]);
				}
			printf("\t�����빺����Ʒ�ı��:");
            scanf("%d",&N[i]);
            printf("\t�����빺�������:");
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
                    printf("\t��������ȷ��Ʒ���\n");
                	printf("\t�Ƿ���Ҫ�������루����y/n��:");
					scanf("%s",&b);
					if(b=='y')
                    {
                        printf("\t--------------���������빺����Ʒ�ı��--------------\n\n\n");
                    }
				    continue;
                }
			
			printf("\t�Ƿ������������y/n����");
			scanf("%c",&b);
     	    i++;

        }while(b=='y');
		printf("\t-------------�����嵥--------------\n");
		if(e==1)
		{
			printf("\t��Ʒ���\t��Ʒ��\t��Ʒ����\t�����ܼ�\n");
  	        for (qd=0;qd<i;qd++)
			{
				printf("\t%d\t\t%s\t%d\t\t%d\n",N[qd],name[qd],n[qd],zj[qd]);
				sum = sum+zj[qd];
			}
		}
		else
		{
			printf("��û�����κζ���Ŷ~\n");
		}
   	    printf("\t�Ƿ�ȷ�Ϲ����嵥������y/n����");
    	scanf("%s",&c);
    }while(c=='n');
    printf("��Ʒ�ܽ��׽��Ϊ��%d\n",sum);
    if (jq<sum)
        printf("��������\n");
    else
        printf("���׳ɹ�������ʣ�����Ϊ��%d\n",jq-sum);
    return 0;
}