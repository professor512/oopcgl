// Write C++ program using STL for sorting and searching user defined records such as personal records
// (Name, DOB, Telephone number etc) using vector container.
// OR
// Write C++ program using STL for sorting and searching user defined records such as Item records (Item
// code, name, cost, quantity etc) using vector container.

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// Structure to hold personal record details
struct PersonalRecord {
    string name;
    string dob; // Date of Birth
    string telephone;

    // Display function
    void display() const {
        cout << "Name: " << name << ", DOB: " << dob << ", Telephone: " << telephone << endl;
    }
};

// Function to input records
void inputRecords(vector<PersonalRecord> &records, int n) {
    for (int i = 0; i < n; i++) {
        PersonalRecord record;
        cout << "\nEnter details for record " << i + 1 << ":\n";
        cin.ignore(); // To clear input buffer
        cout << "Enter Name: ";
        getline(cin, record.name);
        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        getline(cin, record.dob);
        cout << "Enter Telephone Number: ";
        getline(cin, record.telephone);
        records.push_back(record);
    }
}

// Function to display all records
void displayRecords(const vector<PersonalRecord> &records) {
    cout << "\n--- Personal Records ---\n";
    for (const auto &record : records) {
        record.display();
    }
}

int main() {
    vector<PersonalRecord> records;
    int n;

    cout << "Enter the number of records: ";
    cin >> n;

    // Input records
    inputRecords(records, n);

    // Sort records based on name using STL sort
    sort(records.begin(), records.end(), [](const PersonalRecord &a, const PersonalRecord &b) {
        return a.name < b.name;
    });

    cout << "\nRecords after sorting by name:";
    displayRecords(records);

    // Search for a record by name using find_if
    string searchName;
    cout << "\nEnter the name to search: ";
    
    getline(cin, searchName);

    auto it = find_if(records.begin(), records.end(), [&searchName](const PersonalRecord &record) {
        return record.name == searchName;
    });

    if (it != records.end()) {
        cout << "\nRecord Found:\n";
        it->display();
    } else {
        cout << "\nNo record found with the name: " << searchName << endl;
    }

    return 0;
}
