// Develop a program in C++ to create a database of student’s information system containing the following
// information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone
// number, Driving license no. and other. Construct the database with suitable member functions. Make use of
// constructor, default constructor, copy constructor, destructor, static member functions, friend class, this
// pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.

#include<iostream>
#include<string>
using namespace std;

// Forward declaration of friend class
class StudentInfo;

// Class to manage Student Data
class Student {
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob; // Date of Birth
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicense;
    string otherDetails;
    static int studentCount; // Static member to track the number of students

public:
    // Default Constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        studentClass = "Unknown";
        division = 'X';
        dob = "00-00-0000";
        bloodGroup = "Unknown";
        contactAddress = "Unknown";
        telephoneNumber = "Unknown";
        drivingLicense = "Unknown";
        otherDetails = "None";
        studentCount++;
    }

    // Parameterized Constructor
    Student(string n, int roll, string cls, char div, string birth, string bg, string addr, string phone, string license, string other)
        : name(n), rollNumber(roll), studentClass(cls), division(div), dob(birth), bloodGroup(bg), contactAddress(addr), telephoneNumber(phone), drivingLicense(license), otherDetails(other) {
        studentCount++;
    }

    // Copy Constructor
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        studentClass = s.studentClass;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephoneNumber = s.telephoneNumber;
        drivingLicense = s.drivingLicense;
        otherDetails = s.otherDetails;
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Static member function to display student count
    static void displayStudentCount() {
        cout << "\nTotal Students: " << studentCount << endl;
    }

    // Friend function to display student data
    friend void displayStudentDetails(const Student &s);

    // Member function to input data dynamically
    void inputDetails() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Class: ";
        cin >> studentClass;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter Contact Address: ";
        cin.ignore();
        getline(cin, contactAddress);
        cout << "Enter Telephone Number: ";
        cin >> telephoneNumber;
        cout << "Enter Driving License Number: ";
        cin >> drivingLicense;
        cout << "Enter Other Details: ";
        cin.ignore();
        getline(cin, otherDetails);
    }

    // Inline function to display basic details
    inline void displayBasicDetails() const {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

// Initialize static member
int Student::studentCount = 0;

// Friend function to display full student details
void displayStudentDetails(const Student &s) {
    cout << "\n--- Student Details ---\n";
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNumber << endl;
    cout << "Class: " << s.studentClass << endl;
    cout << "Division: " << s.division << endl;
    cout << "Date of Birth: " << s.dob << endl;
    cout << "Blood Group: " << s.bloodGroup << endl;
    cout << "Contact Address: " << s.contactAddress << endl;
    cout << "Telephone Number: " << s.telephoneNumber << endl;
    cout << "Driving License Number: " << s.drivingLicense << endl;
    cout << "Other Details: " << s.otherDetails << endl;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    // Dynamically allocate memory for students
    Student *students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].inputDetails();
    }

    cout << "\nDisplaying all student details:\n";
    for (int i = 0; i < n; i++) {
        displayStudentDetails(students[i]);
    }

    // Display total student count
    Student::displayStudentCount();

    // Free dynamically allocated memory
    delete[] students;

    cout << "\nProgram Ended Successfully." << endl;
    return 0;
}
