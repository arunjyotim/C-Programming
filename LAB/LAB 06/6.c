#include<stdio.h>
int nthTerm( int *a);

int nthTerm(int *a){
*a=*a-1+ *a-2;
}

int main()
{
int b=0,num;
printf("Enter nTh term to find in the fibonacci series:");
scanf("%d",&num);
b=num;
nthTerm(&num);
printf("%dth term is = %d",b,num);
return 0;
}
