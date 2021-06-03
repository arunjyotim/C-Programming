#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *file1;
    FILE *file2;
    int account, i, num;
    char name[30];
    float balance;

    file1 = fopen("oldmast.txt", "w");

    if(file1 == NULL)
    {
        printf("Error storing data!\n");
        exit(1);
    }
    else
    {   
        printf("Enter the amount of account data you want to store in Master file: ");
        scanf("%d", &num);
        fflush(stdin);
        for(i=0; i < num; i++)
        {
            printf("\nEnter name: ");
            gets(name);
            printf("Enter account no: ");
            scanf("%d", &account);
            printf("Enter balance: ");
            scanf("%lf", &balance);
            fprintf(file1,"%-15d%-15s%.3f\n", account, name, balance);
            fflush(stdin);
            printf("\n");
        }
        printf("\n--ALL DATA HAVE BEEN STORED IN MASTER FILE --\n\n");

    }
    fclose(file1);

    int num2;
    file2 = fopen("trans.txt", "w");
    if(file1 == NULL)
    {
        printf("Error storing data!\n");
        exit(1);
    }
    else
    {
        printf("\nEnter the amount of account number you want to store in Transaction list: ");
        scanf("%d", &num2);
        fflush(stdin);
        for(i=0; i < num2; i++)
        {
            printf("\nEnter account number: ");
            scanf("%d", &account);
            printf("Enter transaction amount: ");
            scanf("%lf", &balance);
            fprintf(file1,"%-15d%.3f\n", account, balance);
            fflush(stdin);
            printf("\n");
        }
        printf("\n-- ALL INFO HAVE BEEN STORED IN TRANSACTION FILE --\n\n");
    }
    fclose(file2);
    return 0;
}

