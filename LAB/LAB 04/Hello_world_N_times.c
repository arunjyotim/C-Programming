#include<stdio.h>
void myname(int countdown) {
   printf("My name is Eric\n");
   if (--countdown > 0) myname(countdown);
} 
int main() {
   myname(15);
}