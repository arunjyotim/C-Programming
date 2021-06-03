#include <stdio.h>
int maximum(int x, int y, int z);
int minimum(int a, int b, int c);
int main(void)
{
   int number1;
   int number2;
   int number3;

   printf("Enter three numers: ");
   scanf("%d%d%d", &number1, &number2, &number3);

   printf("Maximum is: %d\n", maximum(number1, number2, number3));
   printf("Minimum is: %d\n", minimum(number1, number2, number3));
   return 0;
}
int minimum(int a, int b, int c)
{
   int min = a;
   if (b < min)
   {
      min = b;
   }
   if (c < min)
   {
      min = c;
   }
   return min;
}
int maximum(int x, int y, int z)
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