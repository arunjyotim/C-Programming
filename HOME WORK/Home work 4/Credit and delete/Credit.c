#include<stdio.h>
int main(void)
{
    int request;
    int account;
    double balance;
    char name[30];
    FILE *cfptr;

    if((cfptr = fopen("clients.dat","r"))=NULL)
    {
        printf("File could not be opened\n");
    }
    else
    {
        printf("Enter request\n"
        "1 - List account with zero balances\n"
        "2 - List account with credit balance\n"
        "3 - List account with debit balances\n"
        "4 - End of run\n?");
        scanf("%d",&request);

        while (request != 4)
        {
            fscanf(cfptr, "%d%s%lf", &account, name, &balance);

            switch (request)
            {
                case 1:
                    printf("\nAccounts with zero balances:\n");
                    while (!feof(cfptr))
                    {
                        if(balance==0)
                        {
                            printf("%-10d%-13s%7.2f\n",account,name, balance);
                        }
                        fscanf(cfptr, "%d%s%lf", &account, name, &balance);
                        }
                    break;

                case 2:
                    printf("\nAccounts with credit balances:\n");
                    while (!feof(cfptr))
                    {
                        if (balance>0)
                        {
                            printf("%-10d%-13s%7.2f\n", account,name,balance);
                        }
                        fscanf(cfptr, "%d%s%lf", &account, name, &balance);
                    }
                    break;
            
            }
            rewind(cfptr);
            printf("\n? ");
            scanf("%d", &request);
        }
        printf("End of run.\n");
        fclose(cfptr);
    }
    return 0;
}