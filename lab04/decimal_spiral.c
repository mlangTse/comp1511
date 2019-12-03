#include <stdio.h>


int main (void){
    int n;
    int counter, sec_counter;
    int line = 1;
    printf("Enter size: ");
    scanf("%d", &n);
    
    counter = (n - 1) * (n + 1) / 2 + n - 1;
    
    while (counter > 9){
        counter = counter - 10;
    }
    
       while (line <= n){
        int row = 1;
        int length = 1;
        while (row <= n){
            if (row == 2 * length - 1 && line != 2 * length && line < n - 2 * length + 1){
                printf("%d", counter);
                counter = counter - 1;
                if(counter < 0){
                    counter = counter + 10;
                } else if(counter > 9){
                    counter = counter - 10;
                }        
                length = length + 1;
            } else if (row > n - 2 * length  && row % 2 == 1 && row != line - 1){
                printf("*");
                length = length + 1;
            } else if (row == n - line && line % 2 == 0 && row < n - 2 * length){ 
                printf("*");
                length = length + 1;
            } else if(line % 2 == 1 && row >= line - 1 && row <= n - line + 1){
                printf("%d", counter);
                counter = counter - 1;
                if(counter < 0){
                    counter = counter + 10;
                } else if(counter > 9){
                    counter = counter - 10;
                }
            } else if (line > n / 2 + 1 && line % 2 == 1 && row <= line && row >= n - line + 1){
                printf("*");
            } else {
                printf("-");
            }
            row = row + 1;
        }   
        printf("\n");
        line = line + 1;
    }         
    return 0;
    }
