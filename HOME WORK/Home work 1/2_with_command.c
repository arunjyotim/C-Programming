#include <stdio.h>
#include <string.h>
int main()
{
  char a[500], b[500];
  
  printf("Enter 1st string: ");
  gets(a);

  printf("Enter 2nd string: ");
  gets(b);
  strcat(a, b);
  printf("\n Merged strin: %s\n", a);

  return 0;
}