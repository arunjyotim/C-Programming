#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char ch;
    int w=1,c=1;
    char name[40];
	printf("Input the filename to open and count the contents : \n");
	scanf("%s",name);

    file=fopen(name,"r");
    if(file==NULL)
     {
         printf("Unable to open/ create file.");
      }
    else
        {
          ch=fgetc(file);
          printf("The contents of the %s are : \n\n",name);
          while(ch!=EOF)
            {
                printf("%c",ch);
                if(ch==' '||ch=='\n')
                    {
                        w++;
                    }
                    else
                    {
                        c++;
                    }
                ch=fgetc(file);
            }
        printf("\n The number of words in the  file %s are : %d\n",name,w-2);
        printf(" The number of characters in the  file %s are : %d\n\n",name,c-1);
        }
    fclose(file);
}
