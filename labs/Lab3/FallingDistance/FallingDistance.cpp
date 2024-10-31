// FallingDistance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to display program information
void DisplayProgramInformation()
{
    cout << "Lab 3: Falling Distance Calculator" << endl;
    cout << "Leonardo Serrato" << endl;
    cout << "COSC 1436 Fall 2024" << endl << endl;
}

// Constant values
const double gravityMeters = 9.8;
const double metersToFeet = 3.28084;            //conversion number

// Function to validate integer input within a specified range
int ReadInt(string message, int minValue, int maxValue)
{
    int value;
    do {
        cout << message;
        cin >> value;

        if (value < minValue || value > maxValue) {
            cout << "Value must be between " << minValue << " and " << maxValue << "." << endl;
        }
    } while (value < minValue || value > maxValue);             //this ensures that the values provided are between 1 and 60 when in the int main function

    return value;
}

// Function to prompt for and validate unit selection (meters or feet)
char ReadUnits()
{
    char unit;
    do {
        cout << "Do you want the results in meters or feet? (Enter 'm' for meters or 'f' for feet): ";
        cin >> unit;
        unit = tolower(unit);           //this comes from the instructions on limiting m and f to its lowercase characters

        if (unit != 'm' && unit != 'f')
        {
            cout << "Invalid selection. Please enter 'm' for meters or 'f' for feet." << endl;
        }
    } while (unit != 'm' && unit != 'f');

    return unit;
}

// Function to calculate falling distance in meters
double CalculateFallingDistance(int timeInSeconds)
{
    return 0.5 * gravityMeters * timeInSeconds * timeInSeconds;         //this equation here of timeInSeconds * timeInSeconds is done to represent the timeInSeconds squared
}

// Function to convert meters to feet if needed
double ConvertToFeet(double meters)
{
    return meters * metersToFeet;
}

// Function to display a table of falling distances for each second up to the given time
void DisplayDistanceTable(int timeInSeconds, char unit)
{
    cout << left << setw(10) << "Seconds" << setw(15) << "Distance" << endl;
    cout << "=======================" << endl;

    for (int second = 1; second <= timeInSeconds; ++second)
    {
        double distance = CalculateFallingDistance(second);
        if (unit == 'f')
        {
            distance = ConvertToFeet(distance);
        }
        cout << left << setw(10) << second << setw(2) << fixed << setprecision(2) << distance << " " << (unit == 'm' ? "m" : "f") << endl;
    }
}

// Main function
int main()
{
    DisplayProgramInformation();                //lab 3, name, and course

    // Prompt for and validate falling time
    int timeInSeconds = ReadInt("Please enter the number of seconds (1-60): ", 1, 60);              //this establishes the minValue and maxValue from earlier

    // Prompt for unit selection (m for meters or f for feet)
    char unit = ReadUnits();

    // Displays the falling distance table
    DisplayDistanceTable(timeInSeconds, unit);
}
