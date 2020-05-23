#include<stdio.h>
#include<string.h>
void replace_space(char *s, char c); 
int main ()
{
	char text[100],ch;
	printf("Enter : ");
	gets(text);
	printf("Char : ");
	scanf("%c",&ch);
	replace_space(text,ch);
	printf("= %s",text);
	return 0;
}
void replace_space(char *s, char c)
{
	int i=0;
	while (i<strlen(s))
	{
		if (*(s+i) == ' ')
		{
			*(s+i)= c;
		}
		i++;
	}
}
