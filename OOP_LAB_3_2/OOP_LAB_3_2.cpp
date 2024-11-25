#include <iostream>
#include <string>

using namespace std;

// Define the Student class
class Student
{
private:
    int id;
    string name;

public:
    // Constructor
    Student(int studentId, string studentName) : id(studentId), name(studentName) {}

    // Getter for the student ID
    int getId()
    {
        return id;
    }

    // Getter for the student name
    string getName()
    {
        return name;
    }

    // Display student information
    void display()
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

// Function to search for a student by ID
void searchStudentById(Student students[], int studentCount, int id)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].getId() == id)
        {
            cout << "Student found: ";
            students[i].display();
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}

// Function to search for a student by name
void searchStudentByName(Student students[], int studentCount, string name)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].getName() == name)
        {
            cout << "Student found: ";
            students[i].display();
            return;
        }
    }
    cout << "Student with name \"" << name << "\" not found." << endl;
}

int main()
{
    // Create a list of students (using an array of students)
    Student students[] =
    {
        Student(1, "Alice"),
        Student(2, "Bob"),
        Student(3, "Charlie"),
        Student(4, "Diana")
    };

    int studentCount = 4;  // Number of students

    // Search for a student by ID
    searchStudentById(students, studentCount, 2);

    // Search for a student by name
    searchStudentByName(students, studentCount, "Charlie");

    return 0;
}