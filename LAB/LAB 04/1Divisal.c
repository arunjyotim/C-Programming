#include<stdio.h>
int divisible(int num1, int num2);

int main()
{
    int num1, num2;
    printf("Enter range numbers: ");
    scanf("%d%d", &num1, &num2);
    divisible(num1,num2);
}

int divisible(int num1, int num2)
{
    int i, count1=0, count2=0;
    for (i = num1; i < num2; i++)
    {
        if (i % 5 == 0)
        {
            count1++;
        }
        if(i % 7 == 0)
        {
            count2++;
        }
    }
    printf("Number of integers divisible by 5 between %d and %d = %d\n", num1, num2, count1);
    printf("Number of integers divisible by 7 between %d and %d = %d\n", num1, num2, count2);
}
