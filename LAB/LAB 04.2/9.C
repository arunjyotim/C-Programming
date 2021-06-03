#include <stdio.h>


void main()
{
   int n[50],i,a,num,newNum;

    printf("Input the size of array : ");
    scanf("%d", &a);

       printf("Input the elements in the array in ascending order:\n",a);
       for(i=0;i<a;i++)
        {
	      printf("element = %d : ",i);
	      scanf("%d",&n[i]);

	    }
      printf("\n The existed array list is :\n ");
   for(i=0;i<a;i++)
     {
          printf("% 5d",n[i]);  
     }

   printf("\n\n Input the value to be inserted: ");
   scanf("%d",&newNum);

   for(i=0;i<a;i++)
     if(newNum<n[i])
     {
       num = i;
       break;
     }
     
   for(i=a;i>=num;i--){
       n[i]= n[i-1];

      n[num]=newNum;
   }
      printf("\n\n After Insert the list is :\n ");
   for(i=0;i<=a;i++)
      {
      printf("% 5d",n[i]);
	  printf("\n");
      }
}