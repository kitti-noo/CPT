#include<stdio.h> 
#include<stdlib.h>
struct listnode
{    
	int data;    
	struct listnode *next; 
};  
typedef struct listnode LN; 
typedef LN *LNP; 
 
typedef struct
{    
	int size;    
	LNP head; 
}Stack; 
 
void push(Stack *sptr, int v); 
int pop(Stack *sptr); 
void cal(Stack *sptr, char operator); 
 
int main()
{    
	Stack stack = {0, NULL};    
	char s[128]; 
	int i,num;  
	printf("Enter Postfix-notation : "); 
	gets(s);
	
 	for (i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ')
		{
			continue;
		}
		if (s[i] >= '0' && s[i] <= '9')
	 	{
	 		num = s[i]-48;
	 		push(&stack,num);
		}
		else
		{
			cal(&stack,s[i]);
		}
	} 
	
	printf("= %d",pop(&stack));
   return 0; 
} 

void push(Stack *sptr, int v)
{
	LN *new_node = NULL;
	new_node=(LN*)malloc(sizeof(LN));
	new_node->data = v;
	new_node->next = sptr->head ;
	sptr->head = new_node; 
}

int pop(Stack *sptr)
{
	int d;
//	sptr->size-1;
	d = sptr->head->data;
	sptr->head = sptr->head->next;
//	sptr->size --;
	return d;
}
void cal(Stack *sptr, char operator)
{
	int a,b;
	a = pop(sptr);
	b = pop(sptr);
	printf("(%d %c %d)\n",b,operator,a);
	switch(operator)
	{
		case '+' : push(sptr,b+a);break;
		case '-' : push(sptr,b-a);break;
		case '*' : push(sptr,b*a);break;
		case '/' : push(sptr,b/a);break;	
	}
	
	
}
 
