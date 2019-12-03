#include<stdio.h>


int main(void){
    int age;
    printf("Enter your age: ");
    scanf("%d",&age);
    if(age>=18){
    printf("Your dating range is %d to %d years old.\n", age/2+7,age+(age-(age/2+7))*2);
    }else{
    printf("You are too young to be dating.\n");
    }
    return 0;
    }
