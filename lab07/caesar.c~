#include <stdio.h>
#include <stdlib.h>

int encrypt(int character, int shift);

int main(int argc, char *argv[]){
    int character = getchar();
    int shift;
    shift = atoi(argv[1]);
    if (shift >= 0){
        shift = shift % 26;
    } else if (shift < 0){
        shift = -shift;
        shift = shift % 26;
        shift = -shift;
    }    
    while (character != EOF){
        character = encrypt(character, shift);
        putchar(character);
        character = getchar();
    }    
    return 0;
}

int encrypt(int character, int shift){
    if (character >= 'A' && character <= 'Z') {
        character = character + shift;
        if (character < 'A'){
            character = 'Z' - ('A' - character - 1);
        } else if (character > 'Z'){
            character = 'A' + (character - 'Z' - 1);
        }        
    } else if (character >= 'a' && character <= 'z') {
        character = character + shift;
        if (character < 'a'){
            character = 'z' - ('a' - character - 1);
        }  else if (character > 'z'){
            character = 'a' + (character - 'z' - 1);
        }   
    }
    return character;
}
