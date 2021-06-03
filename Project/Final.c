#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
struct phonebook
{
    char fullname[35];
    char add[50];
    char f_name[35];
    char m_name[30];
    char contact_no[11];
    char gender[8];
    char email_add[100];
    char postal_code[20];
};
void menu();
void strt();
void bck();
void add_info();
void list_info();
void update_info();
void delete_info();
void search_info();
void copycontact();
void copiedcontact();
void favcontact();
void favlist();


/*-----------------------------------------Main--------------------------------*/
int main()
{
    system("color 5f");
    strt();
    return 0;
}
void bck()
{
    strt();
}
void strt()
{
    menu();
}

/*------------------------------------------Menu---------------------------------*/
void menu()
{
    system("cls");
    printf("\t*********************************WELCOME TO MY PHONEBOOK*********************************");

    printf("\n\n\t\t\t\t MENU \t\t\t\t\t\t\t\t\t\n\n");
    printf("\t1.Add New   \t2.List   \t3.Exit  \t4.Modify\n \t5.Search\t6.Delete\t7.Copy Contact\t8.Copied Contact\n\t9.Add Favourite\t\t\t0.Favourites\n\n");

    switch (getch())
    {
    case '1':

        add_info();
        break;
    case '2':
        list_info();
        break;
    case '3':
        exit(0);
        break;
    case '4':
        update_info();
        break;
    case '5':
        search_info();
        break;
    case '6':
        delete_info();
        break;
    case '7':
        copycontact();
        break;
    case '8':
        copiedcontact();
        break;
    case '9': favcontact();
        break;
    case '0': favlist();
        break;
    default:

        menu();
    }
}

/*-------------------------------------------Add Information------------------------*/
void add_info()
{
    system("cls");
    FILE *files;
    struct phonebook x;

    files = fopen("project.txt", "ab+");

    int m;
    char g[] = "@gmail.com";
    char y[] = "@yahoo.com";
    char o[] = "@outlook.com";

    printf("\n Enter Name: ");
    gets(x.fullname);
    fflush(stdin);
    printf("\nEnter the Address: ");
    gets(x.add);
    fflush(stdin);
    printf("\nEnter Father's Name: ");
    gets(x.f_name);
    fflush(stdin);
    printf("\nEnter Mother's Name: ");
    gets(x.m_name);
    fflush(stdin);
    printf("\nEnter Contact Number:");

    for (;;)
    {
        gets(x.contact_no);
        if (strlen(x.contact_no) <= 11)
            break;
        else
            printf("More then 11 numbers!   Input again: \n");
    }

    fflush(stdin);
    printf("\nEnter Gender:");
    gets(x.gender);
    fflush(stdin);
    printf("\nEnter Email Address Till @:");
    gets(x.email_add);

    printf("choose : \n 1. Gmail \n 2. Yahoo \n 3. Outlook \n");
    scanf("%d", &m);

    if (m == 1)
    {
        strcat(x.email_add, g);
    }
    if (m == 2)
    {
        strcat(x.email_add, y);
    }
    if (m == 3)
    {
        strcat(x.email_add, o);
    }
    puts(x.email_add);

    fflush(stdin);
    printf("\nEnter Postal Code:");
    gets(x.postal_code);
    fflush(stdin);
    fwrite(&x, sizeof(x), 1, files);

    fflush(stdin);
    printf("\nNew Record Has Been Successfully Saved");

    fclose(files);

    printf("\n\nEnter any key");

    getch();
    system("cls");
    menu();
}

/*----------------------------------------------Contact list---------------------------------*/
void list_info()
{

    FILE *files;
    struct phonebook x;
    system("cls");
    files = fopen("project.txt", "rb+");
    fflush(stdin);
    if (files == NULL)
    {
        printf("\nfile opening error in listing :");
        printf("\n Enter any key");
        getch();

        menu();
    }
    printf("\n%90s\n\n\n","CONTACT LIST");
    printf("\n   %-20s%-30s%-20s%-20s%-20s%-10s%-30s%s\n", "Name", "Address", "Father's Name", "Mother's Name", "Contact NO.", "Gender", "E-mail", "Postal Code");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (fread(&x, sizeof(x), 1, files) == 1)
    {
        printf("    %-20s%-30s%-20s%-20s%-20ld%-10s%-30s%s\n", x.fullname, x.add, x.f_name, x.m_name, x.contact_no, x.gender, x.email_add, x.postal_code);

    }
    fclose(files);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}

/*-------------------------------------Searching-----------------------------------*/
void search_info()
{
    struct phonebook x;
    FILE *files;
    char name[100];

    files = fopen("project.txt", "rb");
    if (files == NULL)
    {
        printf("\n error in opening\a\a\a\a");
        exit(1);
    }
    printf("\nEnter the Name of Person you want to Search\n");
    gets(name);
    fflush(stdin);
    while (fread(&x, sizeof(x), 1, files) == 1)
    {
        if (strcmp(x.fullname, name) == 0)
        {
            printf("\n\tDetail Information About %s", name);

            printf("\nName        : %s\nAddress     : %s\nFather name : %s\nMother name : %s\nMobile no   : %ld\nGender      : %s\nE-mail      : %s\nPostal Code :%s", x.fullname, x.add, x.f_name, x.m_name, x.contact_no, x.gender, x.email_add, x.postal_code);
        }
        else
            printf("file not found");
    }
    fflush(stdin);
    fclose(files);
    printf("\n Enter any key");

    getch();
    system("cls");
    menu();
}

void delete_info()
{
    struct phonebook x;
    FILE *files, *file_temp;
    int fl;
    char name[100];
    files = fopen("project.txt", "rb");
    if (files == NULL)
    {

        printf("CONTACT'S DATA NOT ADDED YET.");
    }
    else
    {
        file_temp = fopen("temp.txt", "wb+");
        if (file_temp == NULL)

            printf("file opening error");
        else

        {

            printf("Enter CONTACT'S NAME:");
            gets(name);
            fflush(stdin);

            fflush(stdin);
            while (fread(&x, sizeof(x), 1, files) == 1)
            {
                if (strcmp(x.fullname, name) != 0)

                    fwrite(&x, sizeof(x), 1, file_temp);

                fflush(stdin);
                if (strcmp(x.fullname, name) == 0)
                    fl = 1;
            }
            fclose(files);
            fclose(file_temp);
            if (fl != 1)
            {
                printf("NO CONTACT'S RECORD TO DELETE.");
                remove("temp.txt");
            }
            else
            {
                remove("project.txt");
                rename("temp.txt", "project.txt");
                printf("RECORD DELETED SUCCESSFULLY.");
            }
        }
    }
    printf("\n Enter any key");

    getch();
    system("cls");
    menu();
}

/*---------------------------------Update-------------------------------*/
void update_info()
{
    int b;
    FILE *files;
    int fl = 0;
    struct phonebook x, y;
    char name[50];
    files = fopen("project.txt", "rb+");
    if (files == NULL)
    {

        printf("CONTACT'S DATA NOT ADDED YET.");
        exit(1);
    }
    else
    {
        system("cls");
        printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
        gets(name);
        fflush(stdin);
        while (fread(&x, sizeof(x), 1, files) == 1)
        {
            if (strcmp(name, x.fullname) == 0)
            {

                int m;
                char g[] = "@gmail.com";
                char yy[] = "@yahoo.com";
                char o[] = "@outlook.com";

                printf("\n Enter Name: ");
                gets(y.fullname);
                fflush(stdin);
                printf("\nEnter the Address: ");
                gets(y.add);
                fflush(stdin);
                printf("\nEnter Father Name: ");
                gets(y.f_name);
                fflush(stdin);
                printf("\nEnter Mother Name: ");
                gets(y.m_name);
                fflush(stdin);
                printf("\nEnter Contact Number.:");

                for (;;)
                {
                    gets(x.contact_no);
                    if (strlen(x.contact_no) <= 11)
                        break;
                    else
                        printf("More then 11 numbers. Input again!!!! \n");
                }

                fflush(stdin);
                printf("Enter Gender:");
                gets(y.gender);
                fflush(stdin);
                printf("\nEnter Email Address Till @:");
                gets(y.email_add);

                printf("choose : \n 1. Gmail \n 2. Yahoo \n 3. Outlook \n");
                scanf("%d", &m);

                if (m == 1)
                {
                    strcat(y.email_add, g);
                }
                if (m == 2)
                {
                    strcat(y.email_add, yy);
                }
                if (m == 3)
                {
                    strcat(y.email_add, o);
                }
                puts(y.email_add);

                fflush(stdin);
                printf("\nEnter Postal Code:");
                gets(y.postal_code);
                fflush(stdin);

                fseek(files, -sizeof(x), SEEK_CUR);

                fwrite(&y, sizeof(x), 1, files);

                fflush(stdin);
                fl = 1;
                break;
            }
            fflush(stdin);
        }
        if (fl == 1)
        {
            printf("\n your data id modified");
        }
        else
        {
            printf(" \n data is not found");
        }
        fclose(files);
    }
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}

/*------------------------------------------To copy information---------------------------------*/
void copycontact()
{

    struct phonebook x, y;
    char name[50];

    FILE *files, *target;

    files = fopen("project.txt", "rb");

    if (files == NULL)
    {
        printf("Press any key to exit...\n");
        printf("file not found");
        exit(1);
    }

    target = fopen("copy.txt", "ab+");

    if (target == NULL)
    {
        fclose(files);
        printf("Press any key to exit...\n");
        printf("file not found");
        exit(1);
    }

    printf("\nEnter the Name of Person you want to copy\n");
    gets(name);
    fflush(stdin);
    printf("\n\t COPYING Detail Information About %s ...........\n\n", name);

    printf("\n   %-20s%-30s%-20s%-20s%-20s%-10s%-30s%s\n", "Name", "Address", "Father's Name", "Mother's Name", "Contact NO.", "Gender", "E-mail", "Postal Code");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (fread(&x, sizeof(x), 1, files) == 1)
    {
        if (strcmp(x.fullname, name) == 0)
        {

            printf("    %-20s%-30s%-20s%-20s%-20ld%-10s%-30s%s\n", x.fullname, x.add, x.f_name, x.m_name, x.contact_no, x.gender, x.email_add, x.postal_code);

            fwrite(&x, sizeof(x), 1, target);

            fflush(stdin);
            printf("\n\n------COPIED %s CONTACT'S INFORMATION--------\n", name);
            fflush(stdin);
        }
    }
    fclose(files);
    fclose(target);

    printf("\n Enter any key");

    getch();
    menu();
}
/*--------------------------------------------------Copied Informaiton ----------------------------------*/
void copiedcontact()
{

    system("cls");
    struct phonebook x;
    FILE *files;

    files = fopen("copy.txt", "r");
    if (files == NULL)
    {
        printf("\nfile opening error in listing :");

        exit(1);
    }
    printf("\n%90s\n\n\n","COPIED CONTACT");
    printf("\n   %-20s%-30s%-20s%-20s%-20s%-10s%-30s%s\n", "Name", "Address", "Father's Name", "Mother's Name", "Contact NO.", "Gender", "E-mail", "Postal Code");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    while (fread(&x, sizeof(x), 1, files) == 1)
    {
        printf("    %-20s%-30s%-20s%-20s%-20ld%-10s%-30s%s\n", x.fullname, x.add, x.f_name, x.m_name, x.contact_no, x.gender, x.email_add, x.postal_code);
    }
    fclose(files);

    printf("\n Enter any key\n");
    getch();
    menu();
}



/*------------------------------------------ADD TO  FAVOURITE---------------------------------*/


void favcontact()
{

    struct phonebook x, y;
    char name[50];

    FILE *files, *fav;

    files = fopen("project.txt", "rb");

    if (files == NULL)
    {
        printf("Press any key to exit...\n");
        printf("file not found");
        exit(1);
    }

    fav = fopen("fav.txt", "ab+");

    if (fav == NULL)
    {
        fclose(files);
        printf("Press any key to exit...\n");
        printf("file not found");
        exit(1);
    }

    printf("\nEnter the Name of Person you want to Add to Favourite\n");
    gets(name);
    fflush(stdin);

    printf("\n   %-20s%-30s%-20s%-20s%-20s%-10s%-30s%s\n", "Name", "Address", "Father's Name", "Mother's Name", "Contact NO.", "Gender", "E-mail", "Postal Code");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (fread(&x, sizeof(x), 1, files) == 1)
    {
        if (strcmp(x.fullname, name) == 0)
        {

            printf("    %-20s%-30s%-20s%-20s%-20ld%-10s%-30s%s\n", x.fullname, x.add, x.f_name, x.m_name, x.contact_no, x.gender, x.email_add, x.postal_code);

            fwrite(&x, sizeof(x), 1, fav);

            fflush(stdin);
            printf("\n\n------COPIED %s CONTACT ADDED--------\n", name);
            fflush(stdin);
        }
    }
    fclose(files);
    fclose(fav);

    printf("\n Enter any key");

    getch();
    menu();
}
/*--------------------------------------------------favourite list ----------------------------------*/
void favlist()
{

    system("cls");
    struct phonebook x;
    FILE *files;

    files = fopen("fav.txt", "r");
    if (files == NULL)
    {
        printf("\nfile opening error in listing :");

        exit(1);
    }
    printf("\n%90s\n\n\n","FAVOURITE LIST");
    printf("\n   %-20s%-30s%-20s%-20s%-20s%-10s%-30s%s\n", "Name", "Address", "Father's Name", "Mother's Name", "Contact NO.", "Gender", "E-mail", "Postal Code");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    while (fread(&x, sizeof(x), 1, files) == 1)
    {
        printf("    %-20s%-30s%-20s%-20s%-20ld%-10s%-30s%s\n", x.fullname, x.add, x.f_name, x.m_name, x.contact_no, x.gender, x.email_add, x.postal_code);
    }
    fclose(files);

    printf("\n Enter any key\n");
    getch();
    menu();
}
