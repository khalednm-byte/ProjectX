#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void dataBase(int age, char names[100]);
void IDnumber();

int main() {
    char names[100];
    int ages;

    // File to hold all system information
    FILE *fptr = fopen("dataB.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1; // Exit the program with an error code
    }

    // Name entry
    printf("Enter Name: ");
    fgets(names, sizeof(names), stdin);
    names[strcspn(names, "\n")] = '\0'; // Remove the trailing newline character

    // Age entry
    printf("Enter Age: ");
    scanf("%d", &ages);

    printf("Welcome %s\nYou're %d years old\n", names, ages);

    // Appends all info to the system DataBase
    dataBase(ages, names);

    // Generate an ID number for the user that starts with the last two digits of the year registered
    IDnumber();

    fclose(fptr); // Close the file after writing data

    return 0;
}

void IDnumber() {
    srand(time(NULL)); // Initialize the random number generator with the current time

    int number = 23000000 + rand() % 1000000; // Generate a random number between 23000000 and 23999999

    printf("Your generated number is %08d\n", number); // Print the number with leading zeros to make it 8 digits

    FILE *fptr = fopen("dataB.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return; // Return without writing if file open fails
    }

    fprintf(fptr, "ID = %08d\n==============================\n", number);
    fclose(fptr);
}

void dataBase(int age, char names[100]) {
    FILE *fptr = fopen("dataB.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return; // Return without writing if file open fails
    }

    fprintf(fptr, "\n==============================\nName: %s\nAge: %d\n", names, age);
    fclose(fptr);
}