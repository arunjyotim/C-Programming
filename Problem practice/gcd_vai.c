#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d",&x);
    y=prime(x);
    return 0;
}

int prime(int a)
{
    if(a%2!=0)
    {
        printf("prime number");

    }
    else
    {
        printf("Not prime");
    }
}