#include <iostream>
using namespace std;

namespace NStudent {
    class Student {
    private:
        int rollNo;
        string name;
        int marks;

    public:
        void initStudent() {
            rollNo = 0;
            name = "Raj";
            marks = 0.0;
        }

        void printStudentOnConsole(){
            cout << "Student Details:" << endl;
            cout << "Roll No: " << rollNo << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
        }

        void acceptStudentFromConsole() {
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin>> name;
            cout << "Enter Marks: ";
            cin >> marks;
        }
    };
}

int main() {
    NStudent::Student s1;
    s1.acceptStudentFromConsole();
    s1.printStudentOnConsole();
    return 0;
}
