#include <iostream>
#include <cmath>  // For handling mathematical operations
#include <limits> // For handling invalid results
using namespace std;

// Function to handle division of integers
int divideInt(int a, int b)
{
    if (b == 0)
    {
        cout << "Error: Division by zero is undefined for integers." << endl;
        return std::numeric_limits<int>::min();  // Return an error code (minimum integer)
    }
    return a / b;
}

// Function to handle division of doubles
double divideDouble(double a, double b)
{
    if (b == 0.0)
    {
        cout << "Error: Division by zero is undefined for floating-point numbers." << endl;
        return std::numeric_limits<double>::quiet_NaN();  // Return NaN (not-a-number) for floating point division by zero
    }
    return a / b;
}

// Function to operate on two integers with a pointer to a function
int operate(int a, int b, int (*operation)(int, int))
{
    return operation(a, b);
}

// Function to operate on two doubles with a pointer to a function
double operate(double a, double b, double (*operation)(double, double))
{
    return operation(a, b);
}

int main()
{

    int x, y;
    double p, q;

    cout << "Enter two integers (a and b): ";
    cin >> x >> y;

    cout << "Operating on integers: " << x << " / " << y << " = " << operate(x, y, divideInt) << endl;

    cout << "Enter two doubles (p and q): ";
    cin >> p >> q;

    cout << "Operating on doubles: " << p << " / " << q << " = " << operate(p, q, divideDouble) << endl;

    return 0;
}