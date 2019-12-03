#include <stdio.h>

int main(void) {
    int ch;
    int ch2;
    double ch_array[26];
    int count = 0;
    double total = 0;
    ch = getchar();
    while (count < 26){
        ch_array[count] = 0;
        count++;
    }
    count = 0;    
    while (ch != EOF){
        ch2=ch;
        if (ch >= 'A' && ch <= 'Z'){
            ch = ch - 'A';
        } else if (ch >= 'a' && ch <= 'z'){
            ch = ch - 'a';
        }
        if (ch2 >= 'A' && ch2 <= 'z'){
            ch_array[ch] = ch_array[ch] + 1;
            total++;
        }
        ch = getchar();
    }
    count = 0;
    while (count < 26){
        printf("'%c' %lf %.lf\n", 'a' + count, ch_array[count]/total, ch_array[count]);
        count++;
    }    
    return 0;
}          
