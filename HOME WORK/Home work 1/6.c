#include <stdio.h>

int main()
{
    char a[1000];
    int i,count;
    printf("Enter a string: ");
    gets(a);
    i = 0;
    count = 1;

    while(a[i] != '\0')
    {
        if(a[i]==' ' || a[i]=='\n' || a[i]=='\t')
        {
            count++;
        }
        i++;
    }

    printf("Number of words = %d", count);

    return 0;
}