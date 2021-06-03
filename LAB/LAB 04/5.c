#include <stdio.h>
#include <setjmp.h>
int formula();

jmp_buf buf;
int main() {
   formula();
   return 0;
}

int formula(){
	int n,x = 1;
   printf("Enter how many times you want to print:");
   scanf("%d",&n);
   setjmp(buf); 
   printf("Hello World \n"); 
   x++;
   if (x <= n)
      longjmp(buf, 1); 
}