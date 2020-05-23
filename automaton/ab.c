#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


enum state nextState(enum state s, int ch);
bool acceptable(enum state s);


enum state {N1, N2, N3, N4};  // poss. states


int main(void)
{
  enum state currState = N1;  bool isAccepting =  false;
  int ch;
  
  printf("Start : N%d\n",currState+1);
  printf("Enter string: ");
  while (((ch = getchar()) != '\n') && !isAccepting) {  
    currState = nextState(currState, ch); 
	printf(" %c => State : N%d\n",ch,currState+1);
    
  }
	isAccepting = acceptable(currState);
  if (isAccepting)  
    printf("Accepted\n");
  else  
    printf("Not accepted\n");

  return 0;
}

//------------------------------------------------------//
enum state nextState(enum state s, int ch)
{ 
  if (s == N1) 
  {
  	if (ch == 'a')  
  		return N2;
  	else if (ch == 'b')
  		return N1;
  } 
  else if (s == N2)
  {
  	if (ch == 'a')  
  		return N4;
  	else if (ch == 'b')
  		return N2;
  }
  else if (s == N4)
  {
  	if (ch == 'a')  
  		return N3;
  	else if (ch == 'b')
  		return N4;
  }
  else if (s == N3)
  {
  	if (ch == 'a')  
  		return N1;
  	else if (ch == 'b')
  		return N2;
  }
 
  printf("Illegal Input\n");
  exit(1);
}  // end of nextState()


bool acceptable(enum state s)
{  
  if (s == N1 || s == N2)
    return true;    // N1 N2 is an accepting state  
  return false;
} 


