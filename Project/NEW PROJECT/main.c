#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#include "types.h"
#include "phonebook.h"

extern int currentSize;


/*--------------------------- main -------------------------------*/

int main()
{
    char selection[20];
    int choice, i;
    while (1)
    {

    puts("Phonebook application main menu.");

    puts("      1. Insert New Entry");
    puts("      2. Display All Entry");
    puts("      3. Search by First name");
    puts("      4. Search By last name");
    puts("      5. Search By mobile number");
    puts("      6. Delete a contact (by Mobile Number) ");
    puts("      7. Save DataBase");
    puts("      8. Exit");
    do{
        printf("Enter your choice: ");
        gets(selection);
        choice = atoi(selection); //The atoi() function in C takes a string (which represents an integer) as an argument and returns its value of type int. So basically the function is used to convert a string argument to an integer. ... If no valid conversion takes place, then the function returns zero.

    }while (choice<1 || choice>8);

    switch (choice)
    {
    case 1:
        addEntry();
        break;
    case 2:

        for ( i = 0; i < currentSize; i++)
        {
            display(i);
            puts("");  // extrea new line
        }

        break;
    case 3:
        printf("Enter first name to search: ");
        gets(selection);
        search(selection, FIRST_NAME);
        break;
    case 4:
        printf("Enter last name to search: ");
        gets(selection);
        search(selection, LAST_NAME);
        break;
    case 5:
        printf("Enter mobile number to search: ");
        gets(selection);
        search(selection, MOBILE_NUMBER);
        break;
    case 6:
        break;
    case 7:
        saveToFile();
        break;
    case 8:
        exit(0);
        break;

    default:
        break;

    }

    display(0);

    }



    return 0;
}

