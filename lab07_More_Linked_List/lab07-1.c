#include<stdio.h> 
#include<stdlib.h>
struct song
{   
	char title[128];  
	double duration; 
}; 
typedef struct song Song; 
 
struct listnode
{   
	Song s;   
	struct listnode *next; 
}; 
typedef struct listnode LN; 
 
void insert(LN **hptr, Song *sp); 
LN *find_tail(LN *head); 
void print(LN *head);
double sum_duration(LN *head); 
 
int main()
{   
	LN *head=NULL; 
	Song buf;
	int i;
	for(i=0;i<5;i++) 
	{
		fflush(stdin);
		printf("Song[%0d] : ",i+1);
		scanf("%[^\n]s",buf.title);
		printf("Duration : ");
		scanf("%lf",&buf.duration);
		insert(&head,&buf); 	
	}
	printf("\n");
	print(head);
  	printf("\nTotal duration = %.2lf",sum_duration(head));   
	return 0; 
} 
 
void insert(LN **hptr, Song *sp)
{  
	LN *new_node;
	LN *tail;
	new_node=(LN*)malloc(sizeof(LN));
	new_node->s = *sp;
	new_node->next = NULL;
	
	tail = find_tail(*hptr);
	 if(*hptr==NULL)
	{
  		*hptr=new_node;
	}
	else
	{
 		tail->next = new_node; 
 	}
} 
 
LN *find_tail(LN *head)
{  
	LN *tails;
	 if(head == NULL)
	{
		return NULL;
	}
	else
	{
		tails = head;
		while(tails->next!= NULL)
		{
			tails = tails->next;	
		}
		return tails;
	}	
} 

void print(LN *head)
{
	int i=1;
	while (head != NULL) 
	{	
		printf("S%d:%s ",i,head->s.title);
		head = head->next;
		i++;
	}
} 

double sum_duration(LN *head)
{    
	double ssum=0;
	while (head != NULL)
	{
		ssum += head->s.duration;
		head = head->next;
	}
	return ssum;
} 
