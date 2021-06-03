#include <stdio.h>

int main(void)
{
   int row1[50][50], row2[50][50];
   int i, j, r1, c1,r2, c2, store =1;
  
   printf("Input Rows and Columns of the 1st matrix :\n");
   scanf("%d %d", &r1, &c1);

   printf("Input Rows and Columns of the 2nd matrix :\n");
   scanf("%d %d", &r2,&c2);
	 printf("Input elements in the first matrix :\n");
       for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
	           printf("Element-[%d],[%d] : ",i,j);
	           scanf("%d",&row1[i][j]);
            }
        } 
       printf("Input elements in the second matrix :\n");
       for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
	           printf("Element-[%d],[%d] : ",i,j);
	           scanf("%d",&row2[i][j]);
            }
        }   
 	 printf("The first matrix is :\n");
	 for(i=0;i<r1;i++)
	 {
	   for(j=0;j<c1 ;j++)
	     printf("% 4d",row1[i][j]);
	    printf("\n");
	 }
	 printf("The second matrix is :\n");
	 for(i=0;i<r2;i++)
	 {
	   for(j=0;j<c2 ;j++)
	     printf("% 4d",row2[i][j]);
	    printf("\n");
	 }

   if(r1 == r2 && c1 == c2)
   {
    	printf("The Matrices can be compared : \n");
    	for(i=0; i<r1; i++)
    	{
     		for(j=0; j<c2; j++)
     		{
			if(row1[i][j] != row2[i][j])
			{
	   			store = 0;
	   			break;
			}
     		}
   	   }
    }
    else
    {  printf("The Matrices Cannot be compared :\n");
       exit(1);
    }
    if(store == 1 )
	printf("Two matrices are equal.\n");
    else
	printf("two matrices are not unequal\n");
}