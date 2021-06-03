#include<stdio.h>
#include<string.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[5];
    int book_id;
};

int main()
{
    struct Books book[2];
    int i;
    for ( i = 0; i < 2; i++)
    {
        printf("Enter informaiton for Books %d", i+1);
        printf("\nEnter Title: ");
        scanf("%s",&book[i].title);
        printf("Enter Author: ");
        scanf("%s",&book[i].author);
        printf("Enter subject: ");
        scanf("%s",&book[i].subject);
        printf("Enter Book ID: ");
        scanf("%d",&book[i].book_id);
        printf("\n\n",i+1);
    }

    printf("\n\n--------Informaiton for Books-------- \n");
    for ( i = 0; i < 2; i++)
    {

        printf("\nTitle: %s",book[i].title);
        printf("\nAuthor: %s",book[i].author);
        printf("\nSubject: %s"),book[i].subject;
        printf("\nBook ID: %d"),book[i].book_id;
        printf("\n--------------------",i+1);
    }

    getch();

}
