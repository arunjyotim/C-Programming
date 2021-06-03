#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *file;
    file = fopen("numbers.txt", "w");
    int i, num, res, store;
    if(file==NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    else
    {
        printf("Enter how many result you want to store: ");
        printf("\n");
        scanf("%d", &num);
        fflush(stdin);
        for(i=0; i < num; i++)
        {
            printf("Enter records from 1 to 10: ");
            scanf("%d", &res);
            fprintf(file,"%d ", res);
            fflush(stdin);
        }
    }
    fclose(file);

    /* reading from numbers.txt */
    FILE *rfile;
    rfile = fopen("numbers.txt","r");

    int records[30]={0};

    printf("\nReading recordss...\n");


    for(i=0; i<num; i++)
    {
        fscanf(rfile,"%d",&store);
        switch(store)
        {
            case 1:
                records[0]++;
                break;
            case 2:
                records[1]++;
                break;
            case 3:
                records[2]++;
                break;
            case 4:
                records[3]++;
                break;
            case 5:
                records[4]++;
                break;
            case 6:
                records[5]++;
                break;
            case 7:
                records[6]++;
                break;
            case 8:
                records[7]++;
                break;
            case 9:
                records[8]++;
                break;
            case 10:
                records[9]++;
                break;
        }
    }
    fclose(rfile);

     /* Reading and writing records from file 1 & coping to file 2 */
    FILE *nfile;
    nfile = fopen("output.txt","w");
    for(i=0; i<10; i++)
    {
        fprintf(nfile,"Number of responses %2d: %2d\n", i+1, records[i]);
    }

    printf("------------Responses have been recorded in file 2-----------\n");

    fclose(nfile);

    FILE *rNFile;
    rNFile = fopen("output.txt","r");

    char arr[1000];

    printf("\nScanning details from file 2...\n");
    printf("\n");
    for(i=0; i<10; i++)
    {
        fgets(arr, sizeof(arr), rNFile);
        printf("%s", arr);
    }
    fclose(rNFile);
}

