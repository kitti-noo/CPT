#include<stdio.h>
void to_next(char* cptr);
int main()
{
	char c;
	printf("Please enter (a-z) 1 character\n");
	printf("Enter : ");
	scanf("%c",&c);
	if (c >= 'a' && c<='z')
	{
	to_next(&c);
	printf("= %c",c);
	}
	else
	{
		printf("End.");
	}
	return 0;
}
void to_next(char* cptr)
{
	if(*cptr=='z')
	{
		*cptr = 'a';
	}
	else
	{
		*cptr+=1;
	}
}


