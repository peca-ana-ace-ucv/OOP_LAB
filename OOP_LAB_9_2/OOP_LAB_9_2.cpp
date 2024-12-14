#include <iostream>
#include <vector>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Abstract Shape class
class Shape
{
public:
    virtual double area() = 0;  // Pure virtual function to compute area
    virtual void draw() = 0;    // Pure virtual function to draw the shape
};

// Circle class derived from Shape
class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() override
    {
        return M_PI * radius * radius; // Area of the circle: πr^2
    }

    void draw() override
    {
        cout << "Drawing a Circle" << endl;
    }
};

// Triangle class derived from Shape
class Triangle : public Shape
{
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() override
    {
        return 0.5 * base * height; // Area of the triangle: 1/2 * base * height
    }

    void draw() override
    {
        cout << "Drawing a Triangle" << endl;
    }
};

// Square class derived from Shape
class Square : public Shape
{
private:
    double side;
public:
    Square(double s) : side(s) {}

    double area() override
    {
        return side * side; // Area of the square: side^2
    }

    void draw() override
    {
        cout << "Drawing a Square" << endl;
    }
};

int main()
{
    // Vector to store pointers to Shape objects
    vector<Shape*> shapes;

    // Create instances of different shapes and add them to the vector
    shapes.push_back(new Circle(5));   // Circle with radius 5
    shapes.push_back(new Triangle(4, 6));  // Triangle with base 4 and height 6
    shapes.push_back(new Square(3));  // Square with side 3

    // Compute the sum of areas
    double totalArea = 0;

    for (int i = 0; i < shapes.size(); ++i)
        totalArea += shapes[i]->area();  // Add area of each shape to the total area

    // Output the total area
    cout << "Total area of all shapes: " << totalArea << endl;

    // Clean up dynamically allocated memory
    for (int i = 0; i < shapes.size(); ++i)
        delete shapes[i];

    return 0;
}
