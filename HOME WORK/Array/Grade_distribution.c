#include <stdio.h>
#define length 11

int main (){
    int grade[100],star[length]={0};
    int n, i, j,highest,lowest;
    float sum=0, average;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter the grades: \n");
    for(i=0; i<n; i++) {
        scanf("%d", &grade[i]);
        sum=sum+grade[i];

        if(grade[i]>=0 && grade[i]<10) {
            star[0]++;
        }
        else if(grade[i]>=10 && grade[i]<20) {
            star[1]++;
        }
        else if(grade[i]>=20 && grade[i]<30) {
            star[2]++;
        }
        else if(grade[i]>=30 && grade[i]<40) {
            star[3]++;
        }
        else if(grade[i]>=40 && grade[i]<50) {
            star[4]++;
        }
        else if(grade[i]>=50 && grade[i]<60) {
            star[5]++;
        }
        else if(grade[i]>=60 && grade[i]<70) {
            star[6]++;
        }
        else if(grade[i]>=70 && grade[i]<80) {
            star[7]++;
        }
        else if(grade[i]>=80 && grade[i]<90) {
            star[8]++;
        }
        else if(grade[i]>=90 && grade[i]<100) {
            star[9]++;
        }
        else if(grade[i]==100) {
            star[10]++;
        }
    }
    lowest=highest=grade[0];
    for(i=0; i<n; i++)
    {
        if(lowest>grade[i])
        {
            lowest=grade[i];
        }
        if(highest<grade[i])
        {
            highest=grade[i];
        }
    }

    average=sum/n;

    printf("\n\nWelcome to the grade book for\n");
    printf("CSE103 Introduction to C Programing!\n");
    printf("\nThe grades are:\n\n");

    for(i=0; i<n; i++) {
        printf("Student %d: %d\n",i+1,grade[i]);
    }

    printf("\nClass average is %.2f\n", average);
    printf("Lowest grade is %d\n", lowest);
    printf("Highest grade is %d\n", highest);

    printf("\nGrade distribution:\n");

    for(i=0; i<length; i++) {
        if(i==0) {
            printf("  %d-%d: ", (i*10), (i*10)+9);
        }
        else if(i<length-1 && i!=0) {
            printf("%d-%d: ", (i*10), (i*10)+9);
        }
        else {
            printf("  %d: ", (i*10));
        }
        for(j=0; j<star[i]; j++) {
            printf("%c",'*');
        }
        printf("\n");
    }
    return 0;
 }