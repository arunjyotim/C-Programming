#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,Count=0;
    char x[100];
    char y[100];

    printf("Write 1st String: ");
    gets(x);
    printf("Write 2nd string: ");
    gets(y);

    for(i=0; x[i]!='\0'; i++)
        Count++;
    for(i=Count, j=0; y[j]!='\0'; j++, i++)
    {
        x[i]=y[j];
    }
    x[i]='\0';
    printf("\nMerged String: %s\n\n", x);

    return 0;
}

