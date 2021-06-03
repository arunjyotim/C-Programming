#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

/*--------------------------------------Structure-------------------------------------*/
struct phonebook
{
    char fullname[35];
    char add[50];
     char f_name[35];
     char m_name[30];
    long int contact_no;
    char gender[8];
    char email_add[100];
    char postal_code[20];

    };
/*-----------------------------------Function prototype----------------------------------------------*/
void menu();

void strt();
void bck();
void add_info();
void email();
void list_info();
void update_info();
void delete_info();
void search_info();
/*------------------------------------------------Main---------------------------------------------*/
int main()
{
    system("color 1f");
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
/*------------------------------------------------Menu---------------------------------------------*/
void menu()
{
    system("cls");
printf("\t\t**********WELCOME TO PHONEBOOK*************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search\t6.Delete\t\n\n");
printf("\n\tPlease Enter the Number you Want to Choose: ");
switch(getch())
{
    case '1':

                add_info();
    break;
     case '2': list_info();
    break;
    case '3': exit(0);
    break;
    case '4': update_info();
    break;
    case '5': search_info();
    break;
    case '6': delete_info();
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

menu();
}
}
/*------------------------------------------------Add Info---------------------------------------------*/

        void add_info()
{
        system("cls");
        FILE *files;
        char name[30];
        char gmail[11] = "@gmail.com";
        char yahoo[11] = "@yahoo.com";
        char otl[13] = "@outlook.com";
        int i,j,len;

        struct phonebook x;
        files=fopen("project.txt","a");
        printf("\n Enter Name: ");
        gets(x.fullname);
        fflush(stdin);
        printf("\nEnter the Address: ");
        gets(x.add);
        fflush(stdin);
        printf("\nEnter Father Name: ");
        gets(x.f_name);
        fflush(stdin);
        printf("\nEnter Mother Name: ");
        gets(x.m_name);
        fflush(stdin);

        printf("\nEnter Contact Number:");
        scanf("%ld",&x.contact_no);
        fflush(stdin);

        printf("\nEnter Gender:");
        gets(x.gender);
        fflush(stdin);

        printf("\nEnter Postal Code:");
        gets(x.postal_code);
        fflush(stdin);


        printf("\nEnter your email address: ");
        fflush(stdin);
        gets(name);
                             /*-------For taking different email--------*/
            len = strlen(name);
            printf("\nChoose one of the domain:\n");
            printf("1. @gmail.com\n");
            printf("2. @yahoo.com\n");
            printf("3. @outlook.com\n");
            scanf("%d",&i);
            switch (i)
            {
            case 1:
                for(i=len , j=0 ; gmail[j]!= '\0'; j++, i++){
                    name[i] = gmail[j];
                }
                name[i] = '\0';
                printf("%s\n", name);
                fprintf(files,"    %-20s%-30s%-20s%-20s%-20ld%-10s%-30s%s\n",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,name,x.postal_code);
                break;
            case 2:
                for(i=len , j=0 ; yahoo[j]!= '\0'; j++, i++){
                    name[i]= yahoo[j];
                }
                name[i] = '\0';
                printf("%s\n", name);
                fprintf(files,"    %-20s%-30s%-20s%-20s%-20ld%-10s%-30s%s\n",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,name,x.postal_code);
                break;
            case 3:
                for(i=len , j=0 ; otl[j]!= '\0'; j++, i++){
                    name[i]= otl[j];
                }
                name[i] = '\0';
                printf("%s\n", name);
                fprintf(files,"   %-20s%-30s%-20s%-20s%-20ld%-10s%-30s%s\n",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,name,x.postal_code);
                break;
            
            default:
                printf("Wrong choice!");
                break;
            }

        fflush(stdin);

      fflush(stdin);
        printf("\nNew Record Has Been Successfully Saved");

    fclose(files);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    menu();
}
/*----------------------------------------------View List--------------------------------------------*/

    void list_info()
{
    struct phonebook x;
    FILE *files;

    char temp[1000];

    files=fopen("project.txt","r");
    if(files==NULL)
    {
    printf("\nfile opening error in listing :");
    exit(1);
    }
    printf("\n   ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n   %-20s%-30s%-20s%-20s%-20s%-10s%-30s%s\n","Name","Address","Father's Name","Mother's Name","Contact NO.","Gender","E-mail","Postal Code");
    printf("   ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fgets(temp,sizeof(temp),files);
    while(!feof(files))
{
     printf("%s", temp);
     fgets(temp,sizeof(temp),files);
}

    fclose(files);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}

/*------------------------------------------------Search info---------------------------------------------*/
void search_info()
{
    struct phonebook x;
    FILE *files;
    char name[100];

    files=fopen("project.txt","r");
    if(files==NULL)
    {
        printf("\n Error in opening!\a\a\a\a");
        exit(1);

    }
    printf("\nEnter the Name of Person you want to Search\n");
    gets(name);
    //fgets(name,sizeof(name),files);
    while(fgets(name,sizeof(name),files)!=NULL)
    {   
        
        if(strstr(name,x.fullname)!= NULL)
        {
            printf("\n\tDetail Information About %s",name);
            printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nCitision no:%s",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);
            break;
        }
            else
            printf("file not found");
            break;

            //fgets(name,sizeof(name),files);

    }
    fclose(files);
    printf("\n Enter any key");

	getch();
    system("cls");
    menu();
}
/*------------------------------------------------Delete info---------------------------------------------*/

void delete_info()
{
    struct phonebook x;
    FILE *files,*file_temp;
	int fl;
	char name[100];
	files=fopen("project.txt","r");
	if(files==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		file_temp=fopen("temp.txt","w");
		if(file_temp==NULL)

            printf("File opening error!");
		else

        {


		printf("Enter CONTACT'S NAME:");
		gets(name);

		fflush(stdin);
		while(fread(&x,sizeof(x),1,files)==1)
		{
			if(strcmp(x.fullname,name)!=0)
				fwrite(&x,sizeof(x),1,file_temp);
			if(strcmp(x.fullname,name)==0)
                fl=1;
		}
	fclose(files);
	fclose(file_temp);
	if(fl!=1)
	{
		printf("NO CONACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project.txt");
			rename("temp.txt","project.txt");
			printf("RECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}
/*------------------------------------------------Modify---------------------------------------------*/

void update_info()
{
    int b;
    FILE *files;
    int fl=0;
    struct phonebook x,y;
	char  name[50];
	files=fopen("project.txt","r+");
	if(files==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            gets(name);
            while(fread(&x,sizeof(x),1,files)==1)
            {
                if(strcmp(name,x.fullname)==0)
                {



                    printf("\n Enter Name:");
                    gets(y.fullname);
                    printf("\nEnter the Address:");
                    gets(y.add);
                    printf("\nEnter Father Name:");
                    gets(y.f_name);
                    printf("\nEnter Mother Name:");
                    gets(y.m_name);
                    printf("\nEnter Contact Number:");
                    scanf("%ld",&y.contact_no);
                    printf("\nEnter Gender:");
                    gets(y.gender);
                    printf("\nEnter Email Address:");
                    gets(y.email_add);
                    printf("\nEnter Postal Code\n");
                    gets(y.postal_code);
                    fseek(files,-sizeof(x),SEEK_CUR);
                    fwrite(&y,sizeof(x),1,files);
                    fl=1;
                    break;



                }
                fflush(stdin);


            }
            if(fl==1)
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
