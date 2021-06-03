#include<stdio.h>
#include<string.h>
int main()
{
    char s[100], a;
    int i, counter=0;

    printf("Enter a string: ");
    fgets(s, 100, stdin);
    printf("Enter a character to search: ");
    scanf("%c", &a);
  
    printf("'%c' found in ", a);
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]==a)
        {
            counter++;
            printf("index[%d] ", i);
        }
    }
    if(counter!=0)
    {
        printf("locations %d times\n", counter);
    }
    else
    {
        printf("no where\n");
    }

    return 0;
}


