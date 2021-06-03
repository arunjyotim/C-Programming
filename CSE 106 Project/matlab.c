#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void main(){
   struct timespec starts,ends;  //struct timespec represents a simple calendar time, or an elapsed time, with sub-second resolution. It is declared in time.h and has the following members: time_t tv_sec. The number of whole seconds elapsed since the epoch (for a simple calendar time) or since some other starting point (for an elapsed time).


/* for directed graph */
   char confirm[10];

   do
   {
       /* code */
    int n1;
    //printf("\n-----  -------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------\n");
    printf("\n Input the number of vertices: ");
    scanf("%d", &n1);
    int i,j;
    int *arr1[n1];
        int *inarr,*outarr;
    int in_degree=0,out_degree=0;
    
    long long time1=0; // long long is used to storge 128 bit (16 byte) of memory storage windows environment. 
    
    /* n=1000 */
    in_degree=0,out_degree=0;
    inarr = (int *)malloc(n1 * sizeof(int));
    outarr = (int *)malloc(n1 * sizeof(int));
    
        for (i=0; i<n1; i++){
    arr1[i] = (int *)malloc(n1 * sizeof(int));
    }

    for(i=0;i<n1;i++){  //n times
        inarr[i]=0;     // constant
        outarr[i]=0;    // constant
        for(j=0;j<n1;j++){  //n times
            arr1[i][j]=rand()%2; // constant time * n * n = constant time * n^2 
        }  
        // c*
    }         // total time complexity for this loop is = O(n^2)
    
    clock_gettime( CLOCK_REALTIME, &starts) ; //The clock_gettime system call is a successor to the gettimeofday system call with a few key changes: higher precision and the ability to request specific clocks. It fills in a structure containing two fields: a seconds and a nanosecond count of the time since the Epoch (00:00 1 January, 1970 UTC).
    /* in degree */
    for(i=0;i<n1;i++){
        for(j=0;j<n1;j++){
            if(arr1[i][j]==1){
                inarr[i]++;
            }
        }  
    }
    
    /* out degree */
    for(i=0;i<n1;i++){
        for(j=0;j<n1;j++){
            if(arr1[i][j]==1){
                outarr[j]++;
            }
        }  
    }
    clock_gettime( CLOCK_REALTIME, &ends);

    for(i=0;i<n1;i++){
        in_degree+=inarr[i];
        out_degree+=outarr[i];
    }

    /* calculate totam in ns */
    time1=(ends.tv_sec-starts.tv_sec)*1000000000+(ends.tv_nsec-starts.tv_nsec);
  
    printf("\n Input n= %d\t Total In-degree: %6d \tTotal Out-degree: %6d\t Total time: %ld ns\n",n1,in_degree,out_degree,time1);

    printf("\n-----------------------------------------------------------------------------------------------------------\n");

    
    printf("\n Do you want to calculte another vertices? ( y= Yes or n= No )\n Enter (y/n): ");
    scanf("%s",&confirm);

   } 
   while (strcmp(confirm,"y") == 0);  
}