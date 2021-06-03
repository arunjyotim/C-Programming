#include<stdio.h>
#include<stdlib.h>
struct books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};
void printBook(struct books *BOOK);
int main()
{
    FILE *fptr;
    fptr=fopen("info.txt","w");
     int num, i;
    printf("---     How many book's information you want to add?     ---\n                    =  ");
    scanf("%d", &num);
     printf("\n");
    struct books BOOK[num];
    fflush(stdin);

    for(i=0; i<num; i++)
    {
        printf("Enter Title: ");
        gets(BOOK[i].title);
        printf("Enter Author: ");
        gets(BOOK[i].author);
        printf("Enter  Subject: ");
        gets(BOOK[i].subject);
        fflush(stdin);
        printf("Enter Book  ID: ");
        scanf("%d", &BOOK[i].book_id);
        fprintf(fptr,"%-15d%-20s%-20s%s\n", BOOK[i].book_id, BOOK[i].title, BOOK[i].author, BOOK[i].subject);
        fflush(stdin);
        printf("\n");
    }
    fclose(fptr);
    printBook(&BOOK[i]);
}


void printBook(struct books *book){

    FILE *read;
    read = fopen("info.txt","r");

    char store[1000];
    int i;

    printf("\n-------FILE INFORMATION-------\n");
    printf("%-20s%-20s%-20s%s\n","ID","Title","Author","Subject");
    fgets(store, sizeof(store), read);
    while(!feof(read))
    {
         printf("%s", store);
         fgets(store, sizeof(store), read);
    }
    fclose(read);
}
