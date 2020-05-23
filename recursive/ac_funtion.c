#include<stdio.h> 
int ac(int m ,int n);
int main ()
{
    int m_num,n_num ;
    printf("Enter m : ");
    scanf("%d",&m_num);
    printf("Enter n : ");
    scanf("%d",&n_num);
    printf("Ans = %d",ac(m_num,n_num));
    return 0;
}
int ac(int m, int n)
{
    if (m == 0  && n >= 0)
    {
        return n+1;
    }
    else if (m > 0 && n == 0)
    {
        return ac(m-1,1);
    } 
     else if (m > 0 && n > 0)
    {
        return ac(m-1,ac(m,n-1));
    } 
}
