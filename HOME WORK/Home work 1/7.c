#include<stdio.h>
#include <string.h>
 
int main()
{
    char a[1000];  
    int i,v=0,c=0;
    printf("Enter  the string : ");
    gets(a);
     
    for(i=0;a[i];i++)  
    {
    	if((a[i]>=65 && a[i]<=90)|| (a[i]>=97 && a[i]<=122))
    	{
            if(a[i]=='a'|| a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O' ||a[i]=='U')
		      v++;
            else
             c++;
        }
 	}
    printf("Numbers of Vowels = %d\n",v);
    printf("Numbers of consonants = %d\n",c);
    
    return 0;
}