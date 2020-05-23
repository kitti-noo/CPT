
/* lists.c */
/* Andrew Davison, ad@fivedots.coe.psu.ac.th, April 2020 */

/*
  gcc -std=c99 -Wall -o lists lists.c
  ./lists


  Example:
    $ gcc -std=c99 -Wall -o lists lists.c
    $ ./lists
    3 --> 5 --> 2 --> 7 --> 4 --> 9 --> 19 --> <null>
    Length of list: 7
    Found 19
    $
    
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct CELL {  
  int element;  
  struct CELL *next;
};

typedef struct CELL *LIST;



LIST makeList(int arr[], int i, int n);
void printList(LIST w);
int length(LIST w);
bool hasElem(LIST w, int x);
int range (LIST w);
int max_value (LIST w,int max);
int min_value (LIST w,int min);



int main(void)
{
  int arr[] = { 3, 5, 2, 7, 4, 9, 19};
  LIST w = makeList(arr, 0, 7);
  printList(w);

  int len = length(w);
  printf("Length of list: %d\n", len);

  int elem = 555;  // 19;
  if (hasElem(w, elem))
    printf("Found %d\n", elem);
  else
    printf("%d not in the list\n", elem);

  printf("Max : %d\n",max_value(w,w->element));
  printf("Min : %d\n",min_value(w,w->element));
  printf("Ans : %d - %d : %d",max_value(w,w->element),min_value(w,w->element),range(w));

  return 0;
}


LIST makeList(int arr[], int i, int n)
{
  if (i == n)   // end of array
    return NULL;
  else {
    LIST w = (LIST)malloc(sizeof(struct CELL));
    w->element = arr[i];
    w->next = makeList(arr, i+1, n);
    return w;
  }
}

void printList(LIST w)
{
  if (w == NULL)
    printf("<null>\n");
  else {
    printf("%d --> ", w->element);
    printList(w->next);
  }
}

int length(LIST w)
{ 
  if (w == NULL)
    return 0;
  else
     return 1 + length(w->next);
}

bool hasElem(LIST w, int x)
{
  if (w == NULL)
   return false;
  else if (w->element == x)
    return true;
  else
    return hasElem(w->next, x);
}

//----------------------------------------------------------------//
int range (LIST w)
{
	if (w == NULL)
	{
		return -1;
	}
	else
	{
		return max_value(w->next,w->element) - min_value(w->next,w->element);
		
	}
}
int max_value (LIST w,int max)
{

	if (w == NULL)
	{
		return max;	
	}
	else
	{
		if (w->element > max)
		{
			max = w->element;
		}
		return max_value(w->next,max);
	}
}

int min_value (LIST w,int min)
{

	if (w == NULL)
	{
		return min;
	}
	else
	{
		if (w->element < min)
		{
			min = w->element;
		}
		return min_value(w->next,min);
	}
}	

