#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class Vehicle
class Vehicle
{
protected:
    string name; // Name of the vehicle

public:
    // Constructor
    Vehicle(string n) : name(n) {}

    // Pure virtual method to start the vehicle
    virtual void start() = 0;
};

// Class Rocket derived from Vehicle
class Rocket : public Vehicle
{
public:
    // Constructor
    Rocket(string n) : Vehicle(n) {}

    // Override start method
    void start() override
    {
        cout << "Starting rocket: " << name << endl;
    }
};

// Class Car derived from Vehicle
class Car : public Vehicle
{
public:
    // Constructor
    Car(string n) : Vehicle(n) {}

    // Override start method
    void start() override
    {
        cout << "Starting car: " << name << endl;
    }
};

int main()
{
    // Vector of Vehicle pointers
    vector<Vehicle*> vehicles;

    // Adding vehicles to the vector
    vehicles.push_back(new Car("Red Car"));
    vehicles.push_back(new Car("Awesome Car"));
    vehicles.push_back(new Rocket("NASA Rocket"));

    // Starting all vehicles
    for (int i = 0; i < vehicles.size(); ++i)
        vehicles[i]->start();

    // Clean up allocated memory
    for (int i = 0; i < vehicles.size(); ++i)
        delete vehicles[i];

    return 0;
}