#include <iostream>
#include <cmath> // For sqrt() function
using namespace std;

// Define a class to represent a Quadratic Equation
class QuadraticEquation
{
private:
    double a, b, c; // Coefficients of the quadratic equation

public:
    // Constructor to initialize the coefficients using direct assignment
    QuadraticEquation(double coeffA, double coeffB, double coeffC)
    {
        a = coeffA;
        b = coeffB;
        c = coeffC;
    }

    // Function to calculate the discriminant
    double calculateDiscriminant()
    {
        return b * b - 4 * a * c;
    }

    // Function to solve the quadratic equation
    void solveEquation()
    {
        if (a == 0)
        {
            cout << "This is not a second-degree equation (a cannot be zero)." << endl;
            return;
        }

        double D = calculateDiscriminant(); // Calculate the discriminant

        if (D > 0)
        {
            // Two distinct real roots
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            cout << "Two distinct real roots: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (D == 0)
        {
            // One repeated real root
            double x = -b / (2 * a);
            cout << "One repeated real root: x = " << x << endl;
        }
        else
        {
            // Two complex roots
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-D) / (2 * a);
            cout << "Two complex roots: x1 = " << realPart << " + " << imaginaryPart << "i"
                << ", x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
};

int main()
{
    // Create an instance of QuadraticEquation with coefficients a, b, and c
    double a, b, c;
    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;

    // Instantiate the class and solve the equation
    QuadraticEquation equation(a, b, c);
    equation.solveEquation();

    return 0;
}