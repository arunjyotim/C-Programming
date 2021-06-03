#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void main(){
   struct timespec starts,ends; 


/* for directed graph */
   char confirm[10];

   do
   {
       /* code */
    int n1;
    printf("\n Input the number of vertices: ");
    scanf("%d", &n1);
    int i,j;
    int *arr1[n1];
        int *inarr,*outarr;
    int in_degree=0,out_degree=0;
    
    long long time1=0; 
    
    /* n=1000 */
    in_degree=0,out_degree=0;
    inarr = (int *)malloc(n1 * sizeof(int));
    outarr = (int *)malloc(n1 * sizeof(int));
    
        for (i=0; i<n1; i++){
    arr1[i] = (int *)malloc(n1 * sizeof(int));
    }

    for(i=0;i<n1;i++){  
        inarr[i]=0;
        outarr[i]=0;
        for(j=0;j<n1;j++){  
            arr1[i][j]=rand()%2; 
        }  
    }         
    
    clock_gettime( CLOCK_REALTIME, &starts) ; 
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

    printf("\n Do you want to calculte another vertices? ( y= Yes or n= No )\n Enter (y/n): ");
    scanf("%s",&confirm);

   } 
   while (strcmp(confirm,"y") == 0);
   
}

