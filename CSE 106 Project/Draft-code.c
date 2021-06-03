#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
   struct timespec starts,ends;

/* for displaying graph */
int h1,h2,h3,h4,h5;

/* for directed graph */
   int n1=1000,n2=2000,n3=3000,n4=4000,n5=5000;
   int i,j;
   int *arr1[n1],*arr2[n2],*arr3[n3],*arr4[n4],*arr5[n5];
   int *inarr,*outarr;
   int in_degree=0,out_degree=0;
  
   long long time1=0,time2=0,time3=0,time4=0,time5=0;
  
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
  
   printf("\nTotal In-degree: %6d \tTotal Out-degree: %6d\t for input n=%d\n",in_degree,out_degree,n1);
   printf("Total time : %ld ns\n",time1);
  
  
  
//    /* n=2000 */
//    in_degree=0,out_degree=0;
//    inarr = (int *)malloc(n2 * sizeof(int));
//    outarr = (int *)malloc(n2 * sizeof(int));
  
// for (i=0; i<n2; i++){
//    arr2[i] = (int *)malloc(n2 * sizeof(int));
//    }

//    for(i=0;i<n2;i++){
//        inarr[i]=0;
//        outarr[i]=0;
//        for(j=0;j<n2;j++){
//            arr2[i][j]=rand()%2;
//        }  
//    }
  
//    clock_gettime( CLOCK_REALTIME, &starts) ;
//    /* in degree */
//    for(i=0;i<n2;i++){
//        for(j=0;j<n2;j++){
//            if(arr2[i][j]==1){
//                inarr[i]++;
//            }
//        }  
//    }
  
//    /* out degree */
//    for(i=0;i<n2;i++){
//        for(j=0;j<n2;j++){
//            if(arr2[i][j]==1){
//                outarr[j]++;
//            }
//        }  
//    }
//    clock_gettime( CLOCK_REALTIME, &ends);

//    for(i=0;i<n2;i++){
//        in_degree+=inarr[i];
//        out_degree+=outarr[i];
//    }

//    /* calculate totam in ns */
//    time2=(ends.tv_sec-starts.tv_sec)*1000000000+(ends.tv_nsec-starts.tv_nsec);
  
//    printf("\nTotal In-degree: %6d \tTotal Out-degree: %6d\t for input n=%d\n",in_degree,out_degree,n2);
//    printf("Total time : %ld ns\n",time2);
  
  
  
  
//    /* n=3000 */
//    in_degree=0,out_degree=0;
//    inarr = (int *)malloc(n3 * sizeof(int));
//    outarr = (int *)malloc(n3 * sizeof(int));
  
// for (i=0; i<n3; i++){
//    arr3[i] = (int *)malloc(n3 * sizeof(int));
//    }

//    for(i=0;i<n3;i++){
//        inarr[i]=0;
//        outarr[i]=0;
//        for(j=0;j<n3;j++){
//            arr3[i][j]=rand()%2;
//        }  
//    }
  
//    clock_gettime( CLOCK_REALTIME, &starts) ;
//    /* in degree */
//    for(i=0;i<n3;i++){
//        for(j=0;j<n3;j++){
//            if(arr3[i][j]==1){
//                inarr[i]++;
//            }
//        }  
//    }
  
//    /* out degree */
//    for(i=0;i<n3;i++){
//        for(j=0;j<n3;j++){
//            if(arr3[i][j]==1){
//                outarr[j]++;
//            }
//        }  
//    }
//    clock_gettime( CLOCK_REALTIME, &ends);

//    for(i=0;i<n3;i++){
//        in_degree+=inarr[i];
//        out_degree+=outarr[i];
//    }

//    /* calculate totam in ns */
//    time3=(ends.tv_sec-starts.tv_sec)*1000000000+(ends.tv_nsec-starts.tv_nsec);
  
//    printf("\nTotal In-degree: %6d \tTotal Out-degree: %6d\t for input n=%d\n",in_degree,out_degree,n3);
//    printf("Total time : %ld ns\n",time3);
  
  
  
//    /* n=4000 */
//    in_degree=0,out_degree=0;
//    inarr = (int *)malloc(n4 * sizeof(int));
//    outarr = (int *)malloc(n4 * sizeof(int));
  
// for (i=0; i<n4; i++){
//    arr4[i] = (int *)malloc(n4 * sizeof(int));
//    }

