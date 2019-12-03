// A program that reads 3 integers 
//and prints them from small to larger
//written by MINGLANG XIE 16/3/2019

#include<stdio.h>


int main(void){
    int n, n2, n3;
    printf("Enter integer: ");
    scanf("%d",&n);
    printf("Enter integer: ");
    scanf("%d",&n2);
    printf("Enter integer: ");
    scanf("%d",&n3);
 
    printf("Middle: %d\n", (((((n>=n2) && (n<=n3)) || ((n<=n2) && (n>=n3))) * n + (((n2>n) && (n2<=n3)) || ((n2<n) && (n2>=n3))) * n2 + (((n3>n2) && (n3<n)) || ((n3<n2) && (n3>n))) * n3)));
    
    return 0;
    }
