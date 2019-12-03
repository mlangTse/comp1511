#include <stdio.h>
#include <stdlib.h>

int remove_duplicates(int length, int source[length], int destination[length]){
    int d_count = 0;
    int count;
    int n_count = 0;
    destination[0] = source[0];
    for (int i = 0; i < length; i++){ 
        count = 0;
        for (int k = 0; k < d_count; k++){
            if (destination[k] == source[i]){
                count++;
            }
        }
        if (count == 0){
            destination[d_count++] = source[i];
            n_count++;
        }
    }
    return n_count;
}    
