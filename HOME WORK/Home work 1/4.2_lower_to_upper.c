#include <stdio.h>
#include <string.h>
int main() {
   char a[1000];
   int i;
   printf("\nEnter a string for converting to upper case : \n");
   gets(a);

   for (i = 0; a[i]!='\0'; i++) {
      if(a[i] >= 'a' && a[i] <= 'z') {
         a[i] = a[i] - 32;
      }
   }
   printf("\nString Converted to upper case:  \n %s", a);
   return 0;
}