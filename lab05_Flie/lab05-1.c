#include<stdio.h>
int main()
{
	int num,sum=0;
	FILE *fp;
	if ((fp = fopen("num.txt","r")) == NULL)
	{
		printf("File could not be opened\n");
	}
	else
	{
		printf("num.txt\n");
		while (!feof(fp))
		{	
			fscanf(fp, "%d",&num);
			sum += num;
			printf("-> %d\n",num);
			
		}
		fclose(fp);
		printf("sum = %d",sum);
		
	}
	return 0;
}
