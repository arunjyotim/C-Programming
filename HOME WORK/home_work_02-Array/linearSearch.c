#include<stdio.h>
#define SIZE 100

// funciton prototype
int linearSearch(const int array[],int key, int size);

// funciton main begins program execution
int main(void)
{
    int a[SIZE];
    int x;
    int searchKey;
    int element;

    //create data
    for( x = 0; x < SIZE; x++){
        a[x] = 2 * x;
    }    

    printf("Enter integer search key;\n");
    scanf("%d", &searchKey);

    //attempt to locate searchKey in array a
    element = linearSearch(a,searchKey, SIZE);

    //display results
    if(element != -1){
        printf("Found value in element %d\n", element);
    }
    else{
        printf("Value not found\n");
    }
    return 0;
}

int linearSearch(const int array[],int key, int size)
{
    int n; //counter
    
    //loop througn array
    for (n = 0; n<size; ++n){

        if (array[n]==key){ 	
            return n; // return location key
        }
    }
     return -1;
}
         
