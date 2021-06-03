#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fptr;
    fptr = fopen("input.txt","w");
    int n[5];
    int sum = 0 , i;
    if(fptr==NULL)
    {
        printf("Invalid file!\n");
        exit(1);
    }
    else
    {
        printf("Enter 5 integers to calculate their sum:\n ");
        for(i=0; i < 5; i++)
        {
            scanf("%d", &n[i]);
            sum = sum + n[i];
        }
        printf("Sum = %d", sum);
        fprintf(fptr,"Sum = %d", sum);
    }
    fclose(fptr);
}