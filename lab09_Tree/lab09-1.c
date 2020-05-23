#include <stdio.h>
#include<stdlib.h>
struct treenode{
struct treenode *leftptr;
int data;
struct treenode *rightptr;
};
typedef struct treenode TREENODE;
typedef TREENODE *TREE;

int is_perfect_tree(TREE t);
void insert_node(TREE *tp, int value);
int main()
{
 TREE t = NULL;
 int i = 0, tmp;
 do
 {
 	printf("N%02d: ", i + 1);
 	scanf(" %d", &tmp);
 	if (tmp>0)
	 {
	 	 insert_node(&t,tmp);
	 }
	else
	{
		break;
	}
 	i++;
 }while(tmp > 0);

  	printf("Rerfect Tree = %s\n", is_perfect_tree(t) ? "Yes" : "No");	

 return 0;
}
 
 void insert_node(TREE *tp, int value) {
/* tp is a pointer to a BST */
if (*tp == NULL)
{
	*tp = malloc(sizeof(TREENODE));
	(*tp)->data = value;
	(*tp)->leftptr = NULL;
	(*tp)->rightptr = NULL;
}
else if (value < (*tp)->data )
	insert_node(&((*tp)->leftptr), value);
else if (value > (*tp)->data )
	insert_node(&((*tp)->rightptr), value);
else
	printf("duplicate node\n");
}

int is_perfect_tree(TREE t)
{
	if(t==NULL)
	{
		return 1;
	}
	else if(t->leftptr == NULL && t->rightptr == NULL)
	{	
		return 1;
		
	}
	else if(t->leftptr== NULL || t->rightptr == NULL)
	{
		return 0;
	}
	else
	{
		return is_perfect_tree(t->leftptr) && is_perfect_tree(t->rightptr);
	}
}


