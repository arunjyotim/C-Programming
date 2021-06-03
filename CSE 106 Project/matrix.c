

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// generate a random number from 0 to n
int get_random_value(int n)
{
   srand(time(NULL));
   return rand()%n;
}

// function that fills the graph with E number of edges
void func(int V,int E,int graph[][V])
{
   // initialise graph with all zeroes
   for(int i=0;i<V;i++)
   {
       for(int j=0;j<V;j++)
       {
           graph[i][j]=0;
       }
   }
  
   // iterate from 0 to E-1
   for(int i=0;i<E;i++)
   {
       // infinite loop
       while(1)
       {
           // get a random row R and column C
           int R=get_random_value(V);
           int C=get_random_value(V);
          
           // if that cell is not filled(means 0), then execute the following
           if(graph[R][C]==0)
           {
               // get a value and fill the cell and end the infinite loop
               graph[R][C]=get_random_value(V);
               break;
           }
       }
   }
}

// function that calculates the in degree of graph
int in_degree(int V,int graph[][V])
{
   int count=0;
   for(int i=0;i<V;i++)
   {
       for(int j=0;j<V;j++)
       {
           if(graph[i][j])
           {
               count++;
           }
       }
   }
   return count;
}

// function that calculates the out degree of graph
int out_degree(int V,int graph[][V])
{
   int count=0;
   for(int i=0;i<V;i++)
   {
       for(int j=0;j<V;j++)
       {
           if(graph[i][j])
           {
               count++;
           }
       }
   }
   return count;
}

// testing main function
int main()
{
   for(int V=1000;V<=5000;V+=1000)
   {
       int graph[V][V];
       printf("** V = %d **\n",V);
       printf("No. of edges = ");
      
       // read no.of edges count from user
       int E;
       scanf("%d",&E);
      
       // start timer t1
       clock_t t1=clock();
      
       // call function func()
       func(V,E,graph);
      
       // end timer t2
       clock_t t2=clock();
      
       // calculate difference between t2 and t1, to get taken time
       double time_taken=((double)(t2-t1))/CLOCKS_PER_SEC*1000000;
      
       // print results
       printf("Runtime = %.0lf ns\n",time_taken);
       printf("Sum of In Degree = %d\n",in_degree(V,graph));
       printf("Sum of Out Degree = %d\n",out_degree(V,graph));
       printf("\n");
   }
   return 0;
}