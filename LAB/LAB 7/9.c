#include<stdio.h>
#include<stdlib.h>
struct hardware
{
    int record;
    char toolName[100];
    int quantity;
    double cost;
};
int main()
{
    FILE *fptr;
    fptr = fopen("hardware.dat","w");

    struct hardware list[10];
    int n, i;
    printf("Enter how many hardware's informations your want to keep: ");
    scanf("%d", &n);
    fflush(stdin);

    for(i=0; i < n; i++)
    {
        printf("Record no: ");
        scanf("%d", &list[i].record);
        fflush(stdin);
        printf("Tool name: ");
        gets(list[i].toolName);
        fflush(stdin);
        printf("Quantity: ");
        scanf("%d", &list[i].quantity);
        printf("Cost: ");
        scanf("%lf", &list[i].cost);
        fprintf(fptr, "%-10d%-14s%-14d%-12.2f\n", list[i].record, list[i].toolName, list[i].quantity, list[i].cost);
        printf("\n\n");
        fflush(stdin);
    }
    fclose(fptr);
    FILE *rptr;
    rptr = fopen("hardware.dat","r");
    char r[100];
    if(rptr==NULL)
    {
        printf("ERROR!\n");
        exit(1);
    }
    else
    {
        printf("\n\n----YOUR HARDWARE INFORMATIONS----\n\n");
        printf("%-10s%-14s%-14s%-12s\n","Record","Tool Name","Quantity","Cost");
        while(!feof(rptr))
        {
            fgets(r, sizeof(r), rptr);
            printf("%s", r);
        }
    }
    fclose(rptr);


}
