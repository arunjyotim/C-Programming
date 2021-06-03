
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"types.h"
#include"phonebook.h"
//#include"utilities.h"

#define MAX_SIZE 100
/* ARRY TO HOLD CONTACTS */
Contact phonebook[MAX_SIZE];

/* Current size of the phonebook array */
int currentSize = 0;


/* ---------------------------------- ENTRY --------------------------- */
void addEntry()
{
    if(currentSize == MAX_SIZE){
        puts("Error: phonebook is full!");
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
/* --------------------------------------------DISPLAY -------------------------------*/
void display(int index)
{
    if(index<0 || index>= currentSize){
        puts("Error: invalid index!");
        return;
    }


    Contact c = phonebook[index];

    printf("First Name: %s\n", c.firstName);
    printf("Last Name : %s\n", c.lastName);
    printf("Mobile Number : %s\n", c.mobileNumber);
}
/* ---------------- Converting entry to lowerCase for better search ---------------*/
/* *
CAUTION:
This function modifies the given string
* */

// void strtolower(char *str)
// {
//     int len = strlen(str);
//     int i;
//     for(i = 0; i<len; i++ ){
//         str[i] = tolower(str[i]);
//     }
// }

/* -------------------------------------- SEARCH --------------------------------*/
void search(char *key, search_t type)
{
    int found = 0,i ;

    strtolower(key); // to lower case the key string
    char content[41];  // to modify the first & last name


    if(type == FIRST_NAME){ // serach by first name
        for( i = 0 ; i<currentSize; i++){

            strcpy(content, phonebook[i].firstName); // coping to the temporary string
            strtolower(content);                     // converting temporary string to lower case
            if(strcmp(content, key) == 0){
                display(i);
                found = 1;
            }
        }
    }
    else if( type == LAST_NAME){ // search by last name
        for(i = 0 ; i<currentSize; i++){

            strcpy(content, phonebook[i].lastName); // coping to the temporary string
            strtolower(content);                    // converting temporary string

            if(strcmp(content, key) == 0){
                display(i);
                found = 1;
            }
        }
    }
    else if ( type == MOBILE_NUMBER){ // search by mobile number
        for(i = 0 ; i<currentSize; i++){

            strcpy(content, phonebook[i].mobileNumber); // coping to the temporary string
            strtolower(content);                    // converting temporary string


            if(strcmp(content, key) == 0){
                display(i);
                found = 1;
            }
        }
    }
    else
    {
        puts("Error: invalid search type!");
        return;
    }

    if(!found){
        puts("NOR FOUND IN THE PHONE BOOK");
    }
}
/* ----------------- READING FROM FILE -----------------*/
void readFromFile()
{
    FILE *fp;
    if((fp = fopen("phonebook.db", "rb")) == NULL){
        puts("Error: Can't load the database file!");
        return;
    }


    /* READ the size of the phonebook*/
    if(fread(&currentSize, sizeof(currentSize), 1,fp) != 1){
        puts("Error: Can't read data!");
        return;
    }

    /* read the actual phonebook content */
    if(fread(phonebook, sizeof(phonebook), 1, fp)!= 1){
        puts("Error: Can't read data!");
        return;
    }
}
/* ---------------------------FOR SAVING IN TO FILE ---------------------*/
void saveToFile()
{
    FILE *fp;
    if((fp = fopen ("phonebook.db", "wb"))== NULL){
        puts("ERROR: Can't create database file!");
        return;
    }

    /* Save the current size of phone book*/
    if (fwrite(&currentSize, sizeof(currentSize), 1, fp) != 1) {  // Writing in to file
        puts("Error: Can't save data!");
        return;
    }
    /* save the phonebook contact's */
    if(fwrite(phonebook,sizeof(phonebook), 1, fp) != 1) {
        puts("Error: Can't save data!");
        return;
    }
}
