#include<stdio.h>
#define LEN 5
int* find_max(int *p, int *q); 
int main ()
{
	int i,num[LEN],*fmax;
	for (i=0;i<LEN;i++)
	{
		printf("Number[%02d] : ",i+1);
		scanf("%d",&num[i]);
	}
	fmax = find_max(&num[0],&num[LEN-1]);
	for (i=0;i<LEN;i++)
	{ 
		printf("%d ",*(fmax+i));
	}
	return 0;
}
int* find_max(int *p, int *q)
{
	int temp,i,*num,*num_next,*max;
	for (i=0;i<LEN;i++)
	{
		for (num=p;num<=q;num++)
		{
			num_next = num+1; 
			if(*num<*num_next)
			{
				temp = *num;
				*num = *num_next;
				*num_next = temp;
		
			}
		
		}	
	}
	max = p;
	return max;
}
