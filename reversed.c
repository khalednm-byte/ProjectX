#include <stdio.h>

int main(){

int num, reverse = 0;

printf("enter the number you wish to be reversed :");
scanf("%d", &num);

while (num != 0){

    reverse = reverse * 10 + num % 10;
    num /= 10;

}

printf("the reverse is : %d", reverse);

return 0 ;

}