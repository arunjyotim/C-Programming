#include <stdio.h>
int maximum();//  Parameter                    | Function declaration or prototype
int main(void)
{
    maximum();// funciton calling
   return 0;
}

int maximum()  // |  function header or prototype
{
   int x;
   int y;
   int z;

   printf("Enter three numers: ");
   scanf("%d%d%d", &x, &y, &z);

   int max = x;
   if (y > max)
   {
      max = y;
   }
   if (z > max)
   {
      max = z;
   }
  printf("Maximum number is: %d\n", max);

}