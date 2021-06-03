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
    FILE *fp,*ft;
    char another, choice;

    struct emp
    {
        char name[40];
        int amount;
        float cost;
    };

    struct emp e;
    char empname[40];
    long int resize;

    fp=fopen("EMP.dat","rb+");

    if(fp==NULL)
    {
        fp = fopen("EMP.dat","wb+");
        if(fp==NULL)
        {
            printf("Can't open file");
            exit(1);
        }
    }

    resize = sizeof(e);

    while(1)
    {
        system("cls");
        gotoxy(30,10);
        printf("1. Add Record");
        gotoxy(30,12);
        printf("2. List Record");
        gotoxy(30,14);
        printf("3. Modify Record");
        gotoxy(30,16);
        printf("4. Delete Record");
        gotoxy(30,18);
        printf("5. Exit");
        gotoxy(30,20);
        printf("Your Choice");
        fflush(stdin);
        choice = getche();

        switch (choice)
        {
        case '1':
            system("cls");
            fseek(fp,0,SEEK_END);

            another = 'y';
            while(another=='y')
            {
                printf("\nEnter Name: ");
                scanf("%s",e.name);
                printf("\nEnter amount: ");
                scanf("%d",&e.amount);
                printf("\nEnter basic salary: ");
                scanf("%d",&e.cost);

                fwrite(&e,resize,1,fp);

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();

            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            while(fread(&e,resize,1,fp)==1)
            {
                printf("\n%s %d %.2f", e.name,e.amount,e.cost);
            }
            getch();
            break;
        case '3':
            system("cls");
            another = 'y';
            while (another == 'y')
            {
                printf("enter name to modify: ");
                scanf("%s",empname);
                rewind(fp);
                while(fread(&e,resize,1,fp)==1)
                {
                    if(strcmp(e.name,empname)==0)
                    {
                        printf("\nEnter new name,amount and salary:");
                        scanf("%s%d%f",e.name,&e.amount,e.cost);
                        fseek(fp,-resize,SEEK_CUR);
                        fwrite(&e,resize,1,fp);
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
                printf("\nEnter name of employee to delete: ");
                scanf("%s",empname);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
                while ((fread(&e,resize,1,fp)==1))
                {
                    if(strcmp(e.name,empname)!=0)
                    {
                        fwrite(&e,resize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.dat");
                rename("Temp.dat","EMP.dat");
                fp = fopen("EMP.dat","rb+");
                printf("Delete anotehr record(y/n");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(fp);
            exit(0);
        }
    }

    return 0;

}
