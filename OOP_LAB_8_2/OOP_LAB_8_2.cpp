#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class for Person
class Person 
{
private:
    string name;
    int age;

public:
    // Constructor
    Person(string name, int age) : name(name), age(age) {}

    // Getter for age
    int getAge() { return age; }

    // Display person info
    void display() 
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Class for Car
class Car 
{
private:
    string model;
    int yearsOld; // Age of the car

public:
    // Constructor
    Car(string model, int yearsOld) : model(model), yearsOld(yearsOld) {}

    // Getter for age (years old)
    int getAge() { return yearsOld; }

    // Display car info
    void display() 
    {
        cout << "Model: " << model << ", Years Old: " << yearsOld << endl;
    }
};

// Template class to compute average age
template <typename T>
class AverageCalculator 
{
public:
    // Method to compute the average age
    static double computeAverageAge(vector<T>& list) 
    {
        if (list.empty()) 
        {
            return 0.0;
        }

        int totalAge = 0;
        for (T& item : list) 
            totalAge += item.getAge(); // Calls the getAge() method

        return static_cast<double>(totalAge) / list.size();
    }
};

int main() 
{
    // List of Persons
    vector<Person> persons = 
    {
        Person("Rodica", 30),
        Person("Bobby", 25),
        Person("Carlos", 35)
    };

    // List of Cars
    vector<Car> cars = 
    {
        Car("Toyota", 5),
        Car("Honda Civic", 3),
        Car("Ford Focus", 10)
    };

    // Compute and display average age for persons
    cout << "Persons in the list:" << endl;

    for (Person& person : persons)
        person.display();

    double avgPersonAge = AverageCalculator<Person>::computeAverageAge(persons);
    cout << "Average Age of Persons: " << avgPersonAge << endl;

    // Compute and display average age for cars
    cout << "\nCars in the list:" << endl;
    for (Car& car : cars)
        car.display();

    double avgCarAge = AverageCalculator<Car>::computeAverageAge(cars);
    cout << "Average Age of Cars: " << avgCarAge << endl;

    return 0;
}