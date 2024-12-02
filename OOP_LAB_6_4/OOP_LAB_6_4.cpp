#include <iostream>
#include <iomanip> // For formatting
#include <stdexcept> // For exception handling

using namespace std;

class Time 
{
private:
    int year, month, day, hour, minute, second;

    // Helper to normalize time (handle overflows in seconds, minutes, etc.)
    void normalize() 
    {
        if (second >= 60) 
        {
            minute += second / 60;
            second %= 60;
        }
        else if (second < 0) 
        {
            minute += (second - 59) / 60;
            second = (second % 60 + 60) % 60;
        }

        if (minute >= 60) 
        {
            hour += minute / 60;
            minute %= 60;
        }
        else 
          if (minute < 0) 
          {
            hour += (minute - 59) / 60;
            minute = (minute % 60 + 60) % 60;
          }

        if (hour >= 24) 
        {
            day += hour / 24;
            hour %= 24;
        }
        else 
          if (hour < 0) 
          {
            day += (hour - 23) / 24;
            hour = (hour % 24 + 24) % 24;
          }

        // Simplified day/month/year handling (not considering leap years)
        while (day > 30) 
        { // Assuming 30 days per month for simplicity
            month++;
            day -= 30;
        }
        while (day < 1) 
        {
            month--;
            day += 30;
        }
        while (month > 12) 
        {
            year++;
            month -= 12;
        }
        while (month < 1) 
        {
            year--;
            month += 12;
        }
    }

public:
    // Constructor
    Time(int y, int mo, int d, int h, int mi, int s)
        : year(y), month(mo), day(d), hour(h), minute(mi), second(s) 
    {
        normalize();
    }

    // Overload + operator
    Time operator+(const Time& other) 
    {
        return Time(year, month, day,
            hour + other.hour, minute + other.minute, second + other.second);
    }

    // Overload - operator
    Time operator-(const Time& other) 
    {
        return Time(year, month, day,
            hour - other.hour, minute - other.minute, second - other.second);
    }

    // Overload == operator
    bool operator==(const Time& other) 
    {
        return year == other.year && month == other.month && day == other.day &&
            hour == other.hour && minute == other.minute && second == other.second;
    }

    // Overload != operator
    bool operator!=(const Time& other) 
    {
        return !(*this == other);
    }

    // Display function
    void display() const 
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