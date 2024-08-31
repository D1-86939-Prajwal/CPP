#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

// To initialize the date with default values
void initDate(struct Date *ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 7;
    ptrDate->year = 2007;
}

// To print the date on the console 
void printDateOnConsole(struct Date *ptrDate) {
    printf("Date is: %02d/%02d/%04d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

// To accept the date from the user from the console 
void acceptDateFromConsole(struct Date *ptrDate) {
    printf("Enter the day: ");
    scanf("%d", &ptrDate->day);

    printf("Enter the month: ");
    scanf("%d", &ptrDate->month);

    printf("Enter the year: ");
    scanf("%d", &ptrDate->year);
}

int main() {
    struct Date mydate;
    int choice;

    // Menu for the user to interact
    do {
        printf("\nMenu:\n");
        printf("1: Initialize the Date\n");
        printf("2: Print the Date\n");
        printf("3: Accept the Date\n");
        printf("4: Exit the Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initDate(&mydate);
                printf("Date initialized successfully.\n");
                break;

            case 2:
                printDateOnConsole(&mydate);
                break;

            case 3:
                acceptDateFromConsole(&mydate);
                break;

            case 4:
                printf("Exiting the Menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
