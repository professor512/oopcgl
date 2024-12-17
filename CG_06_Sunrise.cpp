#include <graphics.h>  // Include graphics.h for graphics functions

int main() {
    int gd = DETECT, gm;  // Graphics driver and mode variables
    initgraph(&gd, &gm, NULL);  // Initialize the graphics system

    setbkcolor(BLACK);  // Set the background color to black (0 represents black)
    cleardevice();  // Clear the screen to apply the black background

    int midx, midy, r = 10;  // Declare variables for screen center (midx, midy) and sun radius (r)
    midx = getmaxx() / 2;  // Set midx to the center of the screen (horizontal axis)

    // Loop to animate the sun (increasing the sun's radius)
    while (r <= 50) {
        cleardevice();  // Clear the screen to create the animation effect (clear the previous frame)

        setcolor(WHITE);  // Set the color to white for drawing the mountains

        // Draw the mountains using lines
        line(0, 310, 160, 150);    // Left mountain
        line(160, 150, 320, 310);  // Peak of the left mountain
        line(320, 310, 480, 150);  // Peak of the right mountain
        line(480, 150, 640, 310);  // Right mountain
        line(0, 310, 640, 310);    // Base of the mountains (ground)

        // Draw the sun as an arc (simulate rising/sinking of the sun)
        setcolor(14);  // Set the color to yellow for the sun
        arc(midx, 310, 225, 133, r);  // Draw an arc for the sun (radius increases over time)

        floodfill(midx, 300, 15);  // Fill the sun with yellow color (color 15)

        // Additional coloring effects for sky and ground
        if (r > 20) {
            setcolor(7);  // Set color to light blue for the sky
            floodfill(2, 2, 15);  // Fill the top-left corner with the sky color

            setcolor(6);  // Set color to orange for the sunset effect
            floodfill(150, 250, 15);  // Fill the left middle area with sunset color
            floodfill(550, 250, 15);  // Fill the right middle area with sunset color

            setcolor(2);  // Set color to dark green for the grass/ground
            floodfill(2, 450, 15);  // Fill the bottom-left corner with grass color
        }

        delay(100);  // Delay to create smooth animation (100 ms between frames)
        r += 2;  // Increase the radius of the sun to simulate rising/sinking
    }

    getch();  // Wait for a key press before closing the window
    closegraph();  // Close the graphics window and clean up
}
