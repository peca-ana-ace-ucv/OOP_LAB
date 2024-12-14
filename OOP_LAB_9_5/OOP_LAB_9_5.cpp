#include <iostream>
#include <cmath>

using namespace std;

// Abstract base class for equations
class Equation
{
public:
    virtual void solve() = 0;  // Pure virtual function for solving equations
};

// Derived class for first-degree equations (ax + b = 0)
class FirstDegreeEquation : public Equation
{
private:
    double a, b;  // Coefficients for the first-degree equation

public:
    FirstDegreeEquation(double a, double b) : a(a), b(b) {}

    void solve() override
    {
        if (a == 0)
        {
            if (b == 0)
                cout << "Infinite solutions (0x + 0 = 0)." << endl;
            else
                cout << "No solution (0x + b = 0 where b != 0)." << endl;
        }
        else
        {
            double solution = -b / a;
            cout << "Solution for first-degree equation: x = " << solution << endl;
        }
    }
};

// Derived class for second-degree equations (ax^2 + bx + c = 0)
class SecondDegreeEquation : public Equation
{
private:
    double a, b, c;  // Coefficients for the second-degree equation

public:
    SecondDegreeEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void solve() override
    {
        if (a == 0)
        {
            // It's actually a first-degree equation (bx + c = 0)
            FirstDegreeEquation firstDegreeSolver(b, c);
            firstDegreeSolver.solve();
        }
        else
        {
            double discriminant = b * b - 4 * a * c;

            if (discriminant > 0)
            {
                double root1 = (-b + sqrt(discriminant)) / (2 * a);
                double root2 = (-b - sqrt(discriminant)) / (2 * a);
                cout << "Two real solutions for second-degree equation: x1 = " << root1 << ", x2 = " << root2 << endl;
            }
            else if (discriminant == 0)
            {
                double root = -b / (2 * a);
                cout << "One real solution for second-degree equation: x = " << root << endl;
            }
            else
                cout << "No real solution for second-degree equation (discriminant < 0)." << endl;
        }
    }
};

// Main function
int main()
{
    // List of equations to solve
    FirstDegreeEquation eq1(1, -3);      // 1x - 3 = 0
    FirstDegreeEquation eq2(0, 1);       // 1x + 2 = 0 (First degree with a = 0)
    SecondDegreeEquation eq3(1, -3, 2);  // x^2 - 3x + 2 = 0
    SecondDegreeEquation eq4(1, 2, 1);   // x^2 + 2x + 1 = 0
    FirstDegreeEquation eq5(0, 0);       // 0x + 1 = 0 (Invalid first degree equation)
    SecondDegreeEquation eq6(1, 0, -1);  // x^2 - 1 = 0

    // Array of equations
    Equation* equations[] = { &eq1, &eq2, &eq3, &eq4, &eq5, &eq6 };

    // Iterate through the list of equations
    for (auto& eq : equations)
        eq->solve();  // Call the solve function for each equation

    return 0;
}