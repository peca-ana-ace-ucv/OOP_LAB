#include <iostream>
#include <cmath> // For sqrt

using namespace std;

class Complex
{
private:
    double real, imag; // Real and imaginary parts

public:
    // Constructor
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    // Function to calculate the magnitude (module) of the complex number
    double magnitude()
    {
        return sqrt(real * real + imag * imag);
    }

    // Overload < operator for comparison by module
    bool operator<(Complex other)
    {
        return this->magnitude() < other.magnitude();
    }

    // Display function
    void display()
    {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

int main()
{
    Complex c1(3, 4); // Magnitude = 5
    Complex c2(1, 7); // Magnitude = sqrt(50) ~ 7.07

    // Compare complex numbers by their module
    cout << "Comparing two complex numbers by their module:\n";
    cout << "c1 = ";
    c1.display();
    cout << "\nc2 = ";
    c2.display();

    if (c1 < c2)
        cout << "\n\nc1 has a smaller module than c2.\n";
    else
        cout << "\n\nc1 does not have a smaller module than c2.\n";

    return 0;
}