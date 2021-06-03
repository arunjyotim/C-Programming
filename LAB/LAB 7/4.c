#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct cars{
char name[50];
char model[50];
int year;
int price;

};
void input(struct cars car);
void output(struct cars car);
int main(){
    FILE *f;
    f=fopen("car.txt","w");
    struct cars car1;
    struct cars car2;
    struct cars car3;
    struct cars car4;
    struct cars car5;

    input(car1);
    input(car2);
    input(car3);
    input(car4);
    input(car5);
    printf("1stcar\n");
    fprintf(f,"1stcar\n");
    output(car1);
    printf("2stcar\n");
    fprintf(f,"2stcar\n");
    output(car2);
    printf("3rdcar\n");
    fprintf(f,"3rdcar\n");
    output(car3);
    printf("4thtcar\n");
    fprintf(f,"4thtcar\n");
    output(car4);
    printf("5thcar\n");
    fprintf(f,"5thcar\n");
    output(car5);

    fclose(f);
}

    void input(struct cars car){
    gets(car.name);
    gets(car.model);
    scanf("%d",&car.year);
    scanf("%d",&car.price);
    }
    void output(struct cars car){
   printf("%s",car.name);
    printf("%s",car.model);
    printf("%c",car.year);
    printf("%c",car.price);
    printf("\n\n");
    fprintf("%s",car.name);
    fprintf("%s",car.model);
    fprintf("%c",car.year);
    fprintf("%c",car.price);

    }