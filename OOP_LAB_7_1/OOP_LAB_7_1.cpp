#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Group 
{
public:
    // Nested Student class
    class Student 
    {
    private:
        string name;
        int studentID;

    public:
        // Constructor
        Student(const string& name, int studentID) : name(name), studentID(studentID) {}

        // Display Student Info
        void display() const 
        {
            cout << "  Student Name: " << name << ", ID: " << studentID << endl;
        }
    };

private:
    string groupName;
    vector<Student> students; // List of students in the group

public:
    // Constructor for Group
    Group(const string& groupName) : groupName(groupName) {}

    // Add a student to the group
    void addStudent(const string& name, int studentID) 
    {
        students.emplace_back(name, studentID); // Add a new student to the list
    }

    // Display group details
    void display() const 
    {
        cout << "Group Name: " << groupName << endl;
        if (students.empty()) 
        {
            cout << "  No students in this group." << endl;
        }
        else 
        {
            for (const auto& student : students) 
                student.display();
        }
    }
};

int main() 
{
    // Create groups
    Group group1("Engineering");
    Group group2("Mathematics");

    // Add students to groups
    group1.addStudent("Alice", 101);
    group1.addStudent("Bob", 102);

    group2.addStudent("Charlie", 201);
    group2.addStudent("Diana", 202);

    // Display groups with their students
    cout << "Groups and their Students:" << endl;

    group1.display();
    group2.display();

    return 0;
}