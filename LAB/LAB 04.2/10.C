#include <stdio.h>
int main()
{

    double sales[ 4 ][ 5 ] = { 0.0 };
    double proSales[ 4 ] = { 0.0 };
    double value, totalSales;
    int person, product;
    int i, j;

    printf("Enter the salesperson(1 - 4), product(1 - 5), and total sales.\n" );
    printf("Enter -1 for the salesperson to end input.\n" );
    scanf("%d", &person );


    while (person != -1 )
    {
        scanf( "%d%lf", &product, &value );
        sales[person][product] = value;
        scanf("%d", &person);

    }


    printf("\n%s\n%s\n%s\n%s\n%s\n", "The total sales for each salesperson",
    "are displayed at the end of each", "row, and the total sales for each",
    "product are displayed at the bottom ", "of each column.\n" );
    printf( " %11d%8d%8d%8d%8d%11s\n", 1, 2, 3, 4, 5, "Total" );


    for(i = 0; i <= 3; i++ )
    {
        totalSales = 0.0;
        printf("%6d", i+1);

        for (j=0; j<=4; j++ )
        {
            totalSales += sales[i][j];
            printf("%8.2f", sales[i][j]);
            proSales[j] += sales[i] [j];
        }
        printf("%8.2f\n", totalSales );
    }
    printf("\nTotal " );

    for ( j = 0; j <= 4; j++ )
    {
        printf("%8.2f", proSales[ j ] );
    }
    printf("\n\n");
    return 0;

 }

