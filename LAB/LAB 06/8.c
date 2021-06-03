#include <stdio.h>
#include <string.h>

void palindr(char c[]);

int main()
{
  	char c[100];

  	printf("\n Please Enter any String :  ");
  	gets(c);

  	palindr(c);

  	return 0;
}

void palindr(char c[])
{
	int z = 0;
	int len = strlen(c) - 1;
    int i;
	while (len > i)
	{
		if(c[i++] != c[len--])
		{
			printf("\n %s is Not Palindrome", c);
			return;
		}
	}
	printf("\n %s Palindrome ", c);
}