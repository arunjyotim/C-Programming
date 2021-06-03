#include <stdio.h>
#define size 10
 int main ()
 {
         float grade[size] = {0};
         int n,i,j;
         float sum = 0, average, highest = 0, lowest = 0;

         printf("Enter the number of students: ");
         scanf("%f", &n);


         printf("Enter the grades: \n");
         for(i = 0; i < grade; i++)
            {
                scanf("%f", &grade);

                sum += grade[i];
                 if (grade[i] > highest)
                 {
                      highest = grade[i];
                 }

                else if (grade[i] < lowest)
                 {
                      lowest = grade[i];
                 }

            }

         average = sum / n;
         printf("The Average Grade is %5.2f \n", average);
         printf("The Highest Grade is %5.2f \n", highest);
         printf("The lowest Grade is %5.2f \n", lowest);

         printf("Grade Distribution: ");

         for(i=0; i<size; i++)
         {
            printf("%d%2f",i,grade[i]);
            for(j=1;j<=grade[i];j++)
            {
                printf("%c",'*');
            }
            printf("\n");
         }
         return 0;
 }
