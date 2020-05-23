#include<stdio.h>
#include<stdlib.h>

struct set
{     
	float factor;     
	int amount;     
	int *values; 
};
typedef struct set SET; 

struct v
{   int k;     
	SET set; 
}; 
typedef struct v V; 
 
void input_v(V *p); 
int sum(int d[], int len); 
float f_v(V *p);

int main()
{    
	 V v;  
	 input_v(&v); 
    printf("f = %.1f",f_v(&v)); 
     //free values  
	free(v.set.values);
    return 0; 
}
void input_v(V *p)
{    
	int i;
	printf("k = ");  
	scanf("%d",&p->k);  
	printf("set.factor = ");    
	scanf("%f",&p->set.factor);  
	printf("set.amount = "); 
	scanf("%d",&p->set.amount);
	//malloc values  
 	p->set.values = (int *)malloc(p->set.amount*sizeof(int));  
    printf("set.values = ");
    for (i=0;i<p->set.amount;i++)
    {
    	scanf("%d",p->set.values+i);		
	}
} 
 
int sum(int d[], int len)
{       
	int ssum=0,i;
	for (i=0;i<len;i++)
	{
		ssum += d[i]; 
	}
	return ssum;
	
} 
 
float f_v(V *p)
{      
	float ans;
	int total;
	total = sum(p->set.values,p->set.amount);
	ans = p->k + (p->set.factor*(total));
	return ans;
} 
