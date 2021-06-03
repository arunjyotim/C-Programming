#include<stdio.h>

int Prime(int n, int i);

int main()
{
    int num, prime;
    printf("Enter a integer: ");
    scanf("%d", &num);
    prime = Prime(num, num/2);
    if(prime == 1)
    {
        printf("\n%d is a prime number\n", num);
    }
    else
    {
        printf("\n%d is not a prime number\n", num);
    }
    return 0;
}

int Prime(int n, int i)
{
    if(i == 1)
        return 1; 
    else
    {
        if(n%i == 0)
            return 0;
        else
            Prime(n, i-1); 
    }
}
///  done