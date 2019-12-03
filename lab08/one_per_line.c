#include <stdio.h>

#define MAX_LINE 4096

int main(void){
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stdin) != NULL){
    }   
    printf("Enter a string: ");     
    for (int i = 0; line[i] != '\n'; i++){
        printf("%c\n", line[i]);
    }
    return 0;    
}    
