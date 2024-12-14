#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    // Overload the ~ operator for magnitude (absolute value)
    double operator~()
    {
        return sqrt(real * real + imag * imag);
    }

    // Overload the ^ operator for power (default to power 2)
    Complex operator^(int power)
    {
        double magnitude = pow(~(*this), power);
        double angle = atan2(imag, real) * power; // Polar coordinates
        return Complex(magnitude * cos(angle), magnitude * sin(angle));
    }

    // Overload the + operator for addition
    Complex operator+(Complex& other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Display function
    void display()
    {
        cout << real << (imag >= 0 ? " + " : " - ") << fabs(imag) << "i";
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
