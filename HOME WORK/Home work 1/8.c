#include<stdio.h>

int main(){
   char a[100];
   int i,c=0,n=0;
   printf("Enter the string: ");
   gets(a);
   
 	for ( ; a[i] != '\0';i++)
	 {
      if(a[i]>='A'&&a[i]<='Z'||a[i]>='a'&&a[i]<='z')
	  {
         c++;
      }
      else{
        n++;
      }
   	}
   
	for (i = 0; a[i] != '\0'; ++i)
	{
        ;
    }
	printf("\nThe string's length is: %d", i);
   	printf("\nAlphabets = %d",c);
   	printf("\nNumercial values= %d",n);
   return 0;
}