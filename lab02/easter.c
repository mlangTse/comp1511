#include<stdio.h>


int main(void){
    int year;
    int a,b,c,d,e,f,g,h,i,k,l,m,EasterMonth,p,EasterDate;
    printf("Enter Year: ");
    scanf("%d",&year);
    a=year%19;
    b=year/100;
    c=year%100;
    d=b/4;
    e=b%4;
    f=(b+8)/25;
    g=(b-f+1)/3;
    h=(19*a+b-d-g+15)%30;
    i=c/4;
    k=c%4;
    l=(32+2*e+2*i-h-k)%7;
    m=(a+11*h+22*l)/451;
    EasterMonth=(h+l-7*m+114)/31;
    p=(h+l-7*m+114)%31;
    EasterDate=p+1;
    printf("Easter is ");
    if(EasterMonth == 3){
    printf("March ");
    }else if(EasterMonth == 4){
    printf("April ");
    }
    printf("%d in %d.\n",EasterDate,year);
    return 0;
    }
