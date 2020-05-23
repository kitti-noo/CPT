#include<stdio.h>
#include<string.h>
char* find_space(char *s); 
int main ()
{
	char text[100],ch;
	char *sptr;
	int i;
	printf("Enter : ");
	gets(text);
	printf("Char : ");
	scanf("%c",&ch);
	sptr = text;
	for (i=0;i<strlen(text);i++)
	{ 
		sptr = find_space(text);
		if (sptr != NULL)
		{
			*sptr = ch;		
		}			
	}
	printf("= %s",text);
	return 0;
}

char* find_space(char *s)
{
  	while (1)
	{
		if (*s == '\0')
		{
			return NULL;
		//	break;
		}
		else if (*s == ' ')
		{
			return s;
		}
		s++;
	}
}
