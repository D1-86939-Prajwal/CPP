#include <iostream>
using namespace std;

class Student {
private:
    string name, gender;
    static int nextRollNumber;
    int rollNumber;
    int marks[3];

public:
    Student() {
        rollNumber = nextRollNumber++;
        name = "Raj";
        gender = "Male";
        marks[0] = marks[1] = marks[2] = 0;
    }

    Student(string name, string gender, int marks[]) {
        rollNumber = nextRollNumber++; 
        this->name = name;
        this->gender = gender;
        for (int i = 0; i < 3; i++) {
            this->marks[i] = marks[i];
        }
    }

    string getName() { return name; }
    string getGender() { return gender; }
    int getRollNumber() { return rollNumber; }

    void setName(string name) { this->name = name; }
    void setGender(string gender) { this->gender = gender; }
    void setMarks(int marks[]) {
        for (int i = 0; i < 3; i++) {
            this->marks[i] = marks[i];
        }
    }

    void accept() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Marks for 3 Subjects: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Percentage: " << getPercentage() << "%" << endl;
    }

    float getPercentage() const {
        int totalMarks = 0;
        for (int i = 0; i < 3; i++) {
            totalMarks += marks[i];
        }
        return (totalMarks / 3.0f);
    }
};


int Student::nextRollNumber = 1;

void sortRecords(Student* arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i]->getRollNumber() < arr[j]->getRollNumber()) {
                Student* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int searchRecords(Student* arr[], int size, int rollNumber) {
    for (int i = 0; i < size; i++) {
        if (arr[i]->getRollNumber() == rollNumber) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    Student* arr[5];

    for (int i = 0; i < 5; i++) {
        arr[i] = new Student(); 
        arr[i]->accept();
    }

    int choice;
    do {
        cout << "\nMenu" << endl;
        cout << "1: Display Student Details" << endl;
        cout << "2: Search Student by Roll Number" << endl;
        cout << "3: Sort Records by Roll Number (Descending)" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Displaying All Students Details:" << endl;
            for (int i = 0; i < 5; i++) {
                arr[i]->display();
            }
            break;
        }
        case 2: {
            int rollNumber;
            cout << "Enter Roll Number to Search: ";
            cin >> rollNumber;
            int index = searchRecords(arr, 5, rollNumber);
            if (index != -1) {
                cout << "Student Found:" << endl;
                arr[index]->display();
            } else {
                cout << "Student Not Found." << endl;
            }
            break;
        }
        case 3: {
            sortRecords(arr, 5);
            cout << "Records Sorted in Descending Order by Roll Number." << endl;
            break;
        }
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice. Please Try Again." << endl;
        }
    } while (choice != 4);

    for (int i = 0; i < 5; i++) {
        delete arr[i];
    }

    return 0;
}
