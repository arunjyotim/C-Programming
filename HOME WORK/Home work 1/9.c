#include <stdio.h>
#include <string.h>
 
int main()
{
    char a[100], b[25] = {'\0'};
    int i, l = 0, f = 0;
 
    printf("Enter a string \n");
    gets(a);

    for (i = 0; a[i] != '\0'; i++)
    {
        l++;
    }
    printf("The length of the string '%s' = %d\n", a, l);
    for (i = l - 1; i >= 0 ; i--)
    {
        b[l - i - 1] = a[i];
    }
 
    for (f = 1, i = 0; i < l ; i++)
    {
        if (b[i] != a[i])
            f = 0;
    }
    if (f == 1)
       printf ("%s is a palindrome \n", a);
    else
       printf("%s is not a palindrome \n", a);

    return 0;
}