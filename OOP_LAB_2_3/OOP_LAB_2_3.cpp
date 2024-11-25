#include <iostream>
#include <stdexcept>  // For exception handling
using namespace std;

// Function to solve ax + b = 0
float solveEquation(float a, float b)
{
    if (a == 0)
    {
        if (b == 0)
            throw logic_error("Infinite solutions");
        else
            throw logic_error("No solution exists.");
    }
    // Normal case: a != 0, return the solution
    return -b / a;
}

int main()
{
    float a, b;

    cout << "Enter the coefficient a: ";
    cin >> a;
    cout << "Enter the constant b: ";
    cin >> b;

    try
    {
        // Try solving the equation
        float solution = solveEquation(a, b);
        cout << "The solution to the equation " << a << "x + " << b << " = 0 is: x = " << solution << endl;
    }
    catch (const logic_error& e)
    {
        // Handle any exceptions thrown by the function
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}