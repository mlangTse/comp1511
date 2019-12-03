#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main (void){
    int number[MAX] = {0};
    int f_number[MAX] = {0};
    int n_appear[MAX] = {0};
    int a_count = 0;
    int f_count = 0;
    int count = 0;
    int n_count = 0;
    int max = 0;
    int max_count = 0;
    
    while(scanf("%d", &number[n_count]) == 1){
        n_count++;
    } 
    
    for (int i = 0; i < n_count; i++){
        count = 0;
        for (int k = 0; k < n_count; k++){
            if (number[k] == number[i] & k != i){
                count++;
            }
        } 
        if (count > 0){
            f_number[f_count++] = number[i];
            n_appear[a_count++] = count;
        }
    }
    
    if (f_count == 0 && f_number[0] != 0){
        printf("%d\n", f_number[0]);
    } else if (f_count > 0){
        for (int i = 0; i < a_count / 2; i++){
            for (int k = 0; k < a_count / 2; k++){
                if (n_appear[k] >= n_appear[i] && n_appear[k] > max){
                    max = n_appear[k];
                    max_count = k;
                } else if (n_appear[k] == n_appear[i] && n_appear[k] == max){
                    if (f_number[k] > f_number[i]){
                        max_count = k;
                        k = a_count;
                    } else if (f_number[k] < f_number[i]){
                        max_count = i;
                        k = a_count;
                    }        
                }
            }    
        }
        printf("%d\n", f_number[max_count]);
    } else {
        printf("%d\n", number[n_count - 1]);
    }    
    return EXIT_SUCCESS;
}                                    
