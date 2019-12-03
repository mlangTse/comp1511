// A program that reads 3 integers 
//and prints them from small to larger
//written by MINGLANG XIE 4/3/2019

#include<stdio.h>


int main(void){
    int integer1,integer2,integer3;
    printf("Enter integer: ");
    scanf("%d",&integer1);
    printf("Enter integer: ");
    scanf("%d",&integer2);
    printf("Enter integer: ");
    scanf("%d",&integer3);
    if(integer1 <= integer2  && integer2 <= integer3){
        printf("The integers in order are: %d %d %d\n",integer1,integer2,integer3);
    }else if(integer1 <= integer3  && integer3 <= integer2){
        printf("The integers in order are: %d %d %d\n",integer1,integer3,integer2);
    }else if(integer2 <= integer1  && integer1 <= integer3){
        printf("The integers in order are: %d %d %d\n",integer2,integer1,integer3);
    }else if(integer2 <= integer3  && integer3 <= integer1){
        printf("The integers in order are: %d %d %d\n",integer2,integer3,integer1);
    }else if(integer3 <= integer2  && integer2 <= integer1){
        printf("The integers in order are: %d %d %d\n",integer3,integer2,integer1);
    }else if(integer3 <= integer1  && integer1 <= integer2){
        printf("The integers in order are: %d %d %d\n",integer3,integer1,integer2);
    }
    return 0;
    }
