#include <stdio.h>
#include <stdlib.h>

struct employee {
  char name[128];
  float salary;
};

typedef struct employee Employee;
float total_salary(Employee all[], int len);

int main() {
  int num; //number of employees
  int i;
  Employee *all;
  FILE *fp;
  printf("Enter Number : ");
  scanf(" %d",&num);
  
  all=(Employee *)malloc(num*sizeof(Employee));
  
  fp=fopen("employee.bin","wb");
  for(i=0;i<num;i++)
  {
  	fflush(stdin);
  	printf("Enter Name : ");
  	scanf("%[^\n]s",&(all+i)->name);
  	printf("Enter salary : ");
  	scanf(" %f",&(all+i)->salary);
  	fwrite(&all,sizeof(Employee),1,fp);
  }
  fclose(fp);
  
  fp=fopen("employee.bin","rb");
  fread(&all,sizeof(Employee),1,fp);
  for(i=0;i<num;i++)
  {
  	printf("%s:",(all+i)->name);
  	printf("%.1f\n",(all+i)->salary);

  }
  fclose(fp);
  
  printf("=%.1f\n", total_salary(all, num));

  return 0;	
}

float total_salary(Employee all[], int len)
{
	float sum=0;
	int i;
	for(i=0;i<len;i++)
	{
		sum+=(all+i)->salary;
	}
	return sum;
}
