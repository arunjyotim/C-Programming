#include <stdio.h>
int maximum(int x, int y, int z); //  Parameter                    | Function declaration or prototype
int main(void)
{
   int number1;
   int number2;
   int number3;

   printf("Enter three numers: ");
   scanf("%d%d%d", &number1, &number2, &number3);

   printf("Maximum is: %d\n", maximum(number1, number2, number3)); // funciton calling
   return 0;
}

int maximum(int x, int y, int z)  //   Argument                  |  function header or prototype
{
   int max = x;
   if (y > max)
   {
      max = y;
   }
   if (z > max)
   {
      max = z;
   }
   return max;
}