#include <iostream>
using namespace std ;

struct Date {
    int day;
    int month;
    int year;


// To initialize the date with default values
void initDate() {
    day = 1;
    month = 12;
    year = 2000;
}

// To print the date on the console 
void printDateOnConsole() {
    cout<<"Date is: %d/%d/%d\n", day , month , year;
}

// To accept the date from the user from the console 
void acceptDateFromConsole() {
    cout<<"Enter the day :";
    cin>>day;

    cout<<"Enter the month :";
    cin>>month;

    cout<<"Enter the year :";
    cin>>year;
    }
};

int main() {
    struct Date mydate;
    int choice;

    // Menu for the user to interact
    do {
        cout<<"Menu \n";
        cout<<"1 : Initialise the date \n";
        cout<<"2 : Print the date \n";
        cout<<"3 : Accept the date \n";
        cout<<"4 : Exit the menu \n";
        cout<<"Enter your choice :";
        cin>>choice;

        switch (choice) {
            case 1:
                mydate.initDate();
                cout<<"Date initialised Successfully \n";
                break;

            case 2:
                mydate.printDateOnConsole();
                break;

            case 3:
                mydate.acceptDateFromConsole();
                break;

            case 4:
                cout<<"Exiting the Menu ..\n";
                break;

            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
