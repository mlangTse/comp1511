#include <stdio.h>


int main (void){
    int n;
    int line = 0;
    printf("Enter size: ");
    scanf("%d", &n);
    while(line < n){
        int row = 1;
        while(row <= n){
            if(row == line + 1 || row == n-line){
                printf("*");
                }else {
                printf("-");
                }
            row = row + 1;
            }
        printf("\n");
        line = line +1;
        }
    return 0;
    }
            
            
        
            
            
            
