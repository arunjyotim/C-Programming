#include <stdio.h>
int main()
{
    int a[] = {8, 3, 8, 5, 4, 3, 4, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    printf("The given array is: 8 3 8 5 4 3 4 3 5\n");

    printf("The element odd number of times: %d times.\n", OddCounter(a, n));
    return 0;
}

int OddCounter(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {

        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }
        if (count % 2 != 0)
            return a[i];
    }
    return -1;
}

