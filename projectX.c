#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//char names();
//int ages();
int IDnumber();
//void Files();
//FILE *fptr;

int main(){

    //int rand = 10000;
    char names[100];
    int ages;

//Name entry
printf("Enter Name : ");
scanf("%s", &names);

//Age entry
printf("Enter Age : ");
scanf("%d", &ages);

printf("Welcome %s\nYou're %d years old\n", names, ages);

//Generate an ID number for user that starts with the last two digits of the year registered 
IDnumber();


return 0;



}

int IDnumber(){
    srand(time(NULL)); // Initialize the random number generator with the current time

    int number = 23000000 + rand() % 1000000; // Generate a random number between 23000000 and 23999999

    printf("Your generated number is %08d\n", number); // Print the number with leading zeros to make it 8 digits

}