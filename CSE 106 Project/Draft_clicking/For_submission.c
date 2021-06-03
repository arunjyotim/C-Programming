#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void main()
{
   struct timespec starts,ends;  

   char restart[10];

   do
    {
        int n;
        printf("\n\n Input the number of vertices: ");
        scanf("%d", &n);
        int i,j;                           
        int *array[n];
        int *inarr,*outarr;
        int in_degree=0,out_degree=0,sum_in_n_out=0;
        
        long long time=0; 

        in_degree=0,out_degree=0;
        inarr = (int *)malloc(n * sizeof(int));
        outarr = (int *)malloc(n * sizeof(int));

        for (i=0; i<n; i++) 
        {
            array[i] = (int *)malloc(n * sizeof(int)); 
        }

        for(i=0;i<n;i++) 
        {                                                                                                                
            inarr[i]=0;                                                                             
            outarr[i]=0;                                                                            
            for(j=0;j<n;j++) 
            {  
                array[i][j]=rand()%2; 
                if(i==j)
                {
                    array[i][j]=0; 
                };
                
            }  
            
        }   

        clock_gettime( CLOCK_REALTIME, &starts) ; 

        /* in degree */
        for(i=0;i<n;i++) 
        {
            for(j=0;j<n;j++)
            {
                if(array[i][j]==1) 
                {
                    inarr[i]++; 
                }
            }  
        }

        /* out degree */
        for(i=0;i<n;i++)  
        {
            for(j=0;j<n;j++) 
            {
                if(array[j][i]==1) 
                {
                    outarr[j]++;
                }
            }  
        }
        clock_gettime( CLOCK_REALTIME, &ends);

        for(i=0;i<n;i++) 
        {
            in_degree+=inarr[i];
            out_degree+=outarr[i];    
        }    

        printf("\n Vertices n =%6d \t Sum Of In-degrees: %6d \t Sum Of Out-degrees: %6d\n",n,in_degree,out_degree);

        if(in_degree == out_degree)
                printf("\n Sum of in-degrees and out-degrees are equal as %d = %d\n", in_degree,out_degree);
            else    
            {
                printf("\n Sum of in-degrees and out-degrees are not equal.");
            }

    /* Computaional Time calculation */
        time=(ends.tv_sec-starts.tv_sec)*1000000000+(ends.tv_nsec-starts.tv_nsec);
        
        printf("\n Computational Time: %ld ns", time);
      

        printf("\n-----------------------------------------------------------------------------------------------------------\n");
        
        printf("\n Do you want to calculte another vertices? ( y= Yes or n= No )\n Enter (y/n): ");
        scanf("%s",&restart);
    } 
   while (strcmp(restart,"y") == 0);
}