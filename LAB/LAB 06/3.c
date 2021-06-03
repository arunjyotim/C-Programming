#include <stdio.h>

#include <stdlib.h>

int multiplication(int a, int b);

int multiplication(int a, int b)

{

int result=a*b;

return result;

}
int main()
{

int n1,n2,store;
printf("Enter the two number ");
scanf("%d %d",&n1,&n2);
store=multiplication(n1,n2);
printf("The store of these numbers :%d",store);
return 0;

}