//    for(i=0;i<n4;i++){
//        inarr[i]=0;
//        outarr[i]=0;
//        for(j=0;j<n4;j++){
//            arr4[i][j]=rand()%2;
//        }  
//    }
  
//    clock_gettime( CLOCK_REALTIME, &starts) ;
//    /* in degree */
//    for(i=0;i<n4;i++){
//        for(j=0;j<n4;j++){
//            if(arr4[i][j]==1){
//                inarr[i]++;
//            }
//        }  
//    }
  
//    /* out degree */
//    for(i=0;i<n4;i++){
//        for(j=0;j<n4;j++){
//            if(arr4[i][j]==1){
//                outarr[j]++;
//            }
//        }  
//    }
//    clock_gettime( CLOCK_REALTIME, &ends);

//    for(i=0;i<n4;i++){
//        in_degree+=inarr[i];
//        out_degree+=outarr[i];
//    }

//    /* calculate totam in ns */
//    time4=(ends.tv_sec-starts.tv_sec)*1000000000+(ends.tv_nsec-starts.tv_nsec);
  
//    printf("\nTotal In-degree: %6d \tTotal Out-degree: %6d\t for input n=%d\n",in_degree,out_degree,n4);
//    printf("Total time : %ld ns\n",time4);
  
  
  
  
  
//    /* n=5000 */
//    in_degree=0,out_degree=0;
//    inarr = (int *)malloc(n5 * sizeof(int));
//    outarr = (int *)malloc(n5 * sizeof(int));
  
// for (i=0; i<n5; i++){
//    arr5[i] = (int *)malloc(n5 * sizeof(int));
//    }

//    for(i=0;i<n5;i++){
//        inarr[i]=0;
//        outarr[i]=0;
//        for(j=0;j<n5;j++){
//            arr5[i][j]=rand()%2;
//        }  
//    }
  
//    clock_gettime( CLOCK_REALTIME, &starts) ;
//    /* in degree */
//    for(i=0;i<n5;i++){
//        for(j=0;j<n5;j++){
//            if(arr5[i][j]==1){
//                inarr[i]++;
//            }
//        }  
//    }
  
//    /* out degree */
//    for(i=0;i<n5;i++){
//        for(j=0;j<n5;j++){
//            if(arr5[i][j]==1){
//                outarr[j]++;
//            }
//        }  
//    }
//    clock_gettime( CLOCK_REALTIME, &ends);

//    for(i=0;i<n5;i++){
//        in_degree+=inarr[i];
//        out_degree+=outarr[i];
//    }

//    /* calculate totam in ns */
//    time5=(ends.tv_sec-starts.tv_sec)*1000000000+(ends.tv_nsec-starts.tv_nsec);
  
//    printf("\nTotal In-degree: %6d \tTotal Out-degree: %6d\t for input n=%d\n",in_degree,out_degree,n5);
//    printf("Total time : %ld ns\n",time5);
  
  
   /* calculate height within 25 for displaying graph */
   h5=(int)(time5*25/(double)time5);
   h4=(int)(time4*25/(double)time5);
   h3=(int)(time3*25/(double)time5);
   h2=(int)(time2*25/(double)time5);
   h1=(int)(time1*25/(double)time5);
  
  
   printf("\n\n\t\t\tDisplay the graph Time vs N\n\n");
  
   /* display the graph */
   for(i=24;i>=0;i--){
       printf("%10c|",' ');
       if((i+1)<=h1){
           printf("%10c",'*');
       }
       else{
           printf("%10c",' ');
       }
       if((i+1)<=h2){
           printf("%10c",'*');
       }
       else{
           printf("%10c",' ');
       }
       if((i+1)<=h3){
           printf("%10c",'*');
       }
       else{
           printf("%10c",' ');
       }
       if((i+1)<=h4){
           printf("%10c",'*');
       }
       else{
           printf("%10c",' ');
       }
       if((i+1)<=h5){
           printf("%10c",'*');
       }
       else{
           printf("%10c",' ');
       }
       printf("\n");
   }
  
   printf("%9c",' ');
   for(i=60;i>=0;i--){
       printf("-");
   }
  
   printf("\n\n");
   printf("%10c",' ');
  
   printf("%14s","n=1000");
   printf("%10s","n=2000");
   printf("%10s","n=3000");
   printf("%10s","n=4000");
   printf("%10s","n=5000");
  
}