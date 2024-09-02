#include <iostream>
using namespace std;

unsigned int factorial(unsigned int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int num;
    cout << "Enter the Number: ";
    cin >> num;


    try {
     if (num < 0) {
        throw 1;
    }
        cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    } 
    catch (int e) {
        cout << "Negative number entered , Enter a positive number " << endl;
    }

    return 0;
}




