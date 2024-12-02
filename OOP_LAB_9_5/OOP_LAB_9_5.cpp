#include <iostream>
#include <cmath>
#include <stdexcept>  // For handling exceptions

using namespace std;

// Function to solve a first-degree equation ax + b = 0
void solveFirstDegree(double a, double b) 
{
    if (a == 0) 
    {
        if (b == 0)
            throw runtime_error("Infinite solutions (0x + 0 = 0).");
        else
            throw runtime_error("No solution (0x + b = 0 where b != 0).");
    }
    else 
    {
        double solution = -b / a;
        cout << "Solution for first-degree equation: x = " << solution << endl;
    }
}

// Function to solve a second-degree equation ax^2 + bx + c = 0
void solveSecondDegree(double a, double b, double c) 
{
    if (a == 0) 
    {
        // If a == 0, it's actually a first-degree equation
        solveFirstDegree(b, c);  // Call first-degree solver
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
        else 
          if (discriminant == 0) 
          {
            double root = -b / (2 * a);
            cout << "One real solution for second-degree equation: x = " << root << endl;
          }
        else
            throw runtime_error("No real solution for second-degree equation (discriminant < 0).");
    }
}

int main() 
{
    try 
    {
        // List of equations to solve
        double equations[][4] = 
        {
            {1, -3, 0, 0},  // 1x - 3 = 0 (First degree)
            {0, 1, 2, 0},   // 1x + 2 = 0 (First degree)
            {1, -3, 2, 0},  // x^2 - 3x + 2 = 0 (Second degree)
            {1, 2, 1, 0},   // x^2 + 2x + 1 = 0 (Second degree)
            {0, 0, 1, 0},   // 0x + 1 = 0 (Invalid First degree)
            {1, 0, -1, 0}   // x^2 - 1 = 0 (Second degree)
        };

        // Iterate through the list of equations
        for (auto& eq : equations) 
        {
            if (eq[0] == 0 && eq[1] == 0 && eq[2] != 0) 
                cout << "Invalid equation (0x + c = 0 where c != 0)" << endl;
            
            else 
              if (eq[3] == 0) 
                solveFirstDegree(eq[0], eq[1]);
            else 
                solveSecondDegree(eq[0], eq[1], eq[2]);
        }

    }
    catch (const exception& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}