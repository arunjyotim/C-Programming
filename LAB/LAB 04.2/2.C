#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
    int a[50], t, c;
    srand(time(0));

    for(int i = 0; i < 50; i++)
    {
        a[i] = (rand() % 50) + 1;
    }

    printf("Please enter an integer: ");
    scanf("%d",&t);

    while(t != -1)
    {
        for(int i = 0; i < 50; i++)
        {
        	c = 0;
            if(a[i] == t)
            {
            	c = 1;
                break;
            }

        }
        if(c == 1) {
			printf("The number is present in the array.\n");
        }
        else{
        printf("The number is not present in the array.\n");
        }
        printf("Please enter an integer: ");
        scanf("%d",&t);
    }
}