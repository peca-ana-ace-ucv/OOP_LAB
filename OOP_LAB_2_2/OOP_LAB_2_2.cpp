#include <iostream>
#include <cmath>  // For sqrt() and fabs

using namespace std;

// Define a struct for complex numbers
struct nrComplex
{
    float a;  // Real part
    float b;  // Imaginary part
};

// Function to compute the absolute value of a real number
float abs_value(float realNumber)
{
    return fabs(realNumber);
    //Use fabs to get absolute value of a float(the module)
}

// Function to compute the absolute value of a complex number
float complex_abs_Value(nrComplex complexNumber)
{
    return sqrt(complexNumber.a * complexNumber.a + complexNumber.b * complexNumber.b);
}

int main()
{
    float realNum;
    cout << "Enter a real number: ";
    cin >> realNum;
    cout << "Absolute value of real number " << realNum << " is: " << abs_value(realNum) << endl;

    nrComplex complexNum;

    cout << "Real part of the complex nr: ";

    cin >> complexNum.a;
    cout << "Imaginary part of the complex nr: ";

    cin >> complexNum.b;
    cout << "Absolute value of complex number " << complexNum.a << " + " << complexNum.b << "i is: " << complex_abs_Value(complexNum) << endl;

    return 0;
}