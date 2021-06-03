#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

/* Structure */
typedef struct
{
    char firstName[40];
    char lastName[40];
    char mobileNumber[40];
} Contact;

/* Array data structure for holding contact informantion */

Contact phonebook[MAX_SIZE];

/* Current size of the phonebook array --------- global variable */

int currentSize = 0;

/* Function to input information from user { Function prototype} */

void addEntry();
void display(int index); /* Function to display inputs */
void search(char *key, int type);

/*------------------------------------------------------------main--------------------------------------------------------------*/
int main()
{

    addEntry();
    display(0);

    search("Sakib", 1); // search by last name
    search("123", 2); // search by mobile number

    // addEntry();
    // display(1);
    return 0;
}

void addEntry()
{
    /* to avoid max entry limitation */
    if ( currentSize == MAX_SIZE)
    {
        puts("Error: Phonebook is full!");
        return;
    }

    Contact c;
    printf("Enter First Name: ");
    gets(c.firstName);
    printf("Enter Last Name: ");
    gets(c.lastName);
    printf("Enter Mobile Number: ");
    gets(c.mobileNumber);

    phonebook[currentSize] = c;
    ++currentSize;
}

void display(int index)
{
    /* -----to avoid input limitaion --------- */

    if(index < 0 || index >= currentSize)
    {
        puts("Error: Invalid index!");
        return;
    }

    Contact c = phonebook[index];
    printf("First Name: %s\n", c.firstName);
    printf("Last Name: %s\n", c.lastName);
    printf("Mobile No: %s\n", c.mobileNumber);
}

void search(char *key, int type)
{

    int found = 0;
    int i;
    if(type == 0) // search by first name
    {
        for( i =0; i<currentSize; i++)
        {
            if(strcmp(phonebook[i].firstName, key) == 0);               // compare funtion for comparing with the key
            display(i);
            found = 1;
        }
    }
    else if (type == 1) // search by last name
    {
        for( i =0; i<currentSize; i++)
        {
            if(strcmp(phonebook[i].lastName, key) == 0);               // compare funtion for comparing with the key
            display(i);
            found = 1;
        }
    }
    else if(type == 2) // search by mobile number
    {
        for( i =0; i<currentSize; i++)
        {
            if(strcmp(phonebook[i].mobileNumber, key) == 0);               // compare funtion for comparing with the key
            display(i);
            found = 1;
        }
    }
    else
    {
        puts("Error: invalid search type!");
        return;
    }
    if ( !found)
    {
        puts("Not found in the phone book");
    }

}