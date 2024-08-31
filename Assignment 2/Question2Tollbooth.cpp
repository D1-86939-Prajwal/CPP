#include <iostream>
using namespace std;

class tollbooth{
    private:
    unsigned payingcars;
    unsigned totalcars;
    unsigned nonpayingcars;
    double totalmoneycollected;

    public:
    tollbooth(){
        payingcars = 0;
        totalcars = 0;
        nonpayingcars = 0;
        totalmoneycollected = 0;
    }

    void payingCar(){
        payingcars++;
        totalcars++;
        totalmoneycollected += 0.5;

    }
    
    void nonpayingCar(){
        totalcars++;
        nonpayingcars++;
    }

    void printOnConsole(){
        cout<<"The no of paying cars are "<<payingcars<<endl;
        cout<<"The no of non paying cars are "<< nonpayingcars<<endl;
        cout<<"The total no of cars are "<< totalcars<<endl;
        cout<<"The total no of money collected is "<< totalmoneycollected<<endl;
    }
};


int main(){
    tollbooth booth;
    int choice;

    do {
        cout << "\nTollBooth Menu \n";
        cout << "1: Paying car\n";
        cout << "2: Non Paying car\n";
        cout << "3: Display all the collected data\n";
        cout << "4: Exit the menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                booth.payingCar();
                break;
            }
            case 2: {
                booth.nonpayingCar();
                break;
            }
            case 3: {
                booth.printOnConsole();
                break;
            }
            case 4:
                cout << "Exiting the menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

