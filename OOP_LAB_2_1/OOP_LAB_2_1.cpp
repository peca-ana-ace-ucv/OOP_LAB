#include <iostream>
#include <string>
#include <stdexcept> // library for exceptions
#include <sstream>   // library for stringstream
using namespace std;

// Function to convert string to float
float string_to_float(const string& str)
{
    // Try converting to float, throw exceptions

    stringstream str_conv(str);

    float num;

    if (!(str_conv >> num))
        throw invalid_argument("Invalid input! This input cannot be converted to a number!");

    return num;
}

// Function to calculate area of rectangle
float rectangle_area(float length, float width)
{
    return length * width;
}

// Function pointer definition
typedef float (*AreaFunc)(float, float);

// Main function to calculate the area, handling exceptions and print results
float calc_area(const string& i1, const string& i2 = "")
{
    try
    {
        // Convert inputs from strings to float
        float length = string_to_float(i1);
        float width = length;

        if (!i2.empty())
        {
            // If second input is provided (rectangle)
            width = string_to_float(i2);
        }

        // Use function pointer to calculate area
        AreaFunc areaFunc = &rectangle_area;

        return areaFunc(length, width);

    }
    catch (const invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;  // Return -1 for invalid input
    }
}

int main()
{
    string length_input, width_input;

    cout << "Enter the length: ";
    cin >> length_input;

    // Get width input from the user (optional for square)
    cout << "Enter the width: ";

    cin.ignore();
    // Ignore any leftover newline from previous input

    getline(cin, width_input);

    // Compute the area and display the result
    if (width_input.empty())
        cout << "Square area: " << calc_area(length_input) << endl;

    else
        cout << "Rectangle area: " << calc_area(length_input, width_input) << endl;

    return 0;
}