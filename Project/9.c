#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct shop
{
    int record;
    char toolName[40];
    int quantity;
    double cost;
};
int main()
{
    printf("---------< Shop Record Management >----------\n");
    printf("--------- Press any key to continue ---------");
    getch();
    menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    printf("----------< MENU >------------\n");
    printf("Enter a option from below \n");
    printf("\n1: Add Record.\n");
    printf("2: View Record\n");
    printf("3: Search Record\n");
    printf("4: Modify Record\n");
    printf("5: Delete Record\n");
    printf("6: Exit\n\n");
    printf("Enter you choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        printf("Invalid Choice");
        break;
    }
}
void add()
{

    FILE *fp;
    struct shop add;
    char another='y';
    system("cls");

    fp = fopen("hardware.dat","ab+");
    if(fp==NULL)
    {
        printf("Error Opening file\n");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        printf("\n\n----< ADD RECORD >----\n");
        printf("-----Enter new details----\n\n");
        printf("Enter Record no : ");
        scanf("%d", &add.record);
        fflush(stdin);
        printf("Enter Tool Name : ");
        gets(add.toolName);
        fflush(stdin);
        printf("Enter Quantity : ");
        scanf("%d", &add.quantity);
        printf("Enter Cost: ");
        scanf("%lf", &add.cost);
        fwrite(&add,sizeof(add),1,fp);
        //fprintf(fp,"%-10d%-20s%-14d%.2f\n", add.record, add.toolName, add.quantity, add.cost);
        printf("\n\nAdd another record? then press 'Y' or else 'N': ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    printf("\n\n Press any key to return to menu\n\n");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    struct shop view;
    system("cls");
    printf("----< VIEW RECORD >----\n\n");
    printf("%-10s%-20s%-14s%s\n","Record","Tool Name","Quantity","Cost");
    printf("-------------------------------------------------------------\n");
    fp = fopen("hardware.dat","rb+");
    fflush(stdin);
    while(fread(&view, sizeof(view),1,fp)==1)
    {
        printf("%-10d%-20s%-14d%.2f\n", view.record, view.toolName, view.quantity, view.cost);

    }
    fclose(fp);
    printf("\n\nPress any key to return to menu");
    getch();
    menu();
}
void search()
{

    FILE *fp;
    fp = fopen("hardware.dat","r");
    struct shop srch;
    char tool[40];
    system("cls");
    printf("-------< SEARCH RECORD >------\n");
    fflush(stdin);
    printf("Enter Toolname: ");
    gets(tool);
    while(fread(&srch,sizeof(srch),1,fp ) == 1)
    {
        if(strcmp(tool,srch.toolName) == 0)
        {
            printf("\nRecord No   : %d\n", srch.record);
            printf("Tool Name   : %s\n", srch.toolName);
            printf("Quantity    : %d\n", srch.quantity);
            printf("Cost        : %.2f\n\n", srch.cost);
        }

    }
    fclose(fp);
    printf("Press any key to return to menu\n");
    getch();
    menu();
}
void modify()
{
    FILE *fp;
    fp = fopen("hardware.dat","rb+");
    struct shop modif;
    system("cls");
    char name[40];
    printf("----< MODIFY >-----\n");
    printf("Enter Tool name to modify: ");
    fflush(stdin);
    gets(name);
    rewind(fp);
    fflush(stdin);
    while(fread(&modif,sizeof(modif),1,fp) == 1)
    {
        if(strcmp(name,modif.toolName)==0)
        {
            printf("Enter New Tool Name: ");
            gets(modif.toolName);
            fflush(stdin);
            printf("Enter New Record No: ");
            scanf("%d", &modif.record);
            fflush(stdin);
            printf("Enter New Quantity: ");
            scanf("%d", &modif.quantity);
            fflush(stdin);
            printf("Enter New Cost: ");
            scanf("%lf", &modif.cost);
            fflush(stdin);
            fseek(fp, -sizeof(modif), SEEK_CUR);
            fwrite(&modif, sizeof(modif),1,fp);
            break;
        }
    }
    fclose(fp);
    printf("\n\nPress any key to return to menu\n\n");
    getch();
    menu();
}
void deleterec()
{
    struct shop del;
    FILE *fp, *ft;
    fp = fopen("hardware.dat","rb+");
    ft = fopen("temp.dat","wb+");
    system("cls");
    char name[40];
    char another = 'y';
    printf("----< DELETE RECORD >-----\n");
    printf("Enter Tool Name to delete record: ");
    fflush(stdin);
    gets(name);

    while(fread(&del, sizeof(del),1,fp)==1)
    {
        if(strcmp(name, del.toolName)!=0)
        {
            fwrite(&del, sizeof(del),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("hardware.dat");
    rename("temp.dat","hardware.dat");
    printf("\n\nPress any key to return to menu\n\n");
    getch();
    menu();
}