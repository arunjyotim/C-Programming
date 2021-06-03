#include<stdio.h>
#define PI 3.1416
                                              //  x^2 ==0.273529    temp == -0.1367645   ans =  0.8632355
void main()
{
    printf("Enter angle in degree: \n");
    float angle_degree;
    scanf("%f", &angle_degree);
    //         x
    float angle_radian = angle_degree * PI /180;
    float ans = 1;
    float temp = 1;
    int acc = 3;
    int i;
    for ( i = 1; i <= 2* acc; i+=2)
    { //       1(sign)                   x^2            2!
        temp = temp*(-1)*angle_radian*angle_radian/(i*(i+1));
        ans = ans + temp ;
    }
    printf("cos(%f)= %f\n", angle_degree,ans);
}

