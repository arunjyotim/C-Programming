#include<stdio.h>
int main()
{
    printf("%d", fun(4));
    return 0;
}                               //6, 7, 8, 9 

int fun(int n)
{
    if(n==0){
        return 1;
    }
    else 
        return 7 + fun(n-2);
}