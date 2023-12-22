// Write a program that stores and displays the records of the customer from a
// file the following information for account of the customer is to be stored.
// Account no, account type, name, old balance, new balance, last payment,
// date of last payment. Also display the current account status by comparing
// current payment and previous balance. Also calculate the current balance by
// subtracting the current payment from the previous balance.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct CustomerRecord {
    int accountNumber;
    string accountType;
    string name;
    double oldBalance;
    double newBalance;
    double lastPayment;
    string dateOfLastPayment;
};

void displayCustomerRecord(const CustomerRecord& customer) {
    cout << "Account Number: " << customer.accountNumber << "\n";
    cout << "Account Type: " << customer.accountType << "\n";
    cout << "Name: " << customer.name << "\n";
    cout << "Old Balance: $" << customer.oldBalance << "\n";
    cout << "New Balance: $" << customer.newBalance << "\n";
    cout << "Last Payment: $" << customer.lastPayment << "\n";
    cout << "Date of Last Payment: " << customer.dateOfLastPayment << "\n\n";
}

void calculateAccountStatus(CustomerRecord& customer) {
    double currentPayment = customer.newBalance - customer.oldBalance;
    cout << "Current Payment: $" << currentPayment << "\n";

    if (currentPayment >= 0) {
        cout << "Account Status: Payment Due\n";
    } else {
        cout << "Account Status: Credit Balance\n";
    }

    double currentBalance = customer.oldBalance - currentPayment;
    cout << "Current Balance: $" << currentBalance << "\n\n";
}

int main() {
    ifstream inputFile;
    inputFile.open("customer_records.txt");

    CustomerRecord customer;

    while (inputFile >> customer.accountNumber >> customer.accountType >> customer.name
                     >> customer.oldBalance >> customer.newBalance >> customer.lastPayment
                     >> customer.dateOfLastPayment) {
        // Display the customer record
        displayCustomerRecord(customer);

        // Calculate and display account status and balance
        calculateAccountStatus(customer);
    }

    inputFile.close();

    return 0;
}
