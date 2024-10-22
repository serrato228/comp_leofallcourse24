#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function overloading - 2 or more functions have the same name but different signatures

/// @brief Reads an integer from console
/// @param message Message to display
/// @return Integral value provided by user

int ReadInt(std::string message)
{
    //Display message
    //Get int value and return

    cout << message;

    int value;
    cin >> value;

    return value;
}

int ReadInt(string message, int minValue, int maxValue)
{
    int value;
    do
    {
        value = ReadInt(message);

        if (value < minValue || value > maxValue)
            cout << "Value must be between " << minValue << " and " << maxValue << endl;
    } while (value < minValue || value > maxValue);

    return value;
}

int ReadInt(string message, int minValue)
{
    return ReadInt(message, minValue, INT32_MAX);
   /* int value;
    do
    {
        value = ReadInt(message);

        if (value < minValue)
            cout << "Value must be at least " << minValue << endl;
    } while (value < minValue);

    return value;*/
}

struct Employee
{
    int Id;
    string Name;

    int YearsOfService;
    double PayRate;
};

void Display(Employee employee)
{
    cout << employee.Name << endl;
    cout << employee.Id << endl;
    cout << "Years of service: " << employee.YearsOfService << endl;
    cout << "Pay rate: " << employee.PayRate << endl;

    employee.YearsOfService *= 2;
};
void GivePayRaise(Employee& employee)
{
    //If Years > 3, payrate + $5
    //If Years > 5, payrate + $10
    if (employee.YearsOfService > 3)
        employee.PayRate += 5;
    else if (employee.YearsOfService > 5)
        employee.PayRate += 10;
}

int main()
{
    /*int value = ReadInt("Enter a value between 1 and 10: ", 1, 10);

    int positive = ReadInt("Enter a positive number: ", 0);

    int anyValue = ReadInt("Enter a number: ");

    int test = ReadInt("a message", 10, 50);*/

    Employee employee;
    employee.Id = 10;
    employee.Name = "Bob";
    employee.YearsOfService = 10;
    employee.PayRate = 20.5;

    Display(employee);
    GivePayRaise(employee);
    Display(employee);
}