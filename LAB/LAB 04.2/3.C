#include <stdio.h>

int main()
{
    int i, num, a[200], n;
    i = 1;
    printf("Enter values to count duplicate entries: ");
    scanf("%d", &a[0]);
    num = a[0];
    if (num == -1)
    {
        printf("None");
    }
    else
    {
        while (num != -1)
        {
            scanf("%d", &a[i]);
            num = a[i];
            i++;
        }

        n = num = 0;
        for (int j = 0; j < i - 1; j++)
        {
            if (a[j] == a[j + 1])
            {
                n++;
                num = a[j];
            }
        }
        if (n > 0)
        {
            n += 1;
        }

        printf("%d   %d", num, n);
    }
}