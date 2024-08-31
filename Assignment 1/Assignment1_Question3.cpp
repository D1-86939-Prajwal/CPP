#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int marks;

public:
 
    void initStudent() {
        rollNo = 11;
        name = "Raj";
        marks = 99;
    }

    void printStudentOnConsole()  {
        cout << "Student Details:" << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    void acceptStudentFromConsole() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin>>name;
        cout << "Enter Marks: ";
        cin >> marks;
    }
};

int main() {
    Student s1;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Initialize Student" << endl;
        cout << "2. Accept Student Details" << endl;
        cout << "3. Print Student Details" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s1.initStudent();
                cout << "Student initialized with default values.\n";
                break;
            case 2:
                s1.acceptStudentFromConsole();
                break;
            case 3:
                s1.printStudentOnConsole();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
