#ifndef TYPES_H  /* include guarding */
#define TYPES_H

// structure to hold the information of a single contact

typedef struct
{
    char firstName[40];
    char lastName[40];
    char mobileNumber[20];
} Contact;

/* Enumeration is a user defined datatype in C language. It is used to assign names to the integral constants which makes a program easy to read and maintain. The keyword “enum” is used to declare an enumeration. */

// Enumerator for different search types //
typedef enum { FIRST_NAME, LAST_NAME, MOBILE_NUMBER } search_t;

#endif // TYPES_H
