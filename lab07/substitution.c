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
        count = ch - 'A';
    } else if (ch >= 'a' && ch <= 'z'){
        count = ch - 'a';
    }
    if (ch2 >= 'A' && ch2 <= 'Z'){
        ch =  argv[1][count]; 
        ch = ch - 'a' + 'A';
    } else if (ch2 >= 'a' && ch2 <= 'z'){
        ch =  argv[1][count]; 
    }    
    return ch;
}
