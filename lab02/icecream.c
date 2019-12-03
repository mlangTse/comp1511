#include<stdio.h>


int main(void){
    int numberOfscoops, cost;
    printf("How many scoops? ");
    scanf("%d",&numberOfscoops);
    printf("How many dollars does each scoop cost? ");
    scanf("%d",&cost);
    if (numberOfscoops*cost <= 10){
    printf("You have enough money!\n");
    }else{
    printf("Oh no, you don't have enough money :(\n");
    }
    return 0;
    }
