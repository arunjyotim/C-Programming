
#include <stdio.h>
void main()
{
    float power;
    printf("Enter the power: ");
    scanf("%f", &power);
    int acc;
    printf("Enter the accuracy: ");
    scanf("%d", &acc);
    float ans = 1;
    float temp = 1;
    int i;
    for (i = 1; i < acc; i++)
    {
        temp = (temp * power) / i;
        ans = ans + temp;
    }
    printf("\n\n\nWhen power is %f \n\n & accuracy is %d\n\n The Euler's number is %f \n\n\n", power, acc, ans);
}
