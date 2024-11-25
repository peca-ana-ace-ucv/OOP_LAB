#include <iostream>
#include <string>

using namespace std;

class Address 
{
public:
    string street, city;
    Address(string s, string c) : street(s), city(c) {}
};

class Person 
{
protected:
    string name;
    Address* address;
public:
    Person(string n, Address* addr) : name(n), address(addr) {}
    string getName() { return name; }
};

class Driver : public Person 
{
public:
    Driver(string n, Address* addr) : Person(n, addr) {}
};

class Student : public Person 
{
public:
    Student(string n, Address* addr) : Person(n, addr) {}
};

class Bus 
{
    string id;
    Person* passengers[10]; // Array of pointers to passengers
    string stops[10];       // Array of stops
    int passengerCount, stopCount;
    Driver* driver;
public:
    Bus(string i, Driver* d) : id(i), driver(d), passengerCount(0), stopCount(0) {}

    void addPassenger(Person* p) 
    {
        if (passengerCount < 10) passengers[passengerCount++] = p;
    }

    void addStop(string stop) 
    {
        if (stopCount < 10) stops[stopCount++] = stop;
    }

    void showStops() 
    {
        for (int i = 0; i < stopCount; i++) cout << stops[i] << " ";
        cout << endl;
    }

    int getPassengerCount() 
    { 
        return passengerCount; 
    }
};

class BusStation 
{
    Bus* buses[10];        // Array of pointers to buses
    Person* commuters[10]; // Array of pointers to commuters
    int busCount, commuterCount;

public:
    BusStation() : busCount(0), commuterCount(0) {}

    void addBus(Bus* b) 
    {
        if (busCount < 10) 
            buses[busCount++] = b;
    }

    void addCommuter(Person* p) 
    {
        if (commuterCount < 10) 
            commuters[commuterCount++] = p;
    }

    int getCommuterCount() 
    { 
        return commuterCount; 
    }
};

int main() 
{
    // Create address
    Address addr("Strada Maria-Dudu", "Craiova");

    // Create driver and student
    Driver driver("Ionut", &addr);
    Student student("Alex", &addr);

    // Create bus and bus station
    Bus bus("Bus1", &driver);
    BusStation station;

    // Add stops, passengers, and commuters
    bus.addStop("Stop1");
    bus.addStop("Stop2");
    bus.addPassenger(&student);
    station.addBus(&bus);
    station.addCommuter(&student);

    // Output results
    cout << "Commuters in bus: " << bus.getPassengerCount() << endl;
    cout << "Commuters in station: " << station.getCommuterCount() << endl;
    cout << "Bus stops: ";
    bus.showStops();

    return 0;
}