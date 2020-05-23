#include <stdio.h>
#include <stdlib.h>
#define NUM 5

typedef struct 
{
 	char title[128];
 	char author[128];
 	int price;
} Book;
typedef struct 
{
 	char first_name[128];
 	char last_name[128];
 	Book* books;
 	int book_num;
} Student;

void input_student(Student *s);
void input_book(Book *b);
int total_price(Book *b, int num);
Student* max_total_book_price(Student *s, int num);

int main()
{
	int i;
 	Student students[NUM],* max;
 for(i=0; i<NUM; i++)
 {
 	printf ("Student [%d]\n",i+1);
 	input_student(&students[i]);
	printf("\n");	
 }  
 max = max_total_book_price(students,NUM);
 printf("Students with the most book prices : %s  %s ",max->first_name,max->last_name);
 for(i=0; i<NUM; i++)
 {
 	free(students[i].books);
 }
 
 return 0;
}
void input_student(Student *s)
{
 int i; 
 printf("Enter first name : ");
 scanf(" %[^\n]s", s->first_name);
 printf("Enter last name : ");
 scanf(" %[^\n]s", s->last_name);
 printf("Enter num of book : ");
 scanf(" %d", &s->book_num);
 s->books = (Book *)malloc(s->book_num*sizeof(Book));
 for(i=0; i<s->book_num; i++)
 {
 	printf("Book[%d]\n",i+1);
 	input_book(s->books+i);
 }
 
}
void input_book(Book* b)
{
 printf("Enter book title : ");
 scanf(" %[^\n]s", b->title);
 printf("Enter book author : ");
 scanf(" %[^\n]s", b->author);
 printf("Enter book price : ");
 scanf(" %d", &b->price);
}
int total_price(Book *books, int num)
{
 int total = 0;
 int i;
 for(i=0; i<num; ++i)
 {
 	total += books[i].price;
 }
 return total;
} 

Student* max_total_book_price(Student *s, int num)
{
 int i, price;
 Student* max_s;
 int max_p;
for(i=0; i<NUM; i++)
{
	price = total_price((s+i)->books,(s+i)->book_num);
	if(price > max_p)
	{
		max_p = price;
		max_s = s+i;
	}
}
 return max_s;
} 
