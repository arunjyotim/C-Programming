#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void main(){
   struct timespec starts,ends;  //struct timespec represents a simple calendar time, or an elapsed time, with sub-second resolution. It is declared in time.h and has the following members: time_t tv_sec. The number of whole seconds elapsed since the epoch (for a simple calendar time) or since some other starting point (for an elapsed time).


/* for directed graph */
   char restart[10];

   do
   {
       /* code */
    int n;
    printf("\n Input the number of vertices: ");
    scanf("%d", &n);
    int i,j;
    int *arr1[n];
        int *inarr,*outarr;
    int in_degree=0,out_degree=0,sum_in_n_out=0;
    
    long long time=0; // long long is used to storge 128 bit (16 byte) of memory storage windows environment. 
    
    /* n=1000 */
    in_degree=0,out_degree=0;
    inarr = (int *)malloc(n * sizeof(int));
    outarr = (int *)malloc(n * sizeof(int));
    /*----------1------------*/
        for (i=0; i<n; i++){
    arr1[i] = (int *)malloc(n * sizeof(int));
    }
    /*----------2------------*/
    for(i=0;i<n;i++){  //n times
        inarr[i]=0;     // constant
        outarr[i]=0;    // constant
        for(j=0;j<n;j++){  //n times
            arr1[i][j]=rand()%2; // constant time * n * n = constant time * n^2 
        }  
        // c*
    }         // total time complexity for this loop is = O(n^2)
    
       /*-----------The added point-----------*///-------------
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr1[i][j]==1&&arr1[j][i]==1)
                {
                    arr1[i][j]=0;
                }
            }
        }

    clock_gettime( CLOCK_REALTIME, &starts) ; //The clock_gettime system call is a successor to the gettimeofday system call with a few key changes: higher precision and the ability to request specific clocks. It fills in a structure containing two fields: a seconds and a nanosecond count of the time since the Epoch (00:00 1 January, 1970 UTC).
   /*----------3------------*/
    /* in degree */
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr1[i][j]==1){
                inarr[i]++;
            }
        }  
    }
    /*----------4------------*/
    /* out degree */
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr1[i][j]==1){
                outarr[j]++;
            }
        }  
    }
    clock_gettime( CLOCK_REALTIME, &ends);
    /*----------5------------*/
    for(i=0;i<n;i++){
        in_degree+=inarr[i];
        out_degree+=outarr[i];
          
    }    

    /* calculate totam in ns */
    time=(ends.tv_sec-starts.tv_sec)*1000000000+(ends.tv_nsec-starts.tv_nsec);
  
// struct timespec	Data Type
// The struct timespec structure represents an elapsed time. It is declared in time.h and has the following members:
// long int tv_sec
// This represents the number of whole seconds of elapsed time.
// long int tv_nsec
// This is the rest of the elapsed time (a fraction of a second), represented as the number of nanoseconds. It is always less than one billion.




    printf("\n Vertices n =%6d \t Sum Of In-degrees: %6d \t Sum Of Out-degrees: %6d\t Computational Time: %ld ns\n",n,in_degree,out_degree,time);

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

