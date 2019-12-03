#include <stdio.h>
#include <stdlib.h>

int swap(int ch, char *argv[]);

int main(int argc, char *argv[]){
    int ch= getchar();
    while (ch!= EOF){
        ch= swap(ch, argv);
        putchar(ch);
        ch= getchar();
    }    
    return 0;
}

int swap(int ch, char *argv[]){
    int count = 0;
    int ch2 = ch;
    if (ch >= 'A' && ch <= 'Z'){
        ch2 = ch;
        ch = ch + 'a' - 'A';
    }
    while (count < 26){
        if (argv[1][count] == ch){
            if (ch2 >= 'A' && ch2 <= 'Z'){
                ch = 'A' + count;
            } else if (ch2 >= 'a' && ch2 <= 'z'){
                ch = 'a' + count; 
            }  
            count = 26; 
        }
        count++;
    }                
    return ch;
}
