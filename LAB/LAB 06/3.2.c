#include<stdio.h>
#include<conio.h>
int main()
{
 int num1,num2,mul,*p1,*p2;
 printf("Enter 1st number: ");
 scanf("%d",&num1);
 printf("Enter 2nd number: ");
 scanf("%d",&num2);
 p1=&num1;
 p2=&num2;
 mul=*p1**p2;
 printf("\n\nProduct of %d and %d is %d",*p1,*p2,mul);
 getch();
}