#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    srand ( time(NULL) );
     
    int n = 1000;
    int adjacencyMatrix[n+1][n+1];
    
    // limits between 1 to 1000 to generate random vertices and make an edge
    int l = 1, u = 1000;

    // in undirected graph this is the max number of edges
    int maxEdges = n*((n-1)/2);
    // generating random number of edges
    int numberOfEdges = (rand() % (maxEdges)) + 1;
    
    // intially there is no edge so adjacency matrix has all 0 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            adjacencyMatrix[i][j] = 0;
    }
    
    // finding the random edges
    for(int i=0;i<numberOfEdges;i++) {
        
        // generating two random vertex to make an edge
        int v = (rand() % (u - l + 1)) + l;
        int w = (rand() % (u - l + 1)) + l;    

        // making the undirected graph in adjacency matrix
        adjacencyMatrix[v][w] = 1;
        adjacencyMatrix[w][v] = 1;                                    
    }
    
    // printing the adjacency matrix
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            printf("%d ", adjacencyMatrix[i][j]);
        printf("\n");
    }
    return 0;
}