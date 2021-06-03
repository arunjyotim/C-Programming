#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *records;
    int acNum, i, n;
    char name[50];
    double balance;

    records = fopen("records.dat", "w");

    if(records == NULL)
    {
        printf("Error occured!\n");
        exit(1);
    }
    else
    {
        printf("Enter how many Record You want to enter: ");
        printf("\n\n");
        scanf("%d", &n);
        fflush(stdin);
        for(i=0; i < n; i++)
        {
            printf("Enter name: ");
            gets(name);
            printf("Enter account no: ");
            scanf("%d", &acNum);
            printf("Enter balance: ");
            scanf("%lf", &balance);
            fprintf(records,"%-15d%-15s%.4f\n", acNum, name, balance);
            fflush(stdin);
            printf("\n");
        }
        printf("\n--ENTRY HAS BEEN SAVED--\n");
    }
    fclose(records);

    records = fopen("records.dat","r");
    printf("\n\n-------------Saved file's details------------\n\n");
    printf("%-15s%-15s%s\n", "Account No.","Name","Balance");
    fgets(name, sizeof(name), records);
    while(!feof(records))
    {
        printf("%s", name);
        fgets(name, sizeof(name), records);
    }
    fclose(records);
    return 0;
}


