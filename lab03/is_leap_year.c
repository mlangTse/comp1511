// A program that reads the year
// and tell the reader it's a leap year or not
//written by MINGLANG XIE 4/3/2019

#include<stdio.h>


int main(void){
    int year;
    printf("Enter year: ");
    scanf("%d",&year);
    if((year%4 == 0 && year%100 != 0) || (year%400 == 0 && year%100 != 0) || (year%400 == 0 && year%4 == 0)){
        printf("%d is a leap year.\n",year);
        }else {
        printf("%d is not a leap year.\n",year);
        }
        return 0;
        }
