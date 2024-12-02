#include <iostream>
#include <vector>

using namespace std;

class Polynomial 
{
private:
    vector<int> coefficients; // Vector to store coefficients

public:
    // Constructor
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {}

    // Overload + operator
    Polynomial operator+(const Polynomial& other) 
    {
        // Find the maximum degree of the two polynomials
        size_t maxDegree = max(coefficients.size(), other.coefficients.size());
        vector<int> result(maxDegree, 0);

        // Add coefficients
        for (size_t i = 0; i < maxDegree; ++i) 
        {
            int coeff1 = (i < coefficients.size()) ? coefficients[i] : 0;
            int coeff2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            result[i] = coeff1 + coeff2;
        }

        return Polynomial(result);
    }

    // Display function
    void display() 
    {
        for (int i = coefficients.size() - 1; i >= 0; --i) 
        {
            if (coefficients[i] != 0) 
            {
                if (i != coefficients.size() - 1 && coefficients[i] > 0)
                    cout << " + ";
                else if (coefficients[i] < 0)
                    cout << " - ";

                cout << abs(coefficients[i]);

                if (i > 0)
                    cout << "x";
                if (i > 1)
                    cout << "^" << i;
            }
        }
        cout << endl;
    }
};

int main() 
{
    // Define two polynomials: P1(x) = 3x^2 + 4x + 5, P2(x) = 5x^3 + 2x + 7
    Polynomial p1({ 5, 4, 3 });  // Coefficients: [5, 4, 3]
    Polynomial p2({ 7, 2, 0, 5 });  // Coefficients: [7, 2, 0, 5]

    // Add the two polynomials
    Polynomial sum = p1 + p2;

    // Display the result
    cout << "P1(x) = ";
    p1.display();

    cout << "P2(x) = ";
    p2.display();

    cout << "Sum P1(x) + P2(x) = ";
    sum.display();

    return 0;
}
