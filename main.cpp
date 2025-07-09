#include <iostream>
#include <fstream>
using namespace std;

class Employee {
public:
    string id;
    string name;
    string salary;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore(); // to clear newline from buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }
};

// File to store employee records
const string FILE_NAME = "employees.txt";

// Function to add employee to file
void addEmployee() {
    Employee emp;
    emp.input();

    ofstream outFile(FILE_NAME, ios::app);
    if (outFile.is_open()) {
        outFile << emp.id << "," << emp.name << "," << emp.salary << endl;
        outFile.close();
        cout << "Employee added successfully.\n";
    } else {
        cout << "Error opening file.\n";
    }
}

// Function to display all employees
void viewEmployees() {
    ifstream inFile(FILE_NAME);
    if (!inFile) {
        cout << "No employee records found.\n";
        return;
    }

    Employee emp;
    string line;
    cout << "\nEmployee List:\n";
    while (getline(inFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find_last_of(',');



        emp.id = line.substr(0, pos1);
        emp.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        emp.salary = line.substr(pos2 + 1);
        emp.display();
    }

    inFile.close();
}

// Function to search employee by ID
void searchEmployee() {
    string searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    ifstream inFile(FILE_NAME);
    string line;
    bool found = false;
    while (getline(inFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find_last_of(',');

        string id = line.substr(0, pos1);
        string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string salary = line.substr(pos2 + 1);

        if (id == searchId) {
            cout << "Employee found: ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Employee not found.\n";
}

// Function to delete employee by ID
void deleteEmployee() {
    string delId;
    cout << "Enter ID to delete: ";
    cin >> delId;

    ifstream inFile(FILE_NAME);
    ofstream tempFile("temp.txt");

    string line;
    bool deleted = false;

    while (getline(inFile, line)) {
        size_t pos1 = line.find(',');
        string id = line.substr(0, pos1);

        if (id != delId) {
            tempFile << line << endl;
        } else {
            deleted = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (deleted)
        cout << "Employee deleted successfully.\n";
    else
        cout << "Employee ID not found.\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n==== Employee Management System ====\n";
        cout << "1. Add Employee\n";
        cout << "2. View All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Delete Employee by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << choice;

        switch (choice) {
        case 1: addEmployee(); break;
        case 2: viewEmployees(); break;
        case 3: searchEmployee(); break;
        case 4: deleteEmployee(); break;
        case 5: cout << "Exiting program...\n"; break;
        default: cout << "Invalid choice!\n"; break;
        }
        choice = 0;
    } while (choice != 5);

    return 0;
}
