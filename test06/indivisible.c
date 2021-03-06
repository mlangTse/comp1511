#include <stdio.h>
#define MAX 1000

void sort(int num[MAX], int num1[MAX]);

int main (void){
    int num[MAX] = {0};
    int num1[MAX] = {0};
    int num2[MAX] = {0};
    int count = 0;
    int div_count = 0;
    while (scanf("%d", &num[count]) == 1){
        count++;
    }
    count = 0;
    while (count < MAX){
        num2[count] = num[count];
        count++;
    }
    count = 0;
    sort(num, num1);
    printf("Indivisible numbers: ");
    while (count < MAX){
        div_count = count + 1;
        while (div_count < MAX){
            if (num1[count] != 0 && num1[div_count] !=0){
                if (num1[count] == num1[div_count]){
                    num1[count] = 0;
                    num1[div_count] = 0;
                } else if (num1[count] % num1[div_count] == 0){
                    num1[count] = 0;
                }   
            }    
            div_count++;
        }
        count++;        
    }        
    count = 0;
    while (count < MAX){
        div_count = 0;
        while (div_count < MAX){
            if (num2[count] != 0 && num1[div_count] !=0){
                if (num2[count] == num1[div_count]){
                    num[count] = num2[count];
                }  
            }    
            div_count++;
        }
        if (num[count] != 0){
            printf("%d ", num[count]);
        }    
        count++;        
    }                 
    printf("\n");  
    return 0;
}   

void sort(int num[MAX], int num1[MAX]){
    int max = 42;
    int i = 0;
    int j = 0;
    int t = 0;
    while (t < MAX){
        i = 0;
        while (i < MAX){
            if(((i < MAX - 1 && num[i] >= num[i + 1]) || (i > 0 && num[i] >= num[i - 1])) && num[i] >= num[j]){
                j = i;
                max = num[i];
            }
            i = i + 1;
        }
        num[j] = 0;
        num1[t] = max;
        t++;
    }        
}
