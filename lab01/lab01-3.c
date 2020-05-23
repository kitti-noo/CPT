#include <stdio.h> 
char enc_char(char c);
int check_char(char c);
int main()
{ 
  char text;
  printf("<-- Consonant -->\n");
  text = getchar(); 
  
  while(text != EOF)
  {
	text = enc_char(text);
    putchar(text);
	text = getchar();

  } 
  printf("End.");
  //getch();
return 0;
}
char enc_char(char c)
{
	
	int cs = check_char(c);
	if (c == 'A' )
	{
		return c+=25;
	}
	else if (c == 'z' || c == 'y')
	{
		return c-=24;
	}
	else if (cs == 1)
	{
		return	c+=2;
	}
	else if (cs == 0)
	{
		return c-=1;
	}
	else if (cs == -1)
	{
		return c;
	}
	
}
int check_char(char c)
{
	int num;
	if (c>=97 && c<=122)
	{
		num = 1;
	}
	else if (c >=65 && c<=106)
	{
		num = 0;
	}
	else 
	{
		num = -1;
	}
	return num;
}

