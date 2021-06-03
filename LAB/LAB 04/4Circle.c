#include <stdio.h>
int conditions(int a);
int areas();

int main()
{

   areas();

   return 0;
}
int areas()
{
   float radius, area;
   printf("Enter the radius of circle : ");
   scanf("%f", &radius);

   area = 3.14 * radius * radius;
   printf("Area of circle : %.3f\n\n", area);
   conditions(area);

}

int conditions(int a)
{
    if(a<25)
    {
        printf("Area is less than 25\n\n", a);
    }
    else if(a>25)
    {
        printf("Area is greater than 25\n\n", a);
    }
}
