#include<iostream>
using namespace std;

class Time {
private:
    int seconds, mins, hours;

public:
    // Default constructor
    Time() : seconds(10), mins(20), hours(10) {}

    // Parameterized constructor
    Time(int s, int m, int h) : seconds(s), mins(m), hours(h) {}

    // Getter methods
    int getHour() {
        return hours;
    }

    int getMinute() {
        return mins;
    }

    int getSeconds() {
        return seconds;
    }

    // Setter methods
    void setHour(int h) {
        hours = h;
    }

    void setMinute(int m) {
        mins = m;
    }

    void setSeconds(int s) {
        seconds = s;
    }

    // Print the time
    void printTime() {
        cout << "Time: " << hours << "H:" << mins << "M:" << seconds << "S" << endl;
    }
};

int main() {
    // Dynamically allocate an array of 3 Time objects
    Time *ptr = new Time[3];
    ptr[0].setHour(10);
    ptr[0].setMinute(10);
    ptr[0].setSeconds(10);
    ptr[0].printTime();

    ptr[1].setHour(20);
    ptr[1].setMinute(20);
    ptr[1].setSeconds(20);
    ptr[1].printTime();



    // Deallocate the memory
    delete[] ptr;

    return 0;
}
