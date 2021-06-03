#include <stdio.h>
int Merged(int *ArrayB, int counter1, int *ArrayS, int counter2);


int main()
{
    int ArrayB[13] = {10, 12, 14, 16, 18, 20, 22};
    int ArrayS[6] = {11, 13, 15, 17, 19, 21};
    int i;

    printf("The given Large Array is :  ");
    for (i = 0; i < 7; i++)
    {
        printf("%d  ", ArrayB[i]);
    }
    printf("\n");

    printf("The given Small Array is :  ");
    for (i = 0; i < 6; i++)
    {
        printf("%d  ", ArrayS[i]);
    }
    printf("\n");

    Merged(ArrayB, 7, ArrayS, 6);
    printf("After merged the new Array is :\n");
    for (i = 0; i < 13; i++)
    {
        printf("%d ", ArrayB[i]);
    }
    return 0;
}

void Merged(int *ArrayB, int counter1, int *ArrayS, int counter2)
{
    if (ArrayB == NULL || ArrayS == NULL)
        return;
    int InputB = counter1 - 1,
        InputS = counter2 - 1,
        Final = counter1 + counter2 - 1;
    while (InputB >= 0 && InputS >= 0)
    {
        if (ArrayB[InputB] >= ArrayS[InputS])
        {
            ArrayB[Final] = ArrayB[InputB];
            Final--;
            InputB--;
        }
        else
        {
            ArrayB[Final] = ArrayS[InputS];
            Final--;
            InputS--;
        }
    }
    if (InputB < 0)
    {
        while (InputS >= 0)
        {
            ArrayB[Final] = ArrayS[InputS];
            Final--;
            InputS--;
        }
    }
    else if (InputS < 0)
    {
        while (InputB >= 0)
        {
            ArrayB[Final] = ArrayB[InputB];
            Final--;
            InputB--;
        }
    }
}