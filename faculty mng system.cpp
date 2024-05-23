#include <iostream>
#include<string>
#include <fstream>
#include<windows.h>
#include<stdlib.h>
using namespace std;

struct Faculty {
    int id;
    string name;
    string department;
    double salary;
    Faculty* next;
};

Faculty* head = NULL;
bool isLoggedIn = false;

void addFacultyMember(int id, string name, string department, double salary) {

    Faculty* newFaculty = new Faculty();
    newFaculty->id = id;
    newFaculty->name = name;
    newFaculty->department = department;
    newFaculty->salary = salary;
    newFaculty->next = head;
    head = newFaculty;
    cout << "Faculty member added successfully." << endl;
}

void searchFacultyMember(int id) {


    Faculty* current = head;
    while (current != NULL) {
        if (current->id == id) {
            cout << "Faculty Member Found: " << endl;
            cout << "ID: " << current->id << endl;
            cout << "Name: " << current->name << endl;
            cout << "Department: " << current->department << endl;
            cout << "Salary: " << current->salary << endl;
            return;
        }
        current = current->next;
    }
    cout << "Faculty Member Not Found" << endl;
}

void deleteFacultyMember(int id) {


    Faculty* current = head;
    Faculty* prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (prev != NULL) {
                prev->next = current->next;
            }
            else {
                head = current->next;
            }
            delete current;
            cout << "Faculty Member Deleted" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Faculty Member Not Found" << endl;
}

void printAllFacultyMembers() {

    fstream facdetails;
    facdetails.open("faculty's details txt", ios::app);


    Faculty* current = head;
    while (current != NULL) {
      
        cout << "ID: " << current->id << endl;
        cout << "Name: " << current->name << endl;
        cout << "Department: " << current->department << endl;
        cout << "Salary: " << current->salary << endl;
        current = current->next;


        facdetails << "ID: " << current->id << endl;
        facdetails << "Name: " << current->name << endl;
        facdetails << "Department: " << current->department << endl;
        facdetails << "Salary: " << current->salary << endl;
        facdetails.close();
    }
}

void generateDepartmentReport(string department) {


    Faculty* current = head;
    cout << "Faculty members in department " << department << ": " << endl;
    while (current != NULL) {
        if (current->department == department) {
            system("CLS");
            cout << "ID: " << current->id << endl;
            cout << "Name: " << current->name << endl;
            cout << "Salary: " << current->salary << endl;
        }
        current = current->next;
    }
}

void generateSalaryReport(double salary) {


    Faculty* current = head;
    cout << "Faculty members earning above " << salary << ": " << endl;
    while (current != NULL) {
        if (current->salary > salary) {
            system("CLS");
            cout << "ID: " << current->id << endl;
            cout << "Name: " << current->name << endl;
            cout << "Department: " << current->department << endl;
            cout << "Salary: " << current->salary << endl;
        }
        current = current->next;
    }
}


void updateFacultyMember(int id, string name, string department, double salary) {
    Faculty* current = head;
    while (current != NULL) {
        if (current->id == id) {
            current->name = name;
            current->department = department;
            current->salary = salary;
            cout << "Faculty member information updated successfully." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Faculty member not found." << endl;
}

void logout() {
    isLoggedIn = false;
    cout << "You have successfully logged out." << endl;
}

void login() {
    string username, password;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "------------------------------------------------------------" << endl;
    cout << "     'LOGIN HERE'    " << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    // check if the username and password are correct
    if (username == "admin" && password == "password") {
        cout << "Login successful!" << endl;
        isLoggedIn = true;
        int choice;
        do {
            cout << "                                                     " << endl;
            cout << "                                                     " << endl;
            cout << "                                                     " << endl;
            cout << " * ***------Faculty Management System------ * ***" << endl;
            cout << "                                                     " << endl;
            cout << "            Main Menu      " << endl;
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            cout << "===================================================================================" << endl;
            cout << endl;
            cout << "                                                     " << endl;
            cout << "1. Add Faculty Member" << endl;
            cout << "2. Search Faculty Member" << endl;
            cout << "3. Delete Faculty Member" << endl;
            cout << "4. Print All Faculty Members" << endl;
            cout << "5. Generate Department Report" << endl;
            cout << "6. Generate Salary Report" << endl;
            cout << "7. Update Faculty Member" << endl;
            cout << "8. Logout" << endl;
            cout << "                                                     " << endl;

            cout << "Enter your choice: ";
            cout << "                                                     " << endl;
            cin >> choice;

            switch (choice) {

            case 1: {
                int id;
                string name;
                string department;
                double salary;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Department: ";
                cin >> department;
                cout << "Enter Salary: ";
                cin >> salary;
                addFacultyMember(id, name, department, salary);
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID: ";
                cin >> id;
                searchFacultyMember(id);
                break;
            }
            case 3: {

                int id;
                cout << "Enter ID: ";
                cin >> id;
                deleteFacultyMember(id);
                break;
            }
            case 4:
                printAllFacultyMembers();
                break;
            case 5: {
                string department;
                cout << "Enter department: ";
                cin >> department;
                generateDepartmentReport(department);
                break;
            }
            case 6: {
                double salary;
                cout << "Enter minimum salary: ";
                cin >> salary;
                generateSalaryReport(salary);
                break;
            }
            case 7: {
                int id;
                string name;
                string department;
                double salary;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Department: ";
                getline(cin, department);
                cout << "Enter Salary: ";
                cin >> salary;
                updateFacultyMember(id, name, department, salary);
                break;
            }
            case 8:
                logout();
                break;

            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
                break;
            }
        } while (choice != 8);

    }
    else {
        cout << "Incorrect username or password. Please try again." << endl;
    }
}

int main() {
    login();
    return 0;
    system("pause");
}
