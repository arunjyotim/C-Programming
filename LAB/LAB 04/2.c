#include<stdio.h>
#include<time.h>
int main()
{
    int a,b,c;
    printf("Enter two numbers: ");
    scanf("%d",&c);
    srand(time(0));
    a=1+rand()%6;
    b=1+rand()%6;
    if(a==c && b==c)
    {
       printf("Win\n");
    }
    else
    {
        printf("Lose\n");
    }

}