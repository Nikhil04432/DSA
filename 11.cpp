#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Student {
    string roll_number;
    string name;
    string division;
    string address;
};

void add_student_info() {
    ofstream file("student_info.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
    
    Student student;
    cout << "Enter Roll Number: ";
    getline(cin, student.roll_number);
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);
    
    file << student.roll_number << "," << student.name << "," << student.division << "," << student.address << endl;
    file.close();
    
    cout << "Student information added successfully." << endl;
}

void delete_student_info() {
    string roll_number;
    cout << "Enter Roll Number of student to delete: ";
    getline(cin, roll_number);
    
    ifstream file("student_info.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
    
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        if (line.find(roll_number) == string::npos) {
            lines.push_back(line);
        }
    }
    file.close();
    
    ofstream outFile("student_info.txt");
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
    
    for (const auto& l : lines) {
        outFile << l << endl;
    }
    outFile.close();
    
    if (lines.size() < 1) {
        cout << "No student found with that roll number." << endl;
    } else {
        cout << "Student information deleted successfully." << endl;
    }
}

void display_student_info() {
    string roll_number;
    cout << "Enter Roll Number of student to display information: ";
    getline(cin, roll_number);
    
    ifstream file("student_info.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
    
    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        if (token == roll_number) {
            found = true;
            cout << "Student Information:" << endl;
            cout << "Roll Number: " << token << endl;
            getline(ss, token, ',');
            cout << "Name: " << token << endl;
            getline(ss, token, ',');
            cout << "Division: " << token << endl;
            getline(ss, token, ',');
            cout << "Address: " << token << endl;
            break;
        }
    }
    file.close();
    
    if (!found) {
        cout << "No student found with that roll number." << endl;
    }
}

int main() {
    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Add Student Information" << endl;
        cout << "2. Delete Student Information" << endl;
        cout << "3. Display Student Information" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                add_student_info();
                break;
            case 2:
                delete_student_info();
                break;
            case 3:
                display_student_info();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
