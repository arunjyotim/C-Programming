#include <stdio.h>
int main()
{
    int array[20], i, j = 0;
    
    printf("Input numbers for the array:\n");
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &array[i]);
    }
    
    for (i = 0; i < 20; i++)
    {
        if (array[i] == array[i + 1])
        {
            j++;
        }
    }
	
    if (j == 0)
        printf("\n The array has no duplicate numbers. ");
    else
        printf("The array has duplicate numbers");
}