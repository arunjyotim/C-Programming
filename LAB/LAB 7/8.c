#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
    int roll;
    char name[150];
};
int main()
{
    FILE *fptr;
    fptr = fopen("Information.txt","w");

    struct student info[20];

    if(fptr==NULL)
    {
        printf("INVALID FILE!\n");
        exit(1);
    }
    else
    {
        int num, i;
        printf("How many students information you want to store?\n");
        scanf("%d", &num);
        printf("Enter %d students informations below as it appears:\n\n\n",num);
        fflush(stdin);
        for(i=0; i<num; i++)
        {
            printf("Enter student's roll: ");
            scanf("%d", &info[i].roll);
            fflush(stdin);
            printf("Enter student's name: ");
            gets(info[i].name);
            fprintf(fptr,"roll_no = %d;  name = %s\n",info[i].roll,info[i].name);
            printf("\n\n");
            fflush(stdin);
        }
        printf("\n-------INFORMATIONS SAVED SUCCESSFULLY-------\n");
    }
    fclose(fptr);

    FILE *rptr;
    rptr = fopen("Information.txt","r");
    char arr[500];

    if(rptr==NULL)
    {
        printf("  ERROR!  \n");
    }
    else
    {
        printf("\nFILES INFORMATION HAVE SHOWN BELOW\n\n");
        fgets(arr, sizeof(arr), rptr);
        while(!feof(rptr))
        {
            printf("%s", arr);
            fgets(arr, sizeof(arr), rptr);
        }
    fclose(rptr);
    }
}