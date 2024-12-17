// Implement a class Complex which represents the Complex Number data type. Implement the following
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers.

#include<iostream>
using namespace std;

// Class to represent a complex number
class Complex
{
    float real;     // Real part of the complex number
    float imag;     // Imaginary part of the complex number

public:
    // Default constructor to initialize real and imaginary parts to 0
    Complex() {
        real = 0;
        imag = 0;
    }

    // Overloading the + operator for addition of two complex numbers
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;    // Add real parts
        temp.imag = imag + c.imag;    // Add imaginary parts
        return temp;
    }

    // Overloading the * operator for multiplication of two complex numbers
    Complex operator*(Complex c) {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);  // Real part formula
        temp.imag = (imag * c.real) + (real * c.imag);  // Imaginary part formula
        return temp;
    }

    // Friend function to overload >> operator for input
    friend istream &operator>>(istream &input, Complex &t) {
        cout << "Enter the real part: ";
        input >> t.real;
        cout << "Enter the imaginary part: ";
        input >> t.imag;
        return input;
    }

    // Friend function to overload << operator for output
    friend ostream &operator<<(ostream &output, const Complex &t) {
        output << t.real << "+" << t.imag << "i";
        return output;
    }
};

int main() {
    Complex c1, c2, c3, c4; // Create four complex number objects

    cout << "Default constructor value: " << c1 << endl; // Display default values

    // Input for the first complex number
    cout << "\nEnter the 1st complex number:\n";
    cin >> c1;

    // Input for the second complex number
    cout << "\nEnter the 2nd complex number:\n";
    cin >> c2;

    // Perform addition and multiplication
    c3 = c1 + c2;   // Add c1 and c2
    c4 = c1 * c2;   // Multiply c1 and c2

    // Display results
    cout << "\nThe first complex number is: " << c1;
    cout << "\nThe second complex number is: " << c2;
    cout << "\nThe addition result is: " << c3;
    cout << "\nThe multiplication result is: " << c4 << endl;

    return 0;
}
