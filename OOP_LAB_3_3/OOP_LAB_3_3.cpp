#include <iostream>
#include <string>
using namespace std;

// Define the Student class
class Student
{
private:
    string name;
    double grade;

public:
    // Constructor
    Student(string studentName, double studentGrade) : name(studentName), grade(studentGrade) {}

    // Getter for the student's name
    string getName()
    {
        return name;
    }

    // Getter for the student's grade
    double getGrade()
    {
        return grade;
    }

    // Display student details
    void display()
    {
        cout << "Name: " << name << ", Grade: " << grade << endl;
    }
};

// Function to find and return the students with the highest grade
void getStudentsWithHighestGrade(Student students[], int numStudents)
{
    double highestGrade = 0.0;

    // Find the highest grade among all students
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].getGrade() > highestGrade)
            highestGrade = students[i].getGrade();
    }

    // Collect and display all students with the highest grade
    cout << "Students with the highest grade:" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].getGrade() == highestGrade)
            students[i].display();
    }
}

int main()
{
    // Create an array of students
    Student students[] =
    {
        Student("Alice", 89.5),
        Student("Bob", 95.0),
        Student("Charlie", 95.0),
        Student("Diana", 88.0)
    };

    int numStudents = 4;  // Number of students

    // Get and display the students with the highest grade
    getStudentsWithHighestGrade(students, numStudents);

    return 0;
}