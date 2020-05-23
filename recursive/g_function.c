#include<stdio.h> 
int g(int n);
int main ()
{
    int num ;
    printf("Enter positive number : ");
    scanf("%d",&num);
    if (num > 0)
    {
        printf("Ans : %d",g(num));
    }
    else
    {
        printf("Not positive number");
    }
    
    return 0;
}
int g(int n)
{
    if (n > 100)
    {
        return n-10;
    }
    else
    {
        return g(g(n+11));
    } 
}
