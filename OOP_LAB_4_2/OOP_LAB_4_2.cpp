#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Address Class
class Address 
{
private:
    string city;
    string street;
    int number;

public:
    Address(string c, string s, int n) : city(c), street(s), number(n) {}

    void display() 
    {
        cout << "Address: " << street << " St, " << number << ", " << city << endl;
    }
};

// Engine Class
class Engine 
{
protected:
    string type;
    int horsepower;

public:
    Engine(string t, int hp) : type(t), horsepower(hp) {}

    void display() 
    {
        cout << "Engine Type: " << type << ", Horsepower: " << horsepower << " HP" << endl;
    }
};

// Driver Class
class Driver 
{
private:
    string name;
    int age;

public:
    Driver(string n, int a) : name(n), age(a) {}

    void display() 
    {
        cout << "Driver: " << name << ", Age: " << age << endl;
    }
};

// Commuter Class
class Commuter 
{
private:
    string name;
    int ticketNumber;

public:
    // Default constructor
    Commuter() : name("Unknown"), ticketNumber(0) {}

    // Constructor with parameters
    Commuter(string n, int t) : name(n), ticketNumber(t) {}

    void display() 
    {
        cout << "Commuter: " << name << ", Ticket Number: " << ticketNumber << endl;
    }
};

// Bus Class
class Bus 
{
private:
    string model;
    Engine engine;
    Driver driver;
    vector<Commuter> commuters;

public:
    // Constructor with parameters
    Bus(string m, Engine e, Driver d) : model(m), engine(e), driver(d) {}

    void addCommuter(Commuter commuter) 
    {
        commuters.push_back(commuter);
    }

    void display() 
    {
        cout << "Bus Model: " << model << endl;
        engine.display();
        driver.display();
        cout << "Commuters on Bus:" << endl;
        for (auto commuter : commuters)  // Removed `const`
            commuter.display();
        
    }
};

// Car Class (inherits Engine)
class Car : public Engine 
{
private:
    string model;

public:
    Car(string m, string t, int hp) : Engine(t, hp), model(m) {}

    void display() 
    {
        cout << "Car Model: " << model << endl;
        Engine::display();
    }
};

// BusStation Class
class BusStation 
{
private:
    string name;
    Address address;
    vector<Bus> buses;

public:
    BusStation(string n, Address a) : name(n), address(a) {}

    void addBus(Bus bus) 
    {
        buses.push_back(bus);
    }

    void display() 
    {
        cout << "Bus Station: " << name << endl;
        address.display();
        cout << "Buses in Station:" << endl;
        for (auto bus : buses) // Removed `const`
            bus.display();
    }
};

// Mosquito Class
class Mosquito 
{
private:
    string species;
    bool isDangerous;

public:
    Mosquito(string s, bool d) : species(s), isDangerous(d) {}

    void display() 
    {
        cout << "Mosquito Species: " << species << ", Dangerous: " << (isDangerous ? "Yes" : "No") << endl;
    }
};

// Main Function
int main() 
{
    // Create Address
    Address stationAddress("New York", "5th Ave", 101);

    // Create Engine
    Engine busEngine("Diesel", 400);

    // Create Driver
    Driver busDriver("John Doe", 45);

    // Create Bus
    Bus bus("Volvo 9900", busEngine, busDriver);

    // Create Commuters
    Commuter commuter1("Alice", 101);
    Commuter commuter2("Bob", 102);

    // Add commuters to bus
    bus.addCommuter(commuter1);
    bus.addCommuter(commuter2);

    // Create BusStation
    BusStation station("Central Bus Station", stationAddress);
    station.addBus(bus);

    // Display BusStation Information
    station.display();

    // Create Car
    Car car("Tesla Model S", "Electric", 670);
    car.display();

    // Create Mosquito
    Mosquito mosquito("Aedes", true);
    mosquito.display();

    return 0;
}