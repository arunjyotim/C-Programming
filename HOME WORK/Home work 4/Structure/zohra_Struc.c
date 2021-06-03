#include<stdio.h>
#include<string.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[5];
    int book_id;
};
void printBook(struct Books *book);

int main()
{
    struct Books book[10];
    int i,n;
    
    for(i=1;i<=10;i++){

       printf("Enter Title: ");
        gets(book[i].title);
        printf("Enter Author: ");
        gets(book[i].author);
        printf("Enter subject: ");
        gets(book[i].subject);
        printf("Enter Book ID: ");
        scanf("%d",&book[i].book_id);
         printf("\n");
    }
    for(i=0;i<10;i++){

        printf("printing book %d\n",i+1);
        printBook(&book[i]);
        printf("\n");
    }

}
void printBook(struct Books *book){

    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book subject: %s\n", book->subject);
    printf("Book book_id:%d\n", book->book_id);
}