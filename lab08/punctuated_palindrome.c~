#include <stdio.h>
#include <string.h>

#define MAX_LINE 4096

int main(void){
    char line[MAX_LINE];
    char cpy_line[MAX_LINE] = "\0";
    int length = 0;
    int cpy_count = 0;
    int count = 0;
    printf("Enter a string: ");
    while(fgets(line, MAX_LINE, stdin) != NULL);
    length = strlen(line) - 1;
    for (int i = 0; i < length; i++){
        if (line[i] >= 'A' && line[i] <= 'Z'){
            line[i] = line[i] - 'A' + 'a';
            cpy_line[cpy_count++] = line[i];
        } else if (line[i] >= 'a' && line[i] <= 'z'){
            cpy_line[cpy_count++] = line[i];
        }
    }    
    int cpy_length = strlen(cpy_line) - 1;
    for (int i = 0; i <= cpy_length / 2; i++){
        if (cpy_line[i] == cpy_line[cpy_length - i]){
            count++;
        }
    }
    if (count - 1 == cpy_length / 2){
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    } 
  
    return 0;
}    
