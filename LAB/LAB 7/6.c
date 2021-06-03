#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *file;
    file = fopen("integers.txt","r");

    int arr[300];
    int i=0, j, n=0, hold;

    if(file==NULL)
    {
        printf("Error Occured\n");
        exit(1);
    }
    else
    {
        while(!feof(file))
        {
            fscanf(file, "%d", &arr[i]);
            i++;
            n++;
        }
        printf("----------Sorting from file--------\n");
        for(i=0; i<n; i++)
        {
            for(j=0; j < n-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    hold = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = hold;
                }
            }
        }

        printf("\nAfter sorting from file\n");
        for(i=0; i <n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
    fclose(file);

}

