/*
 * COSC 1436
 * Lab 2
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Program Information
    cout << "Monthly Interest Rate Calculator" << endl;
    cout << "Leonardo Serrato" << endl;
    cout << "COSC 1436 Fall 2024" << endl;
    cout << endl;

    // Get user input
    double loanAmount;
    double interestRatePercentage;
    double monthlyPayment;

    // Input validation for loan amount
    do {
        cout << "Please enter the loan amount (1-1000): ";
        cin >> loanAmount;
        if (loanAmount < 1 || loanAmount > 1000)
            cout << "ERROR: Loan amount must be between 1 and 1000." << endl;
    } while (loanAmount < 1 || loanAmount > 1000);

    // Input validation for interest rate
    do {
        cout << "Please enter the interest rate percentage (1.0 - 100.0): ";
        cin >> interestRatePercentage;
        if (interestRatePercentage < 1.0 || interestRatePercentage > 100.0)
            cout << "ERROR: Interest rate must be between 1.0 and 100.0." << endl;
    } while (interestRatePercentage < 1.0 || interestRatePercentage > 100.0);

    // Convert interest rate from percentage to decimal
    double interestRate = interestRatePercentage / 100.0;

    // Input validation for monthly payment
    do {
        cout << "Please enter the monthly payment (0-" << loanAmount << "): ";
        cin >> monthlyPayment;
        if (monthlyPayment < 0 || monthlyPayment > loanAmount)
            cout << "ERROR: Monthly payment must be between 0 and " << loanAmount << "." << endl;
    } while (monthlyPayment < 0 || monthlyPayment > loanAmount);
    cout << endl;

    // Table header
    cout << left << setw(10) << "Month" << setw(18) << "Balance" << setw(18) << "Payment" << setw(18) << "Interest" << setw(18) << "New Balance" << endl;
    cout << setw(75) << setfill('-') << "" << setfill(' ') << endl;

    double balance = loanAmount;
    double totalPayments = 0.0;
    double totalInterest = 0.0;

    // Loop through each month
    for (int month = 1; month <= 12; ++month) 
    {
        double interest = 0.0;
        double payment = monthlyPayment;

        // First month has no interest and no payment
        if (month == 1)
        {
            cout << setw(10) << month << "$" << setw(17) << fixed << setprecision(2) << balance << "$" << setw(17) << 0.00 << "$" << setw(17) << 0.00 << "$" << setw(17) << balance << endl;
            continue; // I myself dont understand super well how continue  works since ive only seen the use of continue from videos and I didnt really understand it from class, but I used continue here following a video called C++ Full Course for free by Bro Code on youtube and from the classwork
        }

        // If balance is less than the payment, adjust the payment
        if (balance < monthlyPayment) 
        {
            payment = balance; //this makes it so that the balance never becomes a negative number as the payment will never be more than is required to be paid towards the balance
        }

        // Calculate interest after payment is subtracted
        double remainingBalance = balance - payment;
        interest = remainingBalance * interestRate;
        double newBalance = remainingBalance + interest;

        // Output for the current month
        cout << setw(10) << month << "$" << setw(17) << fixed << setprecision(2) << balance << "$" << setw(17) << payment << "$" << setw(17) << interest << "$" << setw(17) << newBalance << endl;

        // Update totals
        totalPayments += payment;
        totalInterest += interest;

        // Update balance for the next month
        balance = newBalance;

        // If balance becomes 0 or less, stop calculating interest and payments
        if (balance <= 0)
        {
            balance = 0;
            for (int m = month + 1; m <= 12; ++m)
            {
                cout << setw(10) << m << "$" << setw(17) << balance << "$" << setw(17) << 0.00 << "$" << setw(17) << 0.00 << "$" << setw(17) << balance << endl;
            }
            break;
        }
    }

    // Totals
    cout << setw(75) << setfill('-') << "" << setfill(' ') << endl;
    cout << "Total" << setw(23) << "" << "$" << setw(17) << totalPayments << "$" << setw(17) << totalInterest << endl;
}