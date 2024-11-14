/*
Lab 4
Leonardo Serrato
COSC 1436 Fall 2024
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constants
const int MAX_SIZE = 100;

// Function to display program information
void displayProgramInfo() 
{
    cout << "Lab 4: Identifier Calculator" << endl;
    cout << "Leonardo Serrato" << endl;
    cout << "COSC 1436 Fall 2024" << endl << endl;
}

// Obtains the user's input values for the array
int getUserValues(int arr[], int maxSize) 
{
    int value;
    int count = 0;
    cout << "Enter numbers (Enter 0 to stop, negative values are not accepted): " << endl;
    while (count < maxSize) 
    {
        cout << "Enter a value: ";
        cin >> value;

        if (value == 0) break;              //ensures the program stops requesting values as instructed if the user types in 0
        if (value < 0) 
        {
            cout << "Negative values are not allowed. Try again." << endl;          //reminds the user that inputting negative values is not allowed, however it does not break the user out of requesting for numbers, it simply request for valid ones
            continue;
        }

        arr[count++] = value;       //increases the count(number of values) in the array, the functions checks that the user has not typed more than 100 total values after increase
    }

    return count;
}

// Displays the main menu and proides the user with a choice, I added the (sum all values) since it confused me if the A was more adding more values to the array or if it was for adding all the values the user provided
char displayMenu() 
{
    cout << "Main Menu" << endl;
    cout << "A) Add (Sum all values)" << endl;
    cout << "L) Largest" << endl;
    cout << "S) Smallest" << endl;
    cout << "M) Mean" << endl;
    cout << "I) Insert new values" << endl;
    cout << "V) View values" << endl;
    cout << "Q) Quit" << endl;
    cout << "Enter your choice: ";

    char choice;
    cin >> choice;

    return choice;
}

// Finds the largest value in the array
int findLargest(const int arr[], int size) 
{
    int largest = arr[0];
    for (int index = 1; index < size; index++) 
    {
        if (arr[index] > largest) largest = arr[index];
    }

    return largest;
}

// Finds the smallest value in the array
int findSmallest(const int arr[], int size) 
{
    int smallest = arr[0];
    for (int index = 1; index < size; index++) 
    {
        if (arr[index] < smallest) smallest = arr[index];
    }
    return smallest;
}

// Calculate the sum of values in the array
int calculateSum(const int arr[], int size) 
{
    int sum = 0;
    for (int index = 0; index < size; index++) 
    {
        sum += arr[index];
    }

    return sum;
}

// Calculate the mean (average) of the values in the array
double calculateMean(const int arr[], int size) 
{
    if (size == 0) return 0.0;
    return static_cast<double>(calculateSum(arr, size)) / size;
}

// View values in the array (10 values per line)
void viewValues(const int arr[], int size) 
{
    cout << "Array values:" << endl;
    for (int index = 0; index < size; index++) 
    {
        cout << arr[index] << "\t";
        if ((index + 1) % 10 == 0) cout << endl;                //the (%10) makes it so that any remainder is placed on a different line since theoretically, if the array has 22 values, the remained should be 2 but it should be able to have 2 full line of values and a third with the remainder
    }
    cout << endl;
}

// Insert new values into the existing array
void insertValues(int arr[], int& size, int maxSize) 
{
    int value;

    cout << "Enter additional values (0 to stop, negative values are not accepted):" << endl;
    while (size < maxSize) 
    {
        cout << "Enter a value: ";
        cin >> value;

        if (value == 0) break;
        if (value < 0) 
        {
            cout << "Negative values are not allowed. Try again." << endl;
            continue;
        }

        arr[size++] = value;
    }
}

// Main Function
int main() 
{
    displayProgramInfo();

    int numbers [MAX_SIZE];
    int size = getUserValues(numbers, MAX_SIZE);

    char choice;
    do {
        choice = displayMenu();
        switch (tolower(choice)) {
            case 'a':
                cout << "Sum = " << calculateSum(numbers, size) << endl;
                break;
            case 'l':
                cout << "Largest = " << findLargest(numbers, size) << endl;
                break;
            case 's':
                cout << "Smallest = " << findSmallest(numbers, size) << endl;
                break;
            case 'm':
                cout << fixed << setprecision(4);
                cout << "Mean = " << calculateMean(numbers, size) << endl;
                break;
            case 'v':
                viewValues(numbers, size);
                break;
            case 'i':
                insertValues(numbers, size, MAX_SIZE);
                break;
            case 'q':
                cout << "Quitting the program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (tolower(choice) != 'q');
}



