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
        
