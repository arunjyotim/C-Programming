#include<stdio.h>
#include<stdlib.h>
int main(){
int a;
FILE *fptr;
printf("Enter (-1) to stop: \n");
if((fptr= fopen("Info.txt","w"))==NULL)
    {
    printf("unable to open file!!");
    exit(1);
    }
else{
    scanf("%d",&a);
    while(a!= -1)
    {
        fprintf(fptr,"%d",a);
        scanf("%d",&a);
    }
    fclose(fptr);

}
}
