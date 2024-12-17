#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

class KochCurve {
public:
    // Function to draw Koch curve recursively
    void koch(int it, int x1, int y1, int x5, int y5) {
        int x2, y2, x3, y3, x4, y4;
        int dx, dy;

        // Base case: if no iterations left, draw a straight line
        if (it == 0) {
            line(x1, y1, x5, y5);  // Draw line from (x1, y1) to (x5, y5)
        } else {
            delay(10);  // Small delay to visualize the drawing

            // Calculate the new points for the Koch curve
            dx = (x5 - x1) / 3;
            dy = (y5 - y1) / 3;

            // Calculate the points of the new triangle
            x2 = x1 + dx;
            y2 = y1 + dy;
            x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6);
            y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);
            x4 = 2 * dx + x1;
            y4 = 2 * dy + y1;

            // Recursively draw the smaller Koch curves
            koch(it - 1, x1, y1, x2, y2);
            koch(it - 1, x2, y2, x3, y3);
            koch(it - 1, x3, y3, x4, y4);
            koch(it - 1, x4, y4, x5, y5);
        }
    }
};

int main() {
    KochCurve k;  // Create an object of the KochCurve class
    int it;  // Variable to store number of iterations

    // Ask user for the number of iterations
    cout << "Enter Number Of Iterations: ";
    cin >> it;

    int gd = DETECT, gm;  // Graphics driver and mode
    initgraph(&gd, &gm, (char*)"C:/MinGW/lib/libbgi.a");  // Initialize graphics mode

    // Call the koch function to draw the Koch snowflake
    k.koch(it, 150, 20, 20, 280);  // First side
    k.koch(it, 280, 280, 150, 20);  // Second side
    k.koch(it, 20, 280, 280, 280);  // Third side

    getch();  // Wait for user input before closing the graphics window
    closegraph();  // Close the graphics window

    return 0;
}
