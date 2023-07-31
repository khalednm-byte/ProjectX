#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int IDnumber(FILE *fptr);
void dataBase(int age, char names[100], FILE *fptr);
//FILE *fptr;

int main(){

    //int rand = 10000;
    char names[100];
    int ages;
    FILE *fptr; //file to hold all system information


//Name entry
printf("Enter Name : ");
scanf("%s", &names);

//Age entry
printf("Enter Age : ");
scanf("%d", &ages);

printf("Welcome %s\nYou're %d years old\n", names, ages);

//Appends all info to system DataBase
dataBase(ages, names, fptr) ;

//Generate an ID number for user that starts with the last two digits of the year registered 
IDnumber(fptr);

return 0;



}

int IDnumber(FILE *fptr){
    srand(time(NULL)); // Initialize the random number generator with the current time

    int number = 23000000 + rand() % 1000000; // Generate a random number between 23000000 and 23999999

    printf("Your generated number is %08d\n", number); // Print the number with leading zeros to make it 8 digits

    fptr = fopen("dataB.txt", "a");
    fprintf(fptr,"ID = %08d\n==============================\n", number);
    fclose(fptr) ;

    

}

void dataBase(int age, char names[100], FILE *fptr){
    
    fptr = fopen("dataB.txt", "a");

    fprintf(fptr, "\n==============================\nName : %s\nAge : %d\n", names, age);

    fclose(fptr) ;
}