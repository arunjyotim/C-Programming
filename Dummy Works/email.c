#include<stdio.h>
#include<string.h>

void email(struct phonebook *name)
{
    char name[30];
    char gmail[11] = "@gmail.com";
    char yahoo[11] = "@yahoo.com";
    char otl[13] = "@outlook.com";
    int i,j,len;
    printf("Enter your email address: ");
    gets(name);
    len = strlen(name);
    printf("Choose one of the domain:\n");
    printf("1. @gmail.com\n");
    printf("2. @yahoo.com\n");
    printf("3. @outlook.com\n");
    scanf("%d",&i);
    switch (i)
    {
    case 1:
        for(i=len , j=0 ; gmail[j]!= '\0'; j++, i++){
            name[i]= gmail[j];
        }
        name[i] = '\0';
        printf("%s\n", name);
        break;
    case 2:
        for(i=len , j=0 ; yahoo[j]!= '\0'; j++, i++){
            name[i]= yahoo[j];
        }
        name[i] = '\0';
        printf("%s\n", name);
        break;
    case 3:
        for(i=len , j=0 ; otl[j]!= '\0'; j++, i++){
            name[i]= otl[j];
        }
        name[i] = '\0';
        printf("%s\n", name);
        break;
    
    default:
        printf("Wrong choice!");
        break;
    }
}