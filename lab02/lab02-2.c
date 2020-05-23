#include<stdio.h>
#include<string.h>
char* find_char(char s[], int c); 
int main()
{
	char str[128];
	char c;
	char *ch;
	printf("String : ");
	gets(str);
	fflush(stdin);
	printf("Character : ");
	scanf("%c",&c);
	fflush(stdin);
	ch = find_char(str,c); 
	printf("=%c ",*ch);
	return 0;
}
char* find_char(char s[], int c)
{
	char *findstr;
	int i;
	for (i=0;i<strlen(s);i++)
	{
		if(s[i] == '\0')
		{
			return  NULL;
		}
		else if (s[i] == c)
		{
			return findstr= &s[i+1];
		}
	}
} 
