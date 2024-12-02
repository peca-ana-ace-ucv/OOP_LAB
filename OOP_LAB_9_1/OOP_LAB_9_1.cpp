#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract class Vehicle
class Vehicle 
{
protected:
    string name; // Name of the vehicle

public:
    // Constructor
    Vehicle(string name) : name(name) {}

    // Pure virtual method to start the vehicle
    virtual void start() = 0;

    // Virtual destructor to clean up derived objects properly
    virtual ~Vehicle() {}
};

// Class Rocket derived from Vehicle
class Rocket : public Vehicle 
{
public:
    // Constructor
    Rocket(string name) : Vehicle(name) {}

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
    Car(string name) : Vehicle(name) {}

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
    for (auto vehicle : vehicles)
        vehicle->start();

    // Clean up to prevent memory leaks
    for (auto vehicle : vehicles)
        delete vehicle;

    return 0;
}
