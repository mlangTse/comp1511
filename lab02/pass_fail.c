#include<stdio.h>

int main(void){
   int mark;
   printf("Please enter your mark: ");
   scanf("%d",&mark);
   if(mark >= 50 & mark <=100){
   printf("PASS\n");
   }else if(mark < 50){
   printf("FAIL\n");
   }else{
   printf("ERROR\n");
   }
   return 0;
   }
