#include <stdio.h>
int main() {
    char p[100], q[100], i;
    printf("Enter String you want to print:\n");
    gets(p);
    printf("Entered string: %s \n\n", p); 
   
   for ( ; p[i] != '\0';i++) {
       q[i] = p[i];
    }
    q[i] = '\0';
    printf("Copied string : %s", q);
    return 0;
}