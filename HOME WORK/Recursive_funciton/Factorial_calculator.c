/* factorial of 5 >     5*4*3*2*1 =120

fact(1) = 1
fact(2) = 2 * 1 = 2 * fact (1)
fact(3) = 3 * 2 * 1 = 3 * fact (2)
fact(4) = 4 * 3 * 2 * 1 = 4 * fact (3)

fact(n) = n * fact(n-1)
*/
Fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * Fact(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d", n, Fact(n));
}