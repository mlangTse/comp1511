//A program that reads a integer n from standard input
//and prints the decomposition of n into prime factors.
//written by MINGLANG XIE 22/3/2019

#include <stdio.h>


int main (void){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    int k=1;
    int n_factor = 0;
    while (k < n){
        if(n % k == 0){
            n_factor++; 
        }        
        k++;
    }            
      
    if (n_factor > 2){
        printf("The prime factorization of %d is: \n", n);
    } else {
        printf("%d is prime\n", n);
    } 
     
    int t = 1;
    int n2 = n;
    int c = 0;
    int counter = 0;
    if (n_factor > 2){
        while (t <= n2){
            
            int t2 = 1;
            counter = 0;
            while (t2 <= t){
                if (t % t2 == 0){
                  counter++;
                }
                t2++;
            }
            if (counter <= 2 && c == 0 && n2 % t == 0 && t != 1){
                printf("%d ", t);
                n2 = n2 / t;
                t = 1;
                c = 1;
            } else if (counter <= 2 && c == 1 && n2 % t == 0 && t != 1){
                    printf("* %d ", t);
                    n2 = n2 / t;
                    t = 1;
            }
            if (n2 == 1){
                printf("= %d\n", n);
                t = n;
            }            
            t++;
        }
    }                                              
    
    return 0;
}    
