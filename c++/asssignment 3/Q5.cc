#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
public:
    string name;
    string address;
    string phoneNumber;

    // Constructor
    Employee(const string& n, const string& addr, const string& phone)
        : name(n), address(addr), phoneNumber(phone) {}

    // Display the details of an employee
    void displayDetails() const {
        cout << setw(15) << left << name << setw(20) << left << address << setw(15) << left << phoneNumber << endl;
    }

    // Write the employee details to a file
    void writeToFile(ofstream& file) const {
        file << name << "\n" << address << "\n" << phoneNumber << "\n";
    }
};

void addRecord(vector<Employee>& employees, ofstream& file) {
    string name, address, phoneNumber;

    cout << "Enter Name: ";
    cin.ignore();  // Ignore any previous newline character
    getline(cin, name);

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);

    employees.emplace_back(name, address, phoneNumber);
    employees.back().writeToFile(file);  // Write the new record to the file
    cout << "Record added successfully.\n";
}

void modifyRecord(vector<Employee>& employees, const string& filename) {
    string targetName;
    cout << "Enter the name of the employee to modify: ";
    cin.ignore();  // Ignore any previous newline character
    getline(cin, targetName);

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening the file for reading!" << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) {
        cerr << "Error opening the temporary file for writing!" << endl;
        inputFile.close();
        return;
    }

    bool found = false;

    // Read from the input file, modify the record, and write to the temporary file
    string line;
    while (getline(inputFile, line)) {
        if (line == targetName) {
            string newAddress, newPhoneNumber;

            cout << "Enter new Address: ";
            getline(cin, newAddress);

            cout << "Enter new Phone Number: ";
            getline(cin, newPhoneNumber);

            tempFile << line << "\n" << newAddress << "\n" << newPhoneNumber << "\n";
            found = true;
        } else {
            tempFile << line << "\n";
        }
    }

    inputFile.close();
    tempFile.close();

    if (remove(filename.c_str()) != 0) {
        cerr << "Error removing the original file!" << endl;
        return;
    }

    if (rename("temp.txt", filename.c_str()) != 0) {
        cerr << "Error renaming the temporary file!" << endl;
        return;
    }

    if (found) {
        cout << "Record modified successfully.\n";
    } else {
        cout << "Employee not found.\n";
    }
}

void retrieveRecord(const string& filename) {
    string targetName;
    cout << "Enter the name of the employee to retrieve: ";
    cin.ignore();  // Ignore any previous newline character
    getline(cin, targetName);

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening the file for reading!" << endl;
        return;
    }

    bool found = false;
    string line;
    while (getline(file, line)) {
        if (line == targetName) {
            found = true;
            cout << "Details of employee " << targetName << ":\n";
            cout << "Name: " << line << "\n";

            getline(file, line);
            cout << "Address: " << line << "\n";

            getline(file, line);
            cout << "Phone Number: " << line << "\n\n";
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee not found.\n";
    }
}


void displayAllRecords(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening the file for reading!" << endl;
        return;
    }

    // Print table headers
    cout << setw(15) << left << "Name" << setw(20) << left << "Address" << setw(15) << left << "Phone" << endl;
    cout << string(50, '-') << endl;

    string name, address, phoneNumber;
    while (getline(file, name)) {
        getline(file, address);
        getline(file, phoneNumber);

        cout << setw(15) << left << name << setw(20) << left << address << setw(15) << left << phoneNumber << endl;
    }

    file.close();
}
int main() {
    vector<Employee> employees;
    char choice;

    const string filename = "employee_records.txt";  // File to store employee records

    do {
        cout << "\nMenu:\n";
        cout << "a. Add a new record\n";
        cout << "b. Modify an existing record\n";
        cout << "c. Retrieve and display an entire record for a given name\n";
        cout << "d. Generate a complete list of all names, addresses, and telephone numbers\n";
        cout << "e. End of computation\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                ofstream outputFile(filename, ios::app);  // Open file in append mode
                if (!outputFile.is_open()) {
                    cerr << "Error opening the file for writing!" << endl;
                    return 1;
                }
                addRecord(employees, outputFile);
                outputFile.close();
                break;
            }
            case 'b':
                modifyRecord(employees, filename);
                break;
            case 'c':
                retrieveRecord(filename);
                break;
            case 'd':
                displayAllRecords(filename);
                break;
            case 'e':
                cout << "End of computation.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 'e');

    return 0;
}
