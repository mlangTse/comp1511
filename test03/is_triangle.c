//A program that reads 3 integers and
//indicate whether they can be the sides of a triangle
//wrinten by MINGLANG XIE 
//6/3/2019


#include <stdio.h>


int main (void){
    double first_side, second_side, third_side;
    
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &first_side, &second_side, &third_side);
    
    if(first_side >= second_side && first_side >= third_side && first_side < (second_side + third_side)){
            printf("triangle\n");
        } else if (second_side >= first_side && second_side >= third_side && second_side < (first_side + third_side)){
            printf("triangle\n");
        } else if (third_side >= first_side && third_side >= second_side && third_side < (first_side + second_side)){
            printf("triangle\n");
        } else{
            printf("not a triangle\n");
        }
    
    return 0;
    }
