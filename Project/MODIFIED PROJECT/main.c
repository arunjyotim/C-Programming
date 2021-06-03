#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
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
void menu();
// void gets();
void strt();
void bck();
void add_info();
void list_info();
void update_info();
void delete_info();
void search_info();
void copycontact();
void copiedcontact();
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
void menu()
{
    system("cls");
printf("\t\t**********WELCOME TO MY PHONEBOOK*************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Add New   \t2.List   \t3.Exit  \t4.Modify\n \t5.Search\t6.Delete\t7.Copy Contact\t8.Copied Contact\t\n\n");
printf("\n\t Please Enter the Number You Want to Choose");
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
    case '7': copycontact();
    break;
    case '8': copiedcontact();
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

menu();
}
}
        void add_info()
{
        system("cls");
        FILE *files;
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
        printf("\nEnter Contact Number.:");
        printf("\nContact number cannot be more than 11 digits\n");
        scanf("%ld",&x.contact_no);
        fflush(stdin);
        printf("Enter Gender:");
        gets(x.gender);
        fflush(stdin);
        printf("\nEnter Email Address:");
         gets(x.email_add);
         fflush(stdin);
        printf("\nEnter Postal Code:");
        gets(x.postal_code);
        fflush(stdin);
        fprintf(files,"%s-%s-%s-%ld-%s-%s-%d",x.fullname,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);
        

      fflush(stdin);
        printf("\nNew Record Has Been Successfully Saved");

fclose(files);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    menu();
}
void list_info()
{
    struct phonebook x;
    FILE *files;
files=fopen("project.txt","rb");
if(files==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fscanf)
{
     printf("\n\n\n YOUR RECORD INFORMATION IS\n\n ");
        printf("\nName=%s\nAdress=%s\nFather name=%s\nMother name=%s\nMobile no=%ld\nSex=%s\nE-mail=%s\nPostal Code=%s",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);

	 getch();
	 system("cls");
	 fflush(stdin);
}
fclose(files);
 printf("\n Enter any key");
 getch();
    system("cls");
menu();
}
void search_info()
{
    struct phonebook x;
FILE *files;
char name[100];

files=fopen("project.txt","rb");
if(files==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter the Name of Person you want to Search\n");
gets(name);
fflush(stdin);
while(fread(&x,sizeof(x),1,files)==1)
{
    if(strcmp(x.fullname,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nCitision no:%s",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);
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
    FILE *files,*file_temp;
	int fl;
	char name[100];
	files=fopen("project.txt","rb");
	if(files==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		file_temp=fopen("temp.txt","wb+");
		if(file_temp==NULL)

            printf("file opening error");
		else

        {


		printf("Enter CONTACT'S NAME:");
		gets(name);
		fflush(stdin);

		fflush(stdin);
		while(fread(&x,sizeof(x),1,files)==1)
		{
			if(strcmp(x.fullname,name)!=0)
				fwrite(&x,sizeof(x),1,file_temp);
				fflush(stdin);
			if(strcmp(x.fullname,name)==0)
                fl=1;
                
		}
	fclose(files);
	fclose(file_temp);
	if(fl!=1)
	{
		printf("NO CONTACT'S RECORD TO DELETE.");
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

void update_info()
{
    int b;
    FILE *files;
    int fl=0;
    struct phonebook x,y;
	char  name[50];
	files=fopen("project.txt","rb+");
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
            fflush(stdin);
            while(fread(&x,sizeof(x),1,files)==1)
            {
                if(strcmp(name,x.fullname)==0)
                {



                    printf("\n Enter Name:");
                    gets(y.fullname);
                    fflush(stdin);
                    printf("\nEnter the Address:");
                    gets(y.add);
                    fflush(stdin);
                    printf("\nEnter Father Name:");
                    gets(y.f_name);
                    fflush(stdin);
                    printf("\nEnter Mother Name:");
                    gets(y.m_name);
                    fflush(stdin);
                    printf("\nEnter Contact Number:");
                    scanf("%ld",&y.contact_no);
                    fflush(stdin);
                    printf("\nEnter Gender:");
                    gets(y.gender);
                    fflush(stdin);
                    printf("\nEnter Email Address:");
                    gets(y.email_add);
                    fflush(stdin);
                    printf("\nEnter Postal Code\n");
                    gets(y.postal_code);
                    fflush(stdin);
                    fseek(files,-sizeof(x),SEEK_CUR);
                    fwrite(&y,sizeof(x),1,files);
                    fflush(stdin);
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

void copycontact(){

    struct phonebook x,y;
	char name[50];

   FILE *files, *target;

   files = fopen("project.txt", "rb+");

   if( files == NULL )
   {
      printf("Press any key to exit...\n");
      printf("file not found");
      exit(1);
   }

   target = fopen("copy.txt", "wb+");

   if( target == NULL )
   {
      fclose(files);
      printf("Press any key to exit...\n");
      printf("file not found");
      exit(1);
   }

   printf("\nEnter the Name of Person you want to copy\n");
gets(name);
fflush(stdin);
while(fread(&x,sizeof(x),1,files)==1)
{
    if(strcmp(x.fullname,name)==0)
    {
        printf("\n\t COPYING Detail Information About %s",name);

        printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nPostal Code:%s",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);

       fwrite(&x,sizeof(x),1,target);
       fflush(stdin);
       printf("\nCOPIED CONTACT INFORMATION\n");
       fflush(stdin);

    }





}


  printf("\n Enter any key");

	 getch();
    system("cls");
menu();

    fclose(files);
   fclose(target);



}
void copiedcontact(){

    struct phonebook x;
    FILE *files;
files=fopen("copy.txt","rb");
if(files==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fread(&x,sizeof(x),1,files)==1)
{
     printf("\n\n\n YOUR RECORD INFORMATION IS\n\n ");
        printf("\nName=%s\nAddress=%s\nFather name=%s\nMother name=%s\nMobile no=%ld\nSex=%s\nE-mail=%s\nPostal Code=%s",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);

	 getch();
	 system("cls");
	 fflush(stdin);
}
fclose(files);
 printf("\n Enter any key\n");
 getch();
    system("cls");
menu();

}