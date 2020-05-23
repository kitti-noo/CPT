#include<stdio.h>
#define LEN 5
int* max(int *a, int *b);  
int main ()
{
	int i,num[LEN],*nmax;
	for (i=0;i<LEN;i++)
	{
		printf("Number[%02d] : ",i+1);
		scanf("%d",&num[i]);
	}
	nmax = max(&num[0],&num[1]);

	printf("max = %d ",*nmax);
	return 0;
}
int* max(int *a, int *b)
{
	int i,*max;
	max = a;
	for (i=0;i<LEN-1;i++)
	{
		 if (*a>*max||*b>*max)
		{
			max=a;
			if (*b>*max)
			{
			max=b;
			}
		}
	a+=i;
	b+=i;	 
	}
	return max;
}
