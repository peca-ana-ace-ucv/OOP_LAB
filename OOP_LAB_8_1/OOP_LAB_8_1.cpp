#include <iostream>
#include <cmath>

using namespace std;

// Class for ComplexNumber
class ComplexNumber 
{
private:
    float real;
    float imag;

public:
    // Constructor
    ComplexNumber(float real = 0.0, float imag = 0.0) : real(real), imag(imag) {}

    // Getter methods for real and imaginary parts
    float getReal() { return real; }
    float getImag() { return imag; }

    // Method to compute the magnitude of the complex number
    float magnitude() 
    {
        return sqrt(real * real + imag * imag);
    }

    // Overloading the comparison operators
    bool operator<(ComplexNumber& other) 
    {
        return this->magnitude() < other.magnitude();
    }

    bool operator>(ComplexNumber& other) 
    {
        return this->magnitude() > other.magnitude();
    }

    // Overload << for printing
    friend ostream& operator<<(ostream& os, ComplexNumber& c) 
    {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

// Template function to compare two values of the same type
template <typename T>
bool compareValues(T& value1, T& value2) 
{
    return value1 > value2; // Uses the overloaded > operator
}

int main() 
{
    // Comparing float numbers
    float num1 = 3.5;
    float num2 = 4.2;

    cout << "Comparing float numbers:" << endl;
    cout << num1 << " > " << num2 << " ? " << (compareValues(num1, num2) ? "Yes" : "No") << endl;

    // Comparing complex numbers
    ComplexNumber c1(3, 4); // Magnitude: 5
    ComplexNumber c2(1, 7); // Magnitude: 7.071

    cout << "\nComparing complex numbers:" << endl;
    cout << c1 << " > " << c2 << " ? " << (compareValues(c1, c2) ? "Yes" : "No") << endl;

    return 0;
}