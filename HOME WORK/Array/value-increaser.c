#include<stdio.h>
#define SIZE 10

int main(void)
{
    int s[SIZE];
    int j;

    printf("%s%12s\n","Element","Value");
    for(j=0;j<SIZE;j++){
        s[j]=2+2*j;
        printf("%d%12d\n",j,s[j]);
    }
    return 0;
    
}