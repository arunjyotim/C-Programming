#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

COORD coord={0,0};

void gotoxy(int x, int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    FILE *hFile,*ft;
    char another, choice;

    struct hardware
    {
        int record;
        char toolName[100];
        int quantity;
        float cost;
    };

    struct hardware e;
    char hName[40];
    long int resize;

    hFile=fopen("EMP.dat","rb+");

    if(hFile==NULL)
    {
        hFile = fopen("EMP.dat","wb+");
        if(hFile==NULL)
        {
            printf("Can't open file");
            exit(1);
        }
    }

    resize = sizeof(e);

    while(1)
    {
        system("cls");
        printf("\n\n---------------------------------WElCOME TO TOOLBOX-----------------------------");
        gotoxy(30,10);
        printf("1. Add Tool Details");
        gotoxy(30,12);
        printf("2. All Saved Informaiton");
        gotoxy(30,14);
        printf("3. Modify Information");
        gotoxy(30,16);
        printf("4. Delete Information");
        gotoxy(30,18);
        printf("5. Exit");
        gotoxy(30,20);
        printf("Enter What you want to do: ");
        fflush(stdin);
        choice = getche();

        switch (choice)
        {
        case '1':
            system("cls");
            fseek(hFile,0,SEEK_END);

            another = 'y';
            while(another=='y')
            {
                printf("\nEnter Tool Name: ");
                scanf("%s",e.toolName);
                printf("\nEnter record Name: ");
                scanf("%d",&e.record);
                printf("\nEnter Tool quantity: ");
                scanf("%d",&e.quantity);
                printf("\nEnter Tool cost: ");
                scanf("%f",&e.cost);

                fwrite(&e,resize,1,hFile);

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();

            }
            break;
        case '2':
            system("cls");
            rewind(hFile);
            while(fread(&e,resize,1,hFile)==1)
            {
                printf("\n %s %d %d %.2f",e.toolName,e.record,e.quantity,e.cost);
            }
            getch();
            break;
        case '3':
            system("cls");
            another = 'y';
            while (another == 'y')
            {
                printf("enter name to modify: ");
                scanf("%s",hName);
                rewind(hFile);
                while(fread(&e,resize,1,hFile)==1)
                {
                    if(strcmp(e.toolName,hName)==0)
                    {
                        printf("\nEnter new name,quantity and salary:");
                        scanf("%d%s%d%f",e.record,e.toolName,&e.quantity,e.cost);
                        fseek(hFile,-resize,SEEK_CUR);
                        fwrite(&e,resize,1,hFile);
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while (another == 'y')
            {
                printf("\nEnter tool name to delete: ");
                scanf("%s",hName);
                ft = fopen("Temp.dat","wb");
                rewind(hFile);
                while ((fread(&e,resize,1,hFile)==1))
                {
                    if(strcmp(e.toolName,hName)!=0)
                    {
                        fwrite(&e,resize,1,ft);
                    }
                }
                fclose(hFile);
                fclose(ft);
                remove("EMP.dat");
                rename("Temp.dat","EMP.dat");
                hFile = fopen("EMP.dat","rb+");
                printf("--*File has been deleted*--\n");
                printf("Delete another record (y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(hFile);
            exit(0);
        }
    }
    return 0;
}
