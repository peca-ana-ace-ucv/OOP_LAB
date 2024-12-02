#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the ~ operator for magnitude
    double operator~()
    {
        return sqrt(real * real + imag * imag);
    }

    // Overload the ^ operator for power
    Complex operator^(int power)
    {
        if (power == 0)
            return Complex(1, 0); // Any number to the power of 0 is 1

        Complex result = *this;

        for (int i = 1; i < power; ++i)
            result = result * (*this);

        return result;
    }

    // Overload the + operator for addition
    Complex operator+(Complex& other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the * operator for multiplication (used in ^ operator)
    Complex operator*(Complex& other)
    {
        return Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
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
    // Example usage
    Complex c1(3, 4); // 3 + 4i
    Complex c2(1, -2); // 1 - 2i

    // Display c1 and c2
    cout << "c1 = ";
    c1.display();
    cout << "\nc2 = ";
    c2.display();
    cout << "\n";

    // Absolute value (magnitude) of c1
    cout << "|c1| = " << ~c1 << "\n";

    // Power of c1 (default to 2)
    Complex c1_squared = c1 ^ 2;
    cout << "c1^2 = ";
    c1_squared.display();
    cout << "\n";

    // Sum of c1 and c2
    Complex sum = c1 + c2;
    cout << "c1 + c2 = ";
    sum.display();
    cout << "\n";

    return 0;
}