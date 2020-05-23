#include<stdio.h>
int main ()
{
	int i,ans,num;
	printf("---NUM FOR FUN 0-99---\n");
	printf("Ans : ");
	scanf("%d",&ans);
	do
	{
		if(ans>=0 && ans<=99)
		{
			break;
		}
		else
		{
			printf("Please enter again\n");	
		}
	}while(1);

	for(i=0;i<10;i++)
	{
		printf("\n");
		printf("T%02d : ",i+1);
		scanf("%d",&num);
		if (num==ans)
		{
			printf("\n<< Vitory >>\n");
			break;
		}
	
		else if (i==9)
		{
			printf("\nGame over\n");
			break;
		}
	
		else if (num<ans)
		{
			if (ans-3<=num )
			{
			printf("=Very close\n");
			}	
			else
			{
			printf("=Too small\n");	
			}
		}
		else if (num>ans)
		{
			if (ans+3>=num)
			{
			printf("=Very close\n");
			}
			else 
			{
			printf("=Too large\n");
			}	
	
		}
	}
	return 0;
}
