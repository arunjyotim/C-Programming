#include <stdio.h>
int Summation(int n);
int main() {
    int num;
    printf("Enter a integer: ");
    scanf("%d", &num);
    printf("Sum = %d", Summation(num));
    return 0;
}

int Summation(int n) {
    if (n != 0)
        return n + Summation(n - 1);
    else
        return n;
}