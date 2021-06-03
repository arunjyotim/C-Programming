#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"string.h"
#include"process.h"
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
void search_info();
int main ()
{
    search_info();
}
void search_info()
{
    struct phonebook x;
    FILE *fp;
    char ch, search_string[300], temp[300];
    int  i=0, k, search_len;
    long int count=0;


    puts("\nEnter the Name of Person you want to Search\n");
    gets(search_string);
    search_len = strlen(search_string);

    // printf("%d\n",search_len);


    if((fp=fopen("project.txt","r"))==NULL)
    {
        puts("Open Error!");
        getch();
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF)
    {
        if(i<search_len)
        {
            temp[i]=ch;
            ++i;
        }

        if(i==search_len)
        {

            count++;
            temp[i]='\0';
            k=stricmp(search_string,temp);

            if(k==0)
            {
                printf("search successful\n");
                printf("%s was found",search_string);
                
                while (fgets(temp, sizeof(temp),fp))
                {
                    if(strcmp(search_string,x.fullname==0)){
                        printf("\n   %-20s%-30s%-20s%-20s%-20s%-10s%-30s%s\n",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);
                    }
                }
                
                
                
                //printf("\n\tDetail Information About %s",search_string);
                // printf("\n   %-20s%-30s%-20s%-20s%-20s%-10s%-30s%s\n","Name","Address","Father's Name","Mother's Name","Contact NO.","Gender","E-mail","Postal Code");
                 //printf("\n   %-20s%-30s%-20s%-20s%-20s%-10s%-30s%s\n",search_string,x.add,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);

            }


            i=0;
            fseek(fp,count,SEEK_SET);

        }
    }
}
