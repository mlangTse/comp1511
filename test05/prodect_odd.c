//A program reads 2 positive integers
//and calculates the product of the odd integers between the first and second integers.
//written by MINGLANG XIE 22/3/2019 

#include <stdio.h>


int main (void){
    int low;
    int high;
    
    printf("Enter lower: ");
    scanf("%d", &low);
    
    printf("Enter upper: ");
    scanf("%d", &high);
    
    int num = low + 1;
    int product = 1;
    while (num < high){
        if (num % 2 == 1){
            product = product * num;
        }  
        num++;  
    }
        printf("%d\n", product);
        
    return 0;
}    
        
