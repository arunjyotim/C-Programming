#include <stdio.h>

void main()
{
    int arr1[100];
    int n, i, j, tmp;


    printf("Enter how many countries average temparature you want to input from last 10 years : ");
    scanf("%d", &n);

       printf("Input %d temparature :\n",n);
       for(i=0;i<n;i++)
            {
	      printf("Country - %d  : ",i);
	      scanf("%d",&arr1[i]);
	    }

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr1[j] <arr1[i])
            {
                tmp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = tmp;
            }
        }
    }
    printf("\nCountries temparature increased in accending order from recent years:\n");
    for(i=0; i<n; i++)
    {
        printf("%d  ", arr1[i]);
    }
	        printf("\n\n");
}
