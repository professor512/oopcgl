#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

class Graphics {
public:
    void ddaLine(int x1, int y1, int x2, int y2) {
        float dx = x2 - x1;
        float dy = y2 - y1;
        int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
        float xInc = dx / steps;
        float yInc = dy / steps;
        float x = x1, y = y1;
        
        for (int i = 0; i <= steps; i++) {
            putpixel(round(x), round(y), WHITE);
            x += xInc;
            y += yInc;
        }
    }

    void bresenhamCircle(int xc, int yc, int r) {
        int x = 0, y = r;
        int p = 3 - 2 * r;
        
        while (x <= y) {
            putpixel(xc + x, yc + y, WHITE);
            putpixel(xc - x, yc + y, WHITE);
            putpixel(xc + x, yc - y, WHITE);
            putpixel(xc - x, yc - y, WHITE);
            putpixel(xc + y, yc + x, WHITE);
            putpixel(xc - y, yc + x, WHITE);
            putpixel(xc + y, yc - x, WHITE);
            putpixel(xc - y, yc - x, WHITE);
            
            x++;
            if (p < 0) {
                p += 4 * x + 6;
            } else {
                y--;
                p += 4 * (x - y) + 10;
            }
        }
    }

    void drawEquilateralTriangle(int xc, int yc, int radius) {
        // Calculate the vertices of the equilateral triangle
        int x1 = xc + radius * cos(0);
        int y1 = yc + radius * sin(0);
        int x2 = xc + radius * cos(2 * M_PI / 3);
        int y2 = yc + radius * sin(2 * M_PI / 3);
        int x3 = xc + radius * cos(4 * M_PI / 3);
        int y3 = yc + radius * sin(4 * M_PI / 3);

        // Draw the triangle using DDA
        ddaLine(x1, y1, x2, y2);
        ddaLine(x2, y2, x3, y3);
        ddaLine(x3, y3, x1, y1);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    Graphics g;
    
    // Coordinates for the large circle and its radius
    int xc = 300, yc = 300, r = 100;
    
    // Draw the large circle
    g.bresenhamCircle(xc, yc, r);
    
    // Draw the equilateral triangle inside the large circle
    g.drawEquilateralTriangle(xc, yc, r);
    
    // Coordinates for the small circle inside the triangle
    int smallRadius = r / 2;  // Smaller radius for the circle inside the triangle
    
    // Draw the small circle inside the triangle
    g.bresenhamCircle(xc, yc, smallRadius);
    
    getch();
    closegraph();
    return 0;
}
