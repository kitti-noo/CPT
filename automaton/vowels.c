
/* vowels.c */
/* Andrew Davison, ad@fivedots.coe.psu.ac.th, April 2020 */

/*
  gcc -std=c99 -Wall -o vowels vowels.c
  ./vowels

  reads up to a newline

  Examples:
    $ gcc -std=c99 -Wall -o vowels vowels.c
    $ ./vowels
    Enter string: andrew
    Not accepted
    $ ./vowels
    Enter string: facetious
    Accepted
    $
    
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


enum state nextState(enum state s, int ch);
bool acceptable(enum state s);


enum state {N0, N1, N2, N3, N4, N5};  // poss. states


int main(void)
{
  enum state currState = N0;
  bool isAccepting =  false;
  int ch;

  printf("Enter string: ");
  while (((ch = getchar()) != '\n') && !isAccepting) {  
    currState = nextState(currState, ch);  
    isAccepting = acceptable(currState);
  }

  if (isAccepting)  
    printf("Accepted\n");
  else  
    printf("Not accepted\n");

  return 0;
}


enum state nextState(enum state s, int ch)
{ 
  if (s == N0)  
    return ((ch == 'a') ? N1 : N0);
  else if (s == N1)
    return ((ch == 'e') ? N2 : N1);
  else if (s == N2)
    return ((ch == 'i') ? N3 : N2);
  else if (s == N3)
    return ((ch == 'o') ? N4 : N3);
  else if (s == N4)
    return ((ch == 'u') ? N5 : N4);

  printf("Illegal Input\n");
  exit(1);
}  // end of nextState()


bool acceptable(enum state s)
{  
  if (s == N5)
    return true;    // N5 is an accepting state  
  return false;
} 


