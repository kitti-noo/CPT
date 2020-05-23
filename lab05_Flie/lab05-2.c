#include<stdio.h>
#include<stdlib.h>
struct employee 
{   
	char name[128];   
	float salary; 
}; 
typedef struct employee Employee; 

float total_salary(Employee all[], int len); 

int main() 
{   
	int num,i; //number of employees   
	Employee *all;
	FILE *fp;   
	
	printf("Number of employee : ");
	scanf("%d",&num);
	all = (Employee *)malloc(num*sizeof(Employee));
	// Writing to binary file
/*	if ((fp = fopen("employee.bin","wb")) == NULL)
	{
		printf("File could not be opened\n");
	}
	else
	{
		for (i = 0; i < num; i++)
  	  {
		fflush(stdin);
        printf("Name : ");
        scanf("%[^\n]s",all->name); 
        printf("Salary : ");
        scanf("%f",&all->salary);
        fwrite(all, sizeof(Employee),1,fp);
	  }
    fclose(fp);
	}*/
	
	// Reading from binary file
	if ((fp = fopen("employee.bin","rb")) == NULL)
	{
		printf("File could not be opened\n");
	}
	else
	{
		fread(all, num*sizeof(Employee),1,fp); 
		for (i = 0; i < num; i++)
    	{
        	printf("%s : %.1f \n",(all+i)->name,(all+i)->salary);
    	}	
    fclose(fp);
	}
	printf("= %.1f",total_salary(all,num));
	free(all);
	return 0;  

}
float total_salary(Employee all[], int len)
{
	int i;
	float sum=0;
	for (i=0;i<len;i++)
	{
		 sum += all[i].salary;
	}
	return sum;
}
