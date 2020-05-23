#include<stdio.h> 
#include<stdlib.h>
struct song
{   
	char title[128];   
	double duration; 
}; typedef struct song Song; 
 
struct listnode
{   
	Song *sp;   
	struct listnode *next; 
}; typedef struct listnode LN; 
 
Song *input_song(); 
void insert(LN **hptr, Song *sp); 
LN *find_tail(LN *head); 
double sum_duration(LN *head); 
void print(LN *head);

int main()
{   
	LN *head=NULL; 
	Song *sp;   
	int i;   
	for(i = 0; i < 5; i++)
	{     
		printf("Song[%0d] : ",i+1);
		sp = input_song();  //malloc, scanf Song in this function   
		insert(&head,sp); 		
	} 
 	printf("\n");
	print(head);
  	printf("\nTotal duration = %.2lf",sum_duration(head));   
	return 0; 	
} 
Song *input_song()
{   
	Song *s;
	s = (Song*)malloc(sizeof(Song));
	fflush(stdin);
	scanf("%[^\n]s",s->title);
	printf("Duration : ");
	scanf("%lf",&s->duration);
	return s;
} 
 
void insert(LN **hptr, Song *sp)
{    
	LN *new_node,*tail;
	new_node=(LN*)malloc(sizeof(LN));
	new_node->sp = sp;
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
		printf("S%d:%s ",i,head->sp->title);
		head = head->next;
		i++;
	}
} 

double sum_duration(LN *head)
{    
	double ssum=0;
	while (head != NULL)
	{
		ssum += head->sp->duration;
		head = head->next;
	}
	return ssum;
} 
