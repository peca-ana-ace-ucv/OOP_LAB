#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

using namespace std;

// Base class Vehicle
class Vehicle 
{
protected:
    double speed;       // Current speed of the vehicle
    bool isRunning;     // Whether the vehicle is running

public:
    Vehicle() : speed(0), isRunning(false) {}

    // Start the vehicle
    virtual void start() 
    {
        isRunning = true;
        speed = rand() % 101;  // Random speed between 0 and 100
    }

    // Stop the vehicle
    virtual void stop() 
    {
        isRunning = false;
        speed = 0;
    }

    // Change the speed by a random value
    virtual void changeSpeed() 
    {
        int change = rand() % 21 - 10;  // Random change in speed: -10 to +10
        speed += change;
        if (speed < 0) speed = 0;  // Ensure speed doesn't go below 0
    }

    // Display the vehicle's speed and status (stopped or moving)
    virtual void displayInfo() const 
    {
        if (isRunning)
            cout << "Speed: " << getSpeed() << " km/h" << endl;
        else 
            cout << "Stopped" << endl;
    }

    // Getter method for speed
    double getSpeed() const 
    {
        return speed;
    }

    // Check if the vehicle is moving
    bool isMoving() const 
    {
        return isRunning && speed > 0;
    }

    // Virtual destructor
    virtual ~Vehicle() {}
};

// Derived class Bike
class Bike : public Vehicle 
{
public:
    void start() override 
    {
        Vehicle::start();
        cout << "Bike started" << endl;
    }
};

// Derived class Car
class Car : public Vehicle 
{
public:
    void start() override 
    {
        Vehicle::start();
        cout << "Car started" << endl;
    }
};

// Derived class Plane
class Plane : public Vehicle 
{
public:
    void start() override 
    {
        Vehicle::start();
        cout << "Plane started" << endl;
    }
};

// Function to calculate the average speed of all moving vehicles
double calculateAverageSpeed(const vector<Vehicle*>& vehicles) 
{
    double totalSpeed = 0;
    int movingCount = 0;

    for (auto v : vehicles) 
    {
        if (v->isMoving()) 
        {
            totalSpeed += v->getSpeed();
            movingCount++;
        }
    }

    if (movingCount == 0) return 0;  // Avoid division by zero
     return totalSpeed / movingCount;
}

int main() 
{
    srand(time(0));  // Seed for random number generation

    // Create a vector of different vehicles
    vector<Vehicle*> vehicles;
    vehicles.push_back(new Bike());
    vehicles.push_back(new Car());
    vehicles.push_back(new Plane());

    // Randomly start some of the vehicles
    for (auto v : vehicles) 
    {
        if (rand() % 2 == 0) 
            v->start();
    }

    // Randomly change the speed of each vehicle
    for (auto v : vehicles) 
    {
        if (rand() % 2 == 0)
            v->changeSpeed();
    }

    // Display all vehicles' information
    cout << "\nVehicle Statuses:\n";

    for (auto v : vehicles)
        v->displayInfo();

    // Calculate and display the average speed of all moving vehicles
    double avgSpeed = calculateAverageSpeed(vehicles);
    if (avgSpeed > 0)
        cout << "\nAverage speed of all moving vehicles: " << avgSpeed << " km/h" << endl;
    else
        cout << "\nNo vehicles are moving." << endl;

    // Clean up dynamically allocated memory
    for (auto v : vehicles)
        delete v;

    return 0;
}
