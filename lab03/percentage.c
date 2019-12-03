// A program that reads the total mark in the exam
//and the marks that student was awarded, and print them in percentage
//written by MINGLANG XIE 4/3/2019

#include<stdio.h>


int main(void){
    int total_mark;
    double mark;
    printf("Enter the total number of marks in the exam: ");
    scanf("%d",&total_mark);
    printf("Enter the number of marks the student was awarded: ");
    scanf("%lf",&mark);
    printf("The student scored %.0lf %% in this exam.\n",(mark/total_mark)*100);
    return 0;
    }
