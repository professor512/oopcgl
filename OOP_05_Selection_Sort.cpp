// Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.

#include<iostream>
using namespace std;

// Global variables
#define SIZE 10  // Macro for array size
int n;          // Number of elements

// Template function for selection sort
template<class T>
void selectionSort(T A[]) {
    int i, j, minIndex;
    T temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the elements
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }

    // Display sorted array
    cout << "\nSorted array: ";
    for (i = 0; i < n; i++) {
        cout << " " << A[i];
    }
    cout << endl;
}

int main() {
    int choice;
    char C[SIZE];
    int A[SIZE];
    float B[SIZE];
    int i;

    cout << "-----------------------";
    do {
        cout << "\n 1. Integer Array";
        cout << "\n 2. Float Array";
        cout << "\n 3. Exit";
        cout << "\n Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nEnter Total Number of Integer Elements: ";
                cin >> n;

                if (n > SIZE) {
                    cout << "Error: Exceeds maximum size (" << SIZE << ")!\n";
                    break;
                }

                cout << "Enter Integer Elements:\n";
                for (i = 0; i < n; i++) {
                    cin >> A[i];
                }
                selectionSort(A);  // Call template function for integers
                break;
            }

            case 2: {
                cout << "\nEnter Total Number of Float Elements: ";
                cin >> n;

                if (n > SIZE) {
                    cout << "Error: Exceeds maximum size (" << SIZE << ")!\n";
                    break;
                }

                cout << "Enter Float Elements:\n";
                for (i = 0; i < n; i++) {
                    cin >> B[i];
                }
                selectionSort(B);  // Call template function for floats
                break;
            }

            case 3: {
                cout << "********** Program Exited Successfully **********" << endl;
                exit(0);
            }

            default: {
                cout << "\nInvalid Choice! Please try again." << endl;
            }
        }
    } while (choice != 3);

    return 0;
}
