#include <stdio.h>
int main()
{
   char p[1000], q[1000];
   int i,j,count=0;

   printf("Enter 1st string : \n");
   gets(p);

   printf("Enter 2nd string : \n");
   gets(q);

   for (j = 0; p[j] != '\0'; ++j){
        ;}

   for ( ; p[i] != '\0';i++) {
       if(q[i] == p[i]){
        count++;
       }
    }
   if (j == count)
      printf("The strings are equal.\n");
   else
      printf("The strings are not equal.\n");

   return 0;

}