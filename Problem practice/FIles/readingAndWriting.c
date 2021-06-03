#include<stdio.h>
#include<stdlib.h>
struct book
{
    int bno;
    char name[10];
};
int main()
{
    FILE *fp;
    struct book b[5]; 
    int i;
    fp = fopen("book.txt","wb");
    if (fp==NULL)
    {
        printf("\n Error can't open file");
        exit(1);
    }
    printf("\nEnter 5 Books details...\n");
    for(i=0;i<5;i++)
    {
        printf("Enter %d Book no = ",i+1);
        fflush(stdin);
        scanf("%d",&b[i].bno);
        printf("Enter %d Book Name = ", i+1);
        fflush(stdin);
        gets(b[i].name);
        printf("\n");
    }

    fwrite(b,sizeof(struct book),5,fp);
    printf("\n-------Data is stored successfully.-------"); 

    fp=fopen("book.txt","rb");
    if(fp==NULL)
    {
        printf("\nError can't open file");
        exit(1);
    }
    fread(b,sizeof(struct book),5,fp);
    printf("\nBook Details...\n");
    for(i=0;i<5;i++)
    {
        printf("\nBook No = %d",b[i].bno);
        printf("\nBook Name = %s",b[i].name);
    }
    fclose(fp);
    
}
