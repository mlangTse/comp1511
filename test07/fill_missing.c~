#include <stdio.h>

#define MAX 10000

int main (void){
    int integer[MAX] = {0};
    int integer2[MAX] = {0};
    int largest = 0;
    int i = 0;
    int count = 0;
    while (scanf("%d", &integer[i]) == 1){
        i++;
    }
    i = 0;
    while (i < MAX){
        if (integer[i] > largest){
            largest = integer[i];
        }
        i++;
    }
    while (count < largest){
        integer2[count] = count + 1;
        count++;
    }
    count = 0;
    while (count < largest){
        int k = 0;
        while (k < MAX){
            if (integer[k] == integer2[count] && integer[k] != 0){
                integer2[count] = 0;
            }
            k++;
        }
        count++;
    }
    count = 0;
    while (count < largest){
        if (integer2[count] !=0){
            printf("%d ", integer2[count]);
        }
        count++;
    }  
    printf("\n");                   
    return 0;
}
