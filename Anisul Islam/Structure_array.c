#include<stdio.h>

struct Person
{
    int age;
    float salary;
};
int main()
{
    struct Person person[5];
    int i;


    for ( i = 0; i < 5; i++)
    {
        printf("Enter the information for person: %d", i+1);
        printf("\nEnter age :");
        scanf("%d",&person[i].age);
        printf("Enter salary :");
        scanf("%f",&person[i].salary);
    }
    for ( i = 0; i < 5; i++)
    {
        printf("\n------Information for person-------- %d\n", i+1);
        printf("Enter age %d\n", person[i].age);

        printf("Enter salary %f\n", person[i].salary);
    }


    getch();

}
