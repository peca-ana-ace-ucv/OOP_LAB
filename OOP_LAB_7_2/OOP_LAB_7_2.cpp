#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Driver
{
private:
    string name;
    int driverID;

public:
    // Constructor
    Driver(string name, int driverID)
    {
        this->name = name;
        this->driverID = driverID;
    }

    // Get Driver Info
    string getName()
    {
        return name;
    }

    int getDriverID()
    {
        return driverID;
    }

    // Display Driver Info
    void display()
    {
        cout << "Driver Name: " << name << ", Driver ID: " << driverID;
    }
};

class Car
{
private:
    string carModel;
    string licensePlate;

public:
    // Constructor
    Car(string carModel, string licensePlate)
    {
        this->carModel = carModel;
        this->licensePlate = licensePlate;
    }

    // Get Car Info
    string getCarModel()
    {
        return carModel;
    }

    string getLicensePlate()
    {
        return licensePlate;
    }

    // Display Car Info
    void display()
    {
        cout << "Car Model: " << carModel << ", License Plate: " << licensePlate;
    }
};

class DriverCarManager
{
private:
    struct DriverCarPair
    {
        Driver driver;
        Car car;

        DriverCarPair(Driver driver, Car car) : driver(driver), car(car) {}
    };

    vector<DriverCarPair> driverCarPairs;

public:
    // Add a Driver-Car Pair
    void addPair(Driver driver, Car car)
    {
        driverCarPairs.push_back(DriverCarPair(driver, car));
    }

    // Remove a Driver-Car Pair by Driver ID
    void removePairByDriverID(int driverID)
    {
        for (auto it = driverCarPairs.begin(); it != driverCarPairs.end(); ++it)
        {
            if (it->driver.getDriverID() == driverID)
            {
                driverCarPairs.erase(it);
                cout << "Pair with Driver ID " << driverID << " removed successfully.\n";
                return;
            }
        }
        cout << "No pair found with Driver ID " << driverID << ".\n";
    }

    // Display All Driver-Car Pairs
    void displayAll()
    {
        if (driverCarPairs.empty())
        {
            cout << "No Driver-Car pairs available.\n";
            return;
        }

        cout << "Driver-Car Pairs:\n";
        for (auto& pair : driverCarPairs)
        {
            pair.driver.display();
            cout << " | ";
            pair.car.display();
            cout << endl;
        }
        cout << "Total pairs: " << driverCarPairs.size() << endl;
    }
};

int main()
{
    DriverCarManager manager;

    // Create Drivers and Cars
    Driver driver1("Alice", 101);
    Car car1("Toyota Corolla", "ABC-156");
    Driver driver2("Bob", 102);
    Car car2("Honda Civic", "XYZ-879");

    // Add pairs to the manager
    manager.addPair(driver1, car1);
    manager.addPair(driver2, car2);

    // Display all pairs
    manager.displayAll();

    // Remove a pair
    manager.removePairByDriverID(101);

    // Display all pairs after removal
    manager.displayAll();

    return 0;
}