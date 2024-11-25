#include <iostream>
using namespace std;

// Define the Rectangle class
class Rectangle
{
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w) : length(l), width(w) {}

    // Function to calculate the perimeter
    double getPerimeter()
    {
        return 2 * (length + width);
    }

    // Function to calculate the area
    double getArea()
    {
        return length * width;
    }

    // Function to compare perimeters
    void comparePerimeter(Rectangle other)
    {
        if (getPerimeter() > other.getPerimeter())
        {
            cout << "The current rectangle has a larger perimeter." << endl;
        }
        else if (getPerimeter() < other.getPerimeter())
        {
            cout << "The other rectangle has a larger perimeter." << endl;
        }
        else
        {
            cout << "Both rectangles have the same perimeter." << endl;
        }
    }

    // Function to compare areas
    void compareArea(Rectangle other)
    {
        if (getArea() > other.getArea())
        {
            cout << "The current rectangle has a larger area." << endl;
        }
        else if (getArea() < other.getArea())
        {
            cout << "The other rectangle has a larger area." << endl;
        }
        else
        {
            cout << "Both rectangles have the same area." << endl;
        }
    }
};

int main()
{
    // Create two Rectangle objects
    Rectangle rect1(10, 5);
    Rectangle rect2(7, 6);

    // Output the perimeter and area of the first rectangle
    cout << "Rectangle 1: Perimeter = " << rect1.getPerimeter() << ", Area = " << rect1.getArea() << endl;

    // Output the perimeter and area of the second rectangle
    cout << "Rectangle 2: Perimeter = " << rect2.getPerimeter() << ", Area = " << rect2.getArea() << endl;

    // Compare the perimeters
    rect1.comparePerimeter(rect2);

    // Compare the areas
    rect1.compareArea(rect2);

    return 0;
}