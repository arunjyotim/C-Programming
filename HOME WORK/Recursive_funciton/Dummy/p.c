#include<stdio.h>
int Multiply( int *nptr , int *sptr, int *ans);
int main(){
int x, y, ans=0;
scanf("%d%d",&x,&y);
Multiply(&x,&y,&ans);
printf(" anstiplyplication of two numbers = %d",ans);
return 0;
}
int Multiply(int *nptr, int *sptr, int *ans){
*ans=*nptr * *sptr;
}