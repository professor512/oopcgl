// Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an
// input file and read the information from the file.

#include<iostream>
#include<fstream>
using namespace std;

int main() {
    string name;
    int roll;
    string line;

    // Step 1: Create and write to a file
    ofstream fout;
    fout.open("demo.txt", ios::out); // Opens demo.txt for writing
    if (!fout) {
        cout << "Error: Unable to create or open file!" << endl;
        return 1;
    }

    // Input details from user
    cout << "Enter the name of the student: ";
    getline(cin, name);

    cout << "Enter the roll number of the student: ";
    cin >> roll;

    // Write to the file
    fout << "The name of the student is: " << name << endl;
    fout << "The roll number of the student is: " << roll << endl;

    fout.close(); // Close the file after writing
    cout << "Data successfully written to the file.\n" << endl;

    // Step 2: Open the file for reading
    ifstream fin;
    fin.open("demo.txt", ios::in); // Opens demo.txt for reading
    if (!fin) {
        cout << "Error: Unable to open file for reading!" << endl;
        return 1;
    }

    cout << "Reading data from the file:\n";
    while (getline(fin, line)) { // Read line by line
        cout << line << endl;
    }

    fin.close(); // Close the file after reading
    cout << "\nFile successfully closed!" << endl;

    return 0;
}
