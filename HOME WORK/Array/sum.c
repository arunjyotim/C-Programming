#include<stdio.h>
#define SIZE 10

int main(void){
    int a[SIZE]={1,2,3,4,5,6,7,8,9,10};
    int i;
    int total=0;

    for(i=0;i<SIZE;i++){
        total+=a[i];
    }
    printf("Total fo array element values is %d\n",total);
    return 0;
}