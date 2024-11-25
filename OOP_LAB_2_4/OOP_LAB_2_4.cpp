#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort()
#include <string>
using namespace std;

// Define a struct for Person
struct Person
{
    string name;
    int age;
};

// Comparator to sort by age in descending order
bool compareByAgeDescending(const Person& p1, const Person& p2)
{
    return p1.age > p2.age;  // Descending order: compare greater than
}

// Comparator to sort by name in ascending order
bool compareByNameAscending(const Person& p1, const Person& p2)
{
    return p1.name < p2.name;  // Ascending order: compare less than
}

// Function to print the list of persons
void printPersons(const vector<Person>& persons)
{
    for (const auto& person : persons)
        cout << "Name: " << person.name << ", Age: " << person.age << endl;
    cout << endl;
}

int main()
{
    // Create a list of persons
    vector<Person> persons =
    {
        {"Alin", 30},
        {"Andrei", 21},
        {"Alexandra", 35},
        {"David", 19},
        {"Eva", 40}
    };

    // Example 1: Sort by age in descending order
    cout << "Sorting by age (descending order):" << endl;
    sort(persons.begin(), persons.end(), compareByAgeDescending);
    printPersons(persons);

    // Example 2: Sort by name in ascending order
    cout << "Sorting by name (ascending order):" << endl;
    sort(persons.begin(), persons.end(), compareByNameAscending);
    printPersons(persons);

    return 0;
}