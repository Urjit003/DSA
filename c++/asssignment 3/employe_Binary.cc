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

    Employee() {}
    // Constructor
    Employee(const string& n, const string& addr, const string& phone)
        : name(n), address(addr), phoneNumber(phone) {}

    // Display the details of an employee
    void displayDetails() const {
        cout << setw(15) << left << name << setw(20) << left << address << setw(15) << left << phoneNumber << endl;
    }

    // Write the employee details to a binary file
    void writeToFile(ofstream& file) const {
        file.write(name.c_str(), name.size() + 1);
        file.write(address.c_str(), address.size() + 1);
        file.write(phoneNumber.c_str(), phoneNumber.size() + 1);
    }

    // Read the employee details from a binary file
    void readFromFile(ifstream& file) {
        char buffer[256];

        file.read(buffer, sizeof(buffer));
        name = buffer;

        file.read(buffer, sizeof(buffer));
        address = buffer;

        file.read(buffer, sizeof(buffer));
        phoneNumber = buffer;
    }
};

// Function to add a new record
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

// Function to modify an existing record
void modifyRecord(vector<Employee>& employees, const string& filename) {
    string targetName;
    cout << "Enter the name of the employee to modify: ";
    cin.ignore();  // Ignore any previous newline character
    getline(cin, targetName);

    ifstream inputFile(filename, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Error opening the file for reading!" << endl;
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile.is_open()) {
        cerr << "Error opening the temporary file for writing!" << endl;
        inputFile.close();
        return;
    }

    bool found = false;

    // Read from the input file, modify the record, and write to the temporary file
    Employee tempEmployee;
    while (inputFile.read(reinterpret_cast<char*>(&tempEmployee), sizeof(Employee))) {
        if (tempEmployee.name == targetName) {
            string newAddress, newPhoneNumber;

            cout << "Enter new Address: ";
            getline(cin, newAddress);

            cout << "Enter new Phone Number: ";
            getline(cin, newPhoneNumber);

            tempEmployee.address = newAddress;
            tempEmployee.phoneNumber = newPhoneNumber;

            tempFile.write(reinterpret_cast<const char*>(&tempEmployee), sizeof(Employee));
            found = true;
        } else {
            tempFile.write(reinterpret_cast<const char*>(&tempEmployee), sizeof(Employee));
        }
    }

    inputFile.close();
    tempFile.close();

    if (remove(filename.c_str()) != 0) {
        cerr << "Error removing the original file!" << endl;
        return;
    }

    if (rename("temp.dat", filename.c_str()) != 0) {
        cerr << "Error renaming the temporary file!" << endl;
        return;
    }

    if (found) {
        cout << "Record modified successfully.\n";
    } else {
        cout << "Employee not found.\n";
    }
}

// Function to display details of an employee by name
void retrieveRecord(const string& filename) {
    string targetName;
    cout << "Enter the name of the employee to retrieve: ";
    cin.ignore();  // Ignore any previous newline character
    getline(cin, targetName);

    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening the file for reading!" << endl;
        return;
    }

    bool found = false;
    Employee tempEmployee;
    while (file.read(reinterpret_cast<char*>(&tempEmployee), sizeof(Employee))) {
        if (tempEmployee.name == targetName) {
            found = true;
            tempEmployee.displayDetails();
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee not found.\n";
    }
}

// Function to display details of all employees
void displayAllRecords(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening the file for reading!" << endl;
        return;
    }

    // Print table headers
    cout << setw(15) << left << "Name" << setw(20) << left << "Address" << setw(15) << left << "Phone" << endl;
    cout << string(50, '-') << endl;

    Employee tempEmployee;
    while (file.read(reinterpret_cast<char*>(&tempEmployee), sizeof(Employee))) {
        tempEmployee.displayDetails();
    }

    file.close();
}

int main() {
    vector<Employee> employees;
    char choice;

    const string filename = "employee_records.dat";  // Binary file to store employee records

    // Read all records from the binary file into the vector
    ifstream inputFile(filename, ios::binary);
    if (inputFile.is_open()) {
        Employee tempEmployee;
        while (inputFile.read(reinterpret_cast<char*>(&tempEmployee), sizeof(Employee))) {
            employees.push_back(tempEmployee);
        }
        inputFile.close();
    } else {
        cerr << "Error opening the file for reading!" << endl;
    }

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
                ofstream outputFile(filename, ios::binary | ios::app);  // Open binary file in append mode
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
