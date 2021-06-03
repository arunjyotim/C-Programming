#include<stdio.h>
#include<string.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};
/* function declaration */

void printBook(struct Books *book);

int main()
{
    struct Books Book1;
    struct Books Book2;
    /*book 1 spec*/

    strcpy(Book1.title, "C programming");
    strcpy(Book1.author, "Nuha Ali");
    strcpy(Book1.subject,"C programming Tutorial");
    Book1.book_id = 6495407;

    /*Book 2 spec */
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Zara Ali");
    strcpy(Book2.subject,"Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    printBook(&Book1);
    printf("\n");
    printBook(&Book2);

    return 0;
}

void printBook(struct Books *book)
{
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book subject: %s\n", book->subject);
    printf("Book book_id:%d\n", book->book_id);
}
