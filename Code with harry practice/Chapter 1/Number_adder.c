#include <stdio.h>
void adder();

int main()
{
    adder();
    return 0;
}

void adder()
{
    int a, b, sum;
    printf("Enter two number=\n");
    scanf("%d%d", &a, &b);
    sum = a + b;
    printf("The sum is= %d", sum);
}
