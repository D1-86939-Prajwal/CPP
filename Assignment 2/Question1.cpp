#include <iostream>
using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Parameterless constructor
    Box() {
        length = 1;
        width = 1;
        height = 1;
    }

    // Parameterized Constructor with a single parameter
    Box(double side) {
        length = side;
        width = side;
        height = side;
    }

    // Parameterized Constructor with three parameters
    Box(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    // Function to calculate the volume of the box
    double calculateVolume() {
        return length * width * height;
    }
};

int main() {
    int choice;

    // Menu for the user to interact
    do {
        cout << "\nMenu for calculating the volume:\n";
        cout << "1: Calculate the volume with default values\n";
        cout << "2: Calculate the volume with the same length, width, and height\n";
        cout << "3: Calculate the volume with different values for length, width, and height\n";
        cout << "4: Exit the menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Box box;
                cout << "Volume calculated with default values is " << box.calculateVolume() << endl;
                break;
            }
            case 2: {
                double side;
                cout << "Enter the value for length, width, and height: ";
                cin >> side;
                Box box(side);
                cout << "Volume calculated with the same values is " << box.calculateVolume() << endl;
                break;
            }
            case 3: {
                double length, width, height;
                cout << "Enter the length: ";
                cin >> length;
                cout << "Enter the width: ";
                cin >> width;
                cout << "Enter the height: ";
                cin >> height;
                Box box(length, width, height);
                cout << "Volume calculated with different values is " << box.calculateVolume() << endl;
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
