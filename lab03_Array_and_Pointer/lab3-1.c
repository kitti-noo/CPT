#include<stdio.h>
#define NUM 5
int sum (int *p, int *q); 
int main ()
{
	int i,num[NUM],total;
	for (i=0;i<NUM;i++)
	{
		printf("Number[%02d] : ",i+1);
		scanf("%d",&num[i]);
	}
	total = sum(&num[0],&num[NUM-1]);
	printf("sum = %d",total);
	return 0;
}
int sum(int *p, int *q)
{
	int sum=0,*i;
	for (i = p;i<=q;i++)
	{
		sum += *i;
	}
	return sum;
}

