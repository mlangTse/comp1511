#include<stdio.h>

int main(int argc, char *argv[]){
    int ch = getchar();
    while (ch != EOF){
        if (ch >= '0' && ch <='9'){ 
            int n = ch - '0';
            ch = argv[1][n];
            putchar(ch);
        } else {
            putchar(ch);
        }
        ch = getchar();
    }
    return 0;
}
