//A program that reads an integer size 
//and prints a pattern of asterisks in the shape of an "L"
//written by MINGLANG XIE 16/3/2019

#include <stdio.h>


int main (void){
    int size;
    int line = 0;
    printf("Enter size: ");
    scanf("%d", &size);
    
    while (line < size){
        int row = 0;
        while (row < size){
            if (row == 1 || line == size - 1){
                printf("*");
                }
            row = row + 1;
        }    
        printf("\n");
        line = line + 1;
    }
    return 0;
}
