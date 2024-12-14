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
    virtual void displayInfo()
    {
        if (isRunning)
            cout << "Speed: " << speed << " km/h" << endl;
        else
            cout << "Stopped" << endl;
    }

    // Check if the vehicle is moving
    bool isMoving()
    {
        return isRunning && speed > 0;
    }

    // Get the speed (added getter method)
    double getSpeed()
    {
        return speed;
    }
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

    for (int i = 0; i < vehicles.size(); ++i)
    {
        if (vehicles[i]->isMoving())
        {
            totalSpeed += vehicles[i]->getSpeed();
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
    for (int i = 0; i < vehicles.size(); ++i)
    {
        if (rand() % 2 == 0)
            vehicles[i]->start();
    }

    // Randomly change the speed of each vehicle
    for (int i = 0; i < vehicles.size(); ++i)
    {
        if (rand() % 2 == 0)
            vehicles[i]->changeSpeed();
    }

    // Display all vehicles' information
    cout << "\nVehicle Statuses:\n";

    for (int i = 0; i < vehicles.size(); ++i)
        vehicles[i]->displayInfo();

    // Calculate and display the average speed of all moving vehicles
    double avgSpeed = calculateAverageSpeed(vehicles);
    if (avgSpeed > 0)
        cout << "\nAverage speed of all moving vehicles: " << avgSpeed << " km/h" << endl;
    else
        cout << "\nNo vehicles are moving." << endl;

    // Clean up dynamically allocated memory (without a destructor, manual delete)
    for (int i = 0; i < vehicles.size(); ++i)
        delete vehicles[i];

    return 0;
}