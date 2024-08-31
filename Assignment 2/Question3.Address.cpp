#include <iostream>
using namespace std;

class Address {
private:
    string building, street, city;
    int pin;

public:
    // Default constructor
    Address() {
        building = "Sunbeam";
        street = "HighStreet";
        city = "Pune";
        pin = 411057;
    }

    // Getters
    string getBuilding() const {
        return building;
    }

    string getStreet() const {
        return street;
    }

    string getCity() const {
        return city;
    }

    int getPin() const {
        return pin;
    }

    // Setters
    void setBuilding(const string& building) {
        this->building = building;
    }

    void setStreet(const string& street) {
        this->street = street;
    }

    void setCity(const string& city) {
        this->city = city;
    }

    void setPin(int pin) {
        this->pin = pin;
    }

    // Method to accept input from the user
    void accept() {
        cout << "Enter the building: ";
        cin >> building;
        cout << "Enter the street: ";
        cin >> street;
        cout << "Enter the city: ";
        cin >> city;
        cout << "Enter the pin: ";
        cin >> pin;
    }

    // Method to display the address
    void display() const {
        cout << "The Building is: " << building << endl;
        cout << "Street is: " << street << endl;
        cout << "City is: " << city << endl;
        cout << "The pin is: " << pin << endl;
    }
};

int main() {
    Address a1;
    
    // Set new values
    a1.setBuilding("Sun");
    
    // Accept new values from user
    a1.accept();
    
    // Display the address
    a1.display();

    return 0;
}
