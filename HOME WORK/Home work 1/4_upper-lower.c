#include<stdio.h>
int main(){
   char a[100];
   int i;
   printf("Enter the string: ");
   gets(a);
 for ( ; a[i] != '\0';i++){
      if(a[i]>='A'&&a[i]<='Z')
         a[i]=a[i]+32;
   }
   printf("Lower Case : %s",a);
   return 0;
}