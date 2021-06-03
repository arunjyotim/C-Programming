#include<stdio.h>
int Formula(int a[], int n);
int Formula(int a[], int n)
{
    int i,j, store;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(a[j] < a[j+1])
            {
                store=a[j];
                a[j]=a[j+1];
                a[j+1]=store;
            }
        }
    }
}
int main()
{
    int i, num;
    int array[100000];
    printf("Give the size of an array: ");
    scanf("%d", &num);
    
    printf("\nEnter the elements: \n", num);
    for(i=0; i<num; i++)
    {
        scanf("%d", &array[i]);
    }
    
    Formula(array, num);
    printf("Elements sorted in descending order\n\n\n");
    for(i=0; i<num; i++)
    {
        printf("%d  ", array[i]);
    }
}
