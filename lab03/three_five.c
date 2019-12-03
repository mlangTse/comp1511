// A program that reads that read a number 
//and show that it's modify by 3 or 5 
//written by MINGLANG XIE 4/3/2019

#include<stdio.h>


int main(void){
    int number;
    int count=1;
    printf("Enter number: ");
    scanf("%d",&number);
    while(count<number){
        if((count%3 == 0) || (count%5 == 0)){
        printf("%d\n",count);
        }      
      count=count+1;
        }
        return 0;
        }
