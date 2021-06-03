#include<stdio.h>
void formula(int *b);

void formula(int *b)
{
    if(*b % 2 != 0)
        printf("The integer is Odd", *b);
    else
        printf("The integer is Even", *b);
}
int main()
{
    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);
    formula(&a);
    printf("\n ---------------------------");
}