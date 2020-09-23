#include<stdio.h>


int main(void){
    int number1,number2;
    printf("Please enter two integers: ");
    scanf("%d%d",&number1,&number2);
    if(number1 == -10){
    printf("negative ten ");
    }  if(number1 == -9){
    printf("negative nine ");
    }  if(number1 == -8){
    printf("negative eight ");
    }  if(number1 == -7){
    printf("negative seven ");
    }  if(number1 == -6){
    printf("negative six ");
    }  if(number1 == -5){
    printf("negative five ");
    }  if(number1 == -4){
    printf("negative four ");
    }  if(number1 == -3){
    printf("negative three ");
    }  if(number1 == -2){
    printf("negative two ");
    }  if(number1 == -1){
    printf("negative one ");
    }  if(number1 == 0){
    printf("zero ");
    }  if(number1 == 10){
    printf("ten ");
    }  if(number1 == 9){
    printf("nine ");
    }  if(number1 == 8){
    printf("eight ");
    }  if(number1 == 7){
    printf("seven ");
    }  if(number1 == 6){
    printf("six ");
    }  if(number1 == 5){
    printf("five ");
    }  if(number1 == 4){
    printf("four ");
    }  if(number1 == 3){
    printf("three ");
    }  if(number1 == 2){
    printf("two ");
    }  if(number1 == 1){
    printf("one ");
    }  else if(number1>10 || number1<-10){
    printf("%d ",number1);
    }
    printf("+ ");
     if(number2 == -10){
    printf("negative ten ");
    }  if(number2 == -9){
    printf("negative nine ");
    }  if(number2 == -8){
    printf("negative eight ");
    }  if(number2 == -7){
    printf("negative seven ");
    }  if(number2 == -6){
    printf("negative six ");
    }  if(number2 == -5){
    printf("negative five ");
    }  if(number2 == -4){
    printf("negative four ");
    }  if(number2 == -3){
    printf("negative three ");
    }  if(number2 == -2){
    printf("negative two ");
    }  if(number2 == -1){
    printf("negative one ");
    }  if(number2 == 0){
    printf("zero ");
    }  if(number2 == 10){
    printf("ten ");
    }  if(number2 == 9){
    printf("nine ");
    }  if(number2 == 8){
    printf("eight ");
    }  if(number2 == 7){
    printf("seven ");
    }  if(number2 == 6){
    printf("six ");
    }  if(number2 == 5){
    printf("five ");
    }  if(number2 == 4){
    printf("four ");
    }  if(number2 == 3){
    printf("three ");
    }  if(number2 == 2){
    printf("two ");
    }  if(number2 == 1){
    printf("one ");
    }  else if(number2>10 || number2<-10){
    printf("%d ",number1);
    }
    printf("= ");
    if(number1+number2 == -10){
    printf("negative ten\n");
    }if(number1+number2 == -9){
    printf("negative nine\n");
    }if(number1+number2 == -8){
    printf("negative eight\n");
    }if(number1+number2 == -7){
    printf("negative seven\n");
    }if(number1+number2 == -6){
    printf("negative six\n");
    }if(number1+number2 == -5){
    printf("negative five\n");
    }if(number1+number2 == -4){
    printf("negative four\n");
    }if(number1+number2 == -3){
    printf("negative three\n");
    }if(number1+number2 == -2){
    printf("negative two\n");
    }if(number1+number2 == -1){
    printf("negative one\n");
    }if(number1+number2 == 0){
    printf("zero\n");
    } if(number1+number2 == 10){
    printf("ten\n");
    }if(number1+number2 == 9){
    printf("nine\n");
    }if(number1+number2 == 8){
    printf("eight\n");
    }if(number1+number2 == 7){
    printf("seven\n");
    }if(number1+number2 == 6){
    printf("six\n");
    }if(number1+number2 == 5){
    printf("five\n");
    }if(number1+number2 == 4){
    printf("four\n");
    }if(number1+number2 == 3){
    printf("three\n");
    }if(number1+number2 == 2){
    printf("two\n");
    }if(number1+number2 == 1){
    printf("one\n");
    }
    else if(number1+number2>10 || number1+number2<-10){
    printf("%d\n",number1+number2);
    }
    return 0;
    }

/*
the other version by using loop
#include <stdio.h>

int main(void) {
    int num1, num2, added;
    printf("Please enter two integers:");
    scanf("%d%d", &num1, &num2);

    added = num1 + num2;
    int nums[3] = {num1, num2, added};

    for (int i = 0; i < 3; i++) {
        if (nums[i] < 0 && nums[i] <= 10 && nums[i] >= -10) {
            nums[i] *= -1;
            printf("negative ");
        } else if (nums[i] > 10 || nums[i] < -10){
            printf("%d ", nums[i]);
        }
        if(nums[i] == 0){
            printf("zero ");
        } else if(nums[i] == 10){
            printf("ten ");
        } else if(nums[i] == 9){
            printf("nine ");
        } else if(nums[i] == 8){
            printf("eight ");
        } else if(nums[i] == 7){
            printf("seven ");
        } else if(nums[i] == 6){
            printf("six ");
        } else if(nums[i] == 5){
            printf("five ");
        } else if(nums[i] == 4){
            printf("four ");
        } else if(nums[i] == 3){
            printf("three ");
        } else if(nums[i] == 2){
            printf("two ");
        } else if(nums[i] == 1){
            printf("one ");
        }
        if (i == 0) {
            printf("+ ");
        } else if (i == 1) {
            printf("= ");
        } else {
            printf("\n");
        }
    }
    return 0;
}
*/
