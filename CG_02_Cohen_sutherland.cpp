#include <iostream>
#include <graphics.h>
using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Clipping window boundaries
int X_MIN, Y_MIN, X_MAX, Y_MAX;

// Function to compute region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < X_MIN) // To the left of clipping window
        code |= LEFT;
    if (x > X_MAX) // To the right of clipping window
        code |= RIGHT;
    if (y < Y_MIN) // Below the clipping window
        code |= BOTTOM;
    if (y > Y_MAX) // Above the clipping window
        code |= TOP;

    return code;
}

// Function to implement Cohen-Sutherland Line Clipping Algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1); // Region code for first endpoint
    int code2 = computeCode(x2, y2); // Region code for second endpoint
    bool accept = false;

    while (true) {
        // Case 1: Both endpoints are inside the clipping window
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        }
        // Case 2: Both endpoints share an outside region (trivially rejected)
        else if (code1 & code2) {
            break;
        }
        // Case 3: Line needs clipping (partially inside and outside)
        else {
            int codeOut;
            int x, y;

            // Select an endpoint outside the clipping window
            codeOut = (code1 != 0) ? code1 : code2;

            // Find intersection point
            if (codeOut & TOP) { // Point is above the window
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) { // Point is below the window
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) { // Point is to the right of the window
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) { // Point is to the left of the window
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            // Replace the endpoint outside the clipping window with the intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // Draw the clipped line if accepted
    if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);
        cout << "Line clipped and drawn successfully." << endl;
    } else {
        cout << "Line rejected (completely outside the window)." << endl;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"C:/MinGW/lib/libbgi.a");

    // Input the clipping window coordinates
    cout << "Enter clipping window coordinates (X_MIN, Y_MIN, X_MAX, Y_MAX): ";
    cin >> X_MIN >> Y_MIN >> X_MAX >> Y_MAX;

    // Draw the clipping window
    setcolor(WHITE);
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    // Input the line coordinates
    int x1, y1, x2, y2;
    cout << "Enter line coordinates (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the original line
    setcolor(GREEN);
    line(x1, y1, x2, y2);
    cout << "Original line drawn in GREEN." << endl;

    // Perform clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
