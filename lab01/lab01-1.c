#include<stdio.h>
int main ()
{
	char ch;
	do
	{
	printf("Enter Character : ");
	scanf("%c",&ch);
	fflush(stdin);
			if (ch>=65 && ch<=90 || ch>=97 && ch<=122)
			{
			
				if (ch>=97)
				{
				printf("%c = %d\n",ch,ch-96);
				}	
				else if (ch>=65)
				{
				printf("%c = %d\n",ch,ch-64);
				}
			}
			else
			{
				break;	
			}
		
	}while(1);
	printf("End.");
	return 0;
}
