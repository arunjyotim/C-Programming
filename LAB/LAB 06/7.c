#include<stdio.h>
int binary(int *a);
int binary(int *a)
{
    int n[100];
    int i;
    for(i=0;*a>0;i++)
    {
        n[i]=*a%2;
        *a=*a/2;
    }
    printf("\nConverted to binary: ");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",n[i]);
        
    }printf("\n\n");
}
int main()
{
    int num;
    printf("Enter the decimal number: ");
    scanf("%d",&num);
    binary(&num);
    return 0;
}