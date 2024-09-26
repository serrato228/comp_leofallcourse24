// MonthlyInterestRatesCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double initialLoan;
    cout << "Please enter the loan amount (1-1000): ";
    cin >> initialLoan;

    if (initialLoan < 1 || initialLoan > 1000)
    {
        cout << "ERROR: Initial loan amount cannot be less than 1 or greater than 1000" << endl;
        cout << endl;
        cout << "Please enter the loan amount (1-1000): ";
        cin >> initialLoan;
    };

    float interestRatePercentage;
    cout << "Please enter the interest rate percentage (1.0 - 100.0): ";
    cin >> interestRatePercentage;

    if (interestRatePercentage < 1.0 || interestRatePercentage > 100.0)
    {
        cout << "ERROR: Interest rate cannot be less than 1.0 or greater than 100.0" << endl;
        cout << endl;
        cout << "Please enter the interest rate percentage (1.0 - 100.0): ";
        cin >> interestRatePercentage;
    };
    float interestRate = interestRatePercentage / 100;

    float monthlyPayment;
    cout << "How much do you want to pay each month?: ";
    cin >> monthlyPayment;

    if (monthlyPayment < 0 || monthlyPayment > initialLoan);
    {
        cout << "This is an invalid value.";
        cout << endl;
        cout << "How much do you want to pay each month?: ";
        cin >> monthlyPayment;
    }

    cout << left << setw(6) << "Month" << setw(10) << "Balance" << setw(10) << "Payment" << setw(10) << "Interest" << setw(12) << "New Balance" << endl;
    cout << setw(48) << setfill('-') << "" << setfill(' ') << endl;
    cout << fixed << setprecision(2);
    //cout << setw(6) << "1" << setw(8) << initialLoan
}