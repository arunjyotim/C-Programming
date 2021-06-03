#include <stdio.h>
#include <string.h>
int main()
{
  char a[500], b[500];

  printf("Enter a string\n");
  gets(a);
  strcpy(b, a);
  printf("Entered string %s\n", a);
  printf("Copied string: %s\n", b);
  
  return 0;
}