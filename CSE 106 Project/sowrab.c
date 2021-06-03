#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void main()
{
    clock_t start,end;

    /* for directed graph */
    char restart[10];

    do
    {  /*-----code------- */
        int n;
        printf("\n Input the number of vertices: ");
        scanf("%d", &n);
        int i,j;
        int *arr[n];
        int *inarr,*outarr;
        int in_degree=0,out_degree=0,sum_in_n_out=0;

        double time=0; 
    /*-------------Input Calculation----------------- */
        in_degree=0,out_degree=0;
        inarr = (int *)malloc(n * sizeof(int));
        outarr = (int *)malloc(n * sizeof(int));
    /*----------1------------*/
        for (i=0; i<n; i++)
        {
            arr[i] = (int *)malloc(n * sizeof(int));
        }
        start=clock();
    /*----------2------------*/
        for(i=0;i<n;i++)
        {  
            inarr[i]=0;     
            outarr[i]=0;    
            for(j=0;j<n;j++) 
            {      
                arr[i][j]=rand()%2; 
            }         
        }         

    /*-----------The added point-----------*///-------------
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]==1&&arr[j][i]==1)
                {
                    arr[i][j]=0;
                }
            }
        }
    /*----------3------------*/
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]==1)
                {
                    inarr[i]++;
                }
            }
        }
       /*----------4------------*/
     /* ---------out degree-------- */
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]==1)
                {
                    outarr[j]++;
                }
            }
        }
            end=clock();
    /*----------5------------*/
        for(i=0;i<n;i++)
        {
            in_degree+=inarr[i];
            out_degree+=outarr[i];
        }

    /* -----------------Computational time calculation------------------------- */
        time=((double)(end-start)/CLOCKS_PER_SEC)*(1000000000);


        printf("\n Vertices n =%6d \t Sum Of In-degrees: %6d \t Sum Of Out-degrees: %6d\t Computational Time: %1f ns\n",n,in_degree,out_degree,time);

            if(in_degree == out_degree)
                printf("\n Sum of in-degrees and out-degrees are equal as %d = %d", in_degree,out_degree);
            else
            {
                printf("\n Sum of in-degrees and out-degrees are not equal.");
            }

        printf("\n-----------------------------------------------------------------------------------------------------------\n");


        printf("\n Do you want to calculte another vertices? ( y= Yes or n= No )\n Enter (y/n): ");
        scanf("%s",&restart);
    }
   while (strcmp(restart,"y") == 0);
}
