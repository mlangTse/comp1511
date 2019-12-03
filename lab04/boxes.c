#include <stdio.h>


int main (void){
    int n;
    int line = 1;
    printf("How many boxes: ");
    scanf("%d", &n);
    
    while (line <= 4*n-1){
        int row = 1;
        int boxes_length = 1;
        while (row <= 4*n-1){
            if (((row < 2*boxes_length && line % 2 == 1) || ((line <= 4*n/2) && (row < line && line % 2 == 0)) || ((line > 4*n/2) && (row < line - 2*(line - 4*n/2) && line % 2 == 0)) || (row <= 4*n-1 && row >4*n-2*boxes_length + 1)) && row % 2 == 1){
                printf("#");
                boxes_length =boxes_length + 1;
            } else if ((line % 2 == 1 && (row >= line && row <= 4*n-line)) || ((line > 4*n/2) && (line % 2 == 1 && (row >= line - 2*(line - 4*n/2) && row <= 4*n-line + 2*(line - 4*n/2))))){
                printf("#");
            } else if (row >= 2 && row < 4*n-1){
                printf(" ");
            }
            row = row + 1;
        }
        printf("\n");
        line = line + 1;
    }

    return 0;
    }
