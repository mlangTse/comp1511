#include <stdio.h>
#define MAX 10

int main (void){
    int num[MAX] = {0};
    int odd_num[MAX] = {0};
    int even_num[MAX] = {0};
    int count = 0;
    int even_count = 0;
    int odd_count = 0;
    while (count < MAX){
        scanf("%d", &num[count]);
        count++;
    }
    count = 0;
    while (count < MAX){
        if (num[count] % 2 == 0){
            even_num[even_count] = num[count];
            even_count++;
        } else if (num[count] % 2 == 1){
            odd_num[odd_count] = num[count];
            odd_count++;
        }
        count++;
    }
    odd_count = 0;
    printf("Odd numbers were: ");
    while (odd_count < MAX && odd_num[odd_count] != 0){
        printf("%d ", odd_num[odd_count]);   
        odd_count++;
    }    
    printf("\n");
    even_count = 0;
    printf("Even numbers were: ");
    while (even_count < MAX && even_num[even_count] != 0){
        printf("%d ", even_num[even_count]);   
        even_count++;
    } 
    printf("\n");              
    return 0;
}
