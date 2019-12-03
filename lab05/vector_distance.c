// COMP1511 Week 5 Lab: Vector Distance
//
// This program was written by MINGLANG XIE (z5228006)
// on 17/03/2019
//
// This program that: reads a positive integer n, reads vector1 and reads vector2
//prints the Euclidean Distance between vector1 and vector2

#include <stdio.h>
#include <math.h>

double euclidean_distance(int size, int array1[size], int array2[size]){
    double sum = 0;
    int i = 0;
    while (i < size){
        sum = sum + (array2[i] - array1[i]) * (array2[i] - array1[i]);
        i = i + 1;
    }    
    sum = sqrt(sum);
    return sum;
    }

int main (void){
    int size;
    printf("Enter vector length: ");
    scanf("%d", &size);
    printf("Enter vector 1: ");
    
    int array1[size];
    int i = 0;
    
    while (i < size){
        scanf("%d", &array1[i]);
        i = i + 1;
    }
    
    printf("Enter vector 2: ");
    
    int array2[size];
    int j = 0;
    
    while (j < size){
        scanf("%d", &array2[j]);
        j = j + 1;
    }    
    
    double distance = euclidean_distance(size, array1, array2);
    printf("Euclidean distance = %lf\n", distance);
    
    return 0;
}


