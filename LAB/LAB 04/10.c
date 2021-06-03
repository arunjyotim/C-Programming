#include <stdio.h>
int qualityPoints(int a);

int main()
{
    int average;

    printf("\nEnter the student's average marks: ");
    scanf( "%d", &average );
    printf(" Grade point average is %d \n", qualityPoints(average));

    return 0;
}

int qualityPoints(int a)
{
    if ( a >= 90 )
    {
        return 4;
    }
    else if ( a>= 80 )
    {
        return 3;
    }
    else if ( a >= 70 )
    {
        return 2;
    }
    else if ( a >= 60 )
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
