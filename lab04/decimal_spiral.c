#include <stdio.h>

//This is incorrect, the following is the correct code
int main (void){
    int n;
    int counter, sec_counter;
    int line = 1;
    printf("Enter size: ");
    scanf("%d", &n);
    
    counter = (n - 1) * (n + 1) / 2 + n - 1;
    
    while (counter > 9){
        counter = counter - 10;
    }
    
       while (line <= n){
        int row = 1;
        int length = 1;
        while (row <= n){
            if (row == 2 * length - 1 && line != 2 * length && line < n - 2 * length + 1){
                printf("%d", counter);
                counter = counter - 1;
                if(counter < 0){
                    counter = counter + 10;
                } else if(counter > 9){
                    counter = counter - 10;
                }        
                length = length + 1;
            } else if (row > n - 2 * length  && row % 2 == 1 && row != line - 1){
                printf("*");
                length = length + 1;
            } else if (row == n - line && line % 2 == 0 && row < n - 2 * length){ 
                printf("*");
                length = length + 1;
            } else if(line % 2 == 1 && row >= line - 1 && row <= n - line + 1){
                printf("%d", counter);
                counter = counter - 1;
                if(counter < 0){
                    counter = counter + 10;
                } else if(counter > 9){
                    counter = counter - 10;
                }
            } else if (line > n / 2 + 1 && line % 2 == 1 && row <= line && row >= n - line + 1){
                printf("*");
            } else {
                printf("-");
            }
            row = row + 1;
        }   
        printf("\n");
        line = line + 1;
    }         
    return 0;
    }

//The code below should be the correct answer, it is from someone else
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printblank(int y);
void printsigns(int x, int t);
void printright(int width, int z);
void printleftdown(int width, int z);
void printblankdown(int width, int z);
int  random_number();  //generating ridiculous random number to start
int  generate_number(int t);


int main(void){
    int size, width, height;
    int x,y;   // z = width-x width-y
    int z = 0; //but without initialization it also works
    int drawheight = 1; // add 1 each step
    int odd_height = 1; // add 1 each step
    int evenheight = 1; // add 2 each step
    int r = random_number();
    int t = 1;

    printf("Enter size: ");
    scanf("%d",&size);

    width = size;
    height = size;

    while(drawheight <= (height-1)/2){
        if(drawheight%2 == 0){
            z = evenheight;
            y = width - 2 * evenheight;
            if(z == 1){
                printf("-");
            }else{
                printright(width,z-2);
                printf("--");
            }
            printblank(y);
            printright(width,z);
            printf("\n");
            evenheight = evenheight + 2;
        }else{
            z = odd_height;
            x = width - 2 * odd_height;
            if(z == 1){
                printf("%d",r);
            }else{
                printright(width,z-2);
                printf("%d%d",r,r);
            }
            printsigns(x,t);
            printright(width,z);
            printf("\n");
            odd_height = odd_height + 2;
        }
        drawheight++;
    }
    
    if((height-5)%4 == 0){
        printright(width,z);
        printf("%d",r);
        printright(width,z+2);
        printf("\n");
    }else{
        printright(width,z-2);
        printf("---");
        printright(width,z);
        printf("\n");
    }
    drawheight++;                // print the middle side, while "5","9"."13","17" is "*", and "7","9"... is "---"

    evenheight = evenheight - 2;
    odd_height = odd_height - 2; //since the last step add an extra two in the while loop before, we need to subtract two:)

    while(drawheight <= height){
        if(drawheight%2 == 0){
            z = evenheight;
            y = width - 2 * evenheight;
            printleftdown(width,z);
            printblank(y);
            printright(width,z);
            printf("\n");
            evenheight = evenheight - 2;
        }else{
            z = odd_height;
            x = width - 2 * odd_height;
            printleftdown(width,z);
            printsigns(x,t);
            printright(width,z);
            printf("\n");
            odd_height = odd_height - 2;
        }
        drawheight++;
    }

    return 0;
}

void printsigns(int x, int t){
    int num;
    int counter = 0;
    while(counter < x){
        num = generate_number(t);
        printf("%d",num);
        t = num;
        counter++;
    }
}

void printblank(int y){
    int counter = 0;
    while(counter < y){
        printf("-");
        counter++;
    }
}

void printright(int width, int z){
    int r = random_number();
    int counter = width;
    while(counter > width - z){
        if(counter%2 == 0){
            printf("-");
        }else{
            printf("%d",r);
        }
    counter--;
    }
}

void printleftdown(int width, int z){
    int r = random_number();
    int counter = width;
    while(counter > width - z){
        if(counter%2 == 0){
            printf("-");
        }else{
            printf("%d",r);
        }
    counter--;
    }
}

void printrightdown(int width, int z){
    int r = random_number();
    int counter = width;
    while(counter > width - z){
        if(counter%2 == 0){
            printf("%d",r);
        }else{
            printf("-");
        }
    counter--;
    }
}

int random_number(){
    int result = 0;
    int i = 0;

    srand(time(NULL));
    result = result + rand()%100 +1;
    result = result % 10;
    result = 0;

    return result;
}

int generate_number(int t){
    int x;
    
    if(t == 0){
        x = 9;
    }else{
        x = t - 1;
    }

    return x;
}
*/
