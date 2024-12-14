#include <iostream>

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

    // Overload + operator for addition
    Complex operator+(Complex other)
    {
        return Complex(real + other.real, imag + other.imag);
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
    Complex c1(3, 4); // First complex number: 3 + 4i
    Complex c2(1, -2); // Second complex number: 1 - 2i

    // Adding two complex numbers
    Complex c3 = c1 + c2;

    // Display results
    cout << "c1 = ";
    c1.display();

    cout << "\nc2 = ";
    c2.display();

    cout << "\nc1 + c2 = ";
    c3.display();

    cout << endl;

    return 0;
}