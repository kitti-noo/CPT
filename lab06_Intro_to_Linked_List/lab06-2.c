#include<stdio.h> 
#include<stdlib.h>
struct listnode 
{   
	int data;   
	struct listnode *next;
}; 
typedef struct listnode LN; 
 
void insert_at_back(LN **hptr, int d); 
void print(LN *head); 
int sum(LN *head); 
 
int main()
{   
  LN *head=NULL; 
  int d; 
  printf("Enter Number : "); 	  
	do
	{     
		scanf("%d",&d);     
		if(d > 0)
		{
			insert_at_back(&head,d);
		}      
	}while(d > 0); 
  printf("= ");
  print(head);
  
  printf("\n= %d",sum(head));   
   
  return 0; } 
 
void insert_at_back(LN **hptr, int d)
{
	LN *new_node = NULL;
	LN *node_p = *hptr;
	new_node=(LN*)malloc(sizeof(LN));
	new_node->data = d;
	new_node->next = NULL;
	 if(*hptr==NULL)
	{
  		*hptr=new_node;
	}
	else
	{
 		while(node_p->next!= NULL)
		 {
		 	node_p = node_p->next;	
		 }
  		node_p->next = new_node;
 	}
}

void print(LN *head)
{
		while (head != NULL) 
	{
		printf("%d ",head->data);
		head = head->next;
	}
} 
int sum(LN *head)
{
	int ssum=0;
	while (head != NULL)
	{
		ssum += head->data;
		head = head->next;
	}
	return ssum;
} 
