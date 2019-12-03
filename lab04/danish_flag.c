#include <stdio.h>


int main (void){
    int size;
    printf("Enter the flag size: ");
    scanf("%d", &size);
    int high = 1;
    while(high <= 2*2*size){
        int wide = 1;
        if(high != 2*size && high !=2*size+1){
            while(wide <= 3*3*size){
                if(wide < 3*size){
                  printf("#");
                }else if (wide == 3*size || wide == 3*size + 1){
                  printf(" ");
                }else if (wide > 3*size || wide <= 2*3*size){
                  printf("#");
                }else if (wide <= 3*3*size){
                   printf("#");
                }
                wide = wide + 1;
            }
            }else {
                while(wide <= 3*3*size){
                    printf(" ");
                    wide = wide + 1;
                    }
            }
            printf("\n");
            high = high + 1;
        }
    return 0; 
    }
            
            
            
            
                
            
            
            
            
            
