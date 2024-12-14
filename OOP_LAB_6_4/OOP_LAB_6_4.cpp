#include <iostream>
#include <iomanip> // For formatting, using setw() and setfill()

using namespace std;

class Time
{
private:
    int year, month, day, hour, minute, second;

public:
    // Constructor
    Time(int y, int mo, int d, int h, int mi, int s)
    {
        year = y;
        month = mo;
        day = d;
        hour = h;
        minute = mi;
        second = s;
    }

    // Overload + operator for adding two times
    Time operator+(Time other)
    {
        return Time(year + other.year, month + other.month, day + other.day,
            hour + other.hour, minute + other.minute, second + other.second);
    }

    // Overload - operator for subtracting two times
    Time operator-(Time other)
    {
        return Time(year - other.year, month - other.month, day - other.day,
            hour - other.hour, minute - other.minute, second - other.second);
    }

    // Overload == operator for equality comparison
    bool operator==(Time other)
    {
        return year == other.year && month == other.month && day == other.day &&
            hour == other.hour && minute == other.minute && second == other.second;
    }

    // Overload != operator for inequality comparison
    bool operator!=(Time other)
    {
        return !(*this == other);
    }

    // Display function
    void display()
    {
        cout << setw(4) << setfill('0') << year << "-"
            << setw(2) << setfill('0') << month << "-"
            << setw(2) << setfill('0') << day << " "
            << setw(2) << setfill('0') << hour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second;
    }
};

int main()
{
    Time t1(2024, 12, 1, 14, 30, 45); // December 1, 2024, 14:30:45
    Time t2(2024, 11, 30, 12, 45, 20); // November 30, 2024, 12:45:20

    // Add two times
    Time t3 = t1 + t2;
    cout << "t1 + t2 = ";
    t3.display();
    cout << endl;

    // Subtract two times
    Time t4 = t1 - t2;
    cout << "t1 - t2 = ";
    t4.display();
    cout << endl;

    // Compare times
    if (t1 == t2)
        cout << "t1 is equal to t2\n";
    else
        cout << "t1 is not equal to t2\n";

    if (t1 != t2)
        cout << "t1 is not equal to t2\n";
    else
        cout << "t1 is equal to t2\n";

    return 0;
}