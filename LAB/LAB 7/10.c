#include <stdio.h>
#include<stdlib.h>

int main(){

int num;

FILE *fptr;
fptr= fopen("datasize.dat","w");

if(fptr==NULL)
{
    printf("error at opening!!");
    exit(1);
}

    printf("data type            Size\n\n");
    printf("char                 %d\n", sizeof(char));
    printf("unsigned char        %d\n", sizeof(unsigned char));
    printf("short                %d\n", sizeof(short));
    printf("short int            %d\n", sizeof(short int));
    printf("int                  %d\n", sizeof(int));
    printf("unsigned int         %d\n", sizeof(unsigned int));
    printf("long                 %d\n", sizeof(long));
    printf("unsigned long int    %d\n", sizeof(unsigned long int));
    printf("float                %d\n", sizeof(float));
    printf("double               %d\n", sizeof(double));
    printf("long double          %d\n", sizeof(long double));

    fprintf(" char  %d\n", sizeof(char));
    fprintf(" unsigned char  %d\n", sizeof(unsigned char));
    fprintf(" short  %d\n", sizeof(short));
    fprintf(" short int  %d\n", sizeof(short int));
    fprintf(" int  %d\n", sizeof(int));
    fprintf(" unsigned int  %d\n", sizeof(unsigned int));
    fprintf(" long  %d\n", sizeof(long));
    fprintf(" unsigned long int %d\n", sizeof(unsigned long int));
    fprintf(" float  %d\n", sizeof(float));
    fprintf(" double  %d\n", sizeof(double));
    fprintf(" long double  %d\n", sizeof(long double));
    
    return 0;
}