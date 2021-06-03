#include <stdio.h>
#define SIZE 250
int search(int array[], int a, int num, int no);

int search( int array[], int a, int num, int no )
{
    if(array[num]==a)
    {
        return num;
    }
    else if(num==no)
    {
        return -1;
    }
    else
    {
        return search(array, a, num + 1, no);
    }
}

int main()
{
    int a[ SIZE ] , i , n, val;
  	printf("The array is\n");
    for (i=0; i<SIZE; i++ )
    {
        a[i]=3+3*i;
        printf("%d ",a[i]);   
    }


    printf("\n\n Enter the key to search: " );
    scanf("%d", &n );

    val=search(a, n, 0, SIZE-1);

    if(val!=-1)
    {
        printf("Found value in element %d\n", val );
    }
    else
    {
        printf("Not found in any element" );
    }

    return 0;

 }
