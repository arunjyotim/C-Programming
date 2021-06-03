#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *file;
    file = fopen("ToDoList.txt","w");
    int num, i;
    char input[100];

    if(file==NULL)
    {
        printf("Invalid file!\n");
        exit(1);
    }
    else
    {
        printf("How many lines you want to write?\n Ans =  ");
        scanf("%d", &num);
        printf("Note down %d lines below:\n",num);
        for(i=0; i<=num; i++)
        {
            fgets(input, sizeof(input), stdin);
            fprintf(file,"%s", input);
        }
        printf("--------------------------------");
        printf("\n       Your note is saved.\n");
        printf("--------------------------------");
    fclose(file);
    }
}

