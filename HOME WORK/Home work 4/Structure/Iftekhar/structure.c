#include<stdio.h>
#include<stdlib.h>
struct books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};
int main()
{
    FILE *create;
    create = fopen("bookrecords.txt","w");

    int n, i;
    printf("Enter the number of books to be listed: ");
    scanf("%d", &n);
    struct books book[n];
    fflush(stdin);

    for(i=0; i<n; i++)
    {
        printf("Enter Book %d Title: ", i+1);
        gets(book[i].title);
        printf("Enter Book %d Author: ", i+1);
        gets(book[i].author);
        printf("Enter Book %d Subject: ", i+1);
        gets(book[i].subject);
        fflush(stdin);
        printf("Enter Book %d ID: ", i+1);
        scanf("%d", &book[i].book_id);
        printf("---------------------------\n");
        fprintf(create,"%-10d%-20s%-20s%s\n", book[i].book_id, book[i].title, book[i].author, book[i].subject);
        printf("Info Added Successfully into file\n");
        printf("---------------------------\n");
        fflush(stdin);
    }
    fclose(create);

    FILE *read;
    read = fopen("bookrecords.txt","r");

    char temp[512];

    printf("\nReading from file\n\n");
    printf("%-10s%-20s%-20s%s\n","Bood ID","Title","Author","Subject");
    printf("--------------------------------------------------------------------------\n");
    fgets(temp, sizeof(temp), read);
    while(!feof(read))
    {
        printf("%s", temp);
        fgets(temp, sizeof(temp), read);
    }


}