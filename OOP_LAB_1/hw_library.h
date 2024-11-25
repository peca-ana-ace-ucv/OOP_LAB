#ifndef HW_LIBRARY_H
#define HW_LIBRARY_H

double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

#endif


//Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}

//Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5.0 / 9.0;
}