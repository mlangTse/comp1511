//A program that reads 2 integers and 
//print their difference
//wrinten by MINGLANG XIE 
//6/3/2019

#include <stdio.h>


int main (void){
    int number_one, number_two;
    scanf("%d %d", &number_one, &number_two);
    if(number_one > number_two){
        printf("%d\n", number_one - number_two);
        }else if(number_two > number_one){
            printf("%d\n", number_two - number_one);
        }else{
            printf("equal\n");
            }
    return 0;
    }
