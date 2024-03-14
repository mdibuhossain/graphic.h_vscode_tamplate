#include <graphics.h>

#include <iostream>

const int INSIDE = 0;  // 0000
const int LEFT = 1;    // 0001
const int RIGHT = 2;   // 0010
const int BOTTOM = 4;  // 0100
const int TOP = 8;     // 1000

// Function to compute the region code for a point (x, y)
int computeCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

// Function to clip a line segment from (x1, y1) to (x2, y2) using Cohen-Sutherland algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);

    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints are inside the clip window
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside the same region (e.g., to the left of the window)
            break;
        } else {
            // Some part of the line may be inside the window
            int codeOut;
            int x, y;

            // Choose an endpoint outside the clip window
            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            // Find intersection point
            if (codeOut & TOP) {
                // Point is above the clip window
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                // Point is below the clip window
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) {
                // Point is to the right of the clip window
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (codeOut & LEFT) {
                // Point is to the left of the clip window
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // Replace outside point with intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept) {
        // Draw the clipped line
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set the clipping window coordinates
    int xmin = 50, ymin = 50, xmax = 400, ymax = 300;

    // Draw the clipping window
    rectangle(xmin, ymin, xmax, ymax);

    // Draw the original line
    setcolor(BLUE);
    line(20, 30, 300, 400);

    // Clip the line using Cohen-Sutherland algorithm
    cohenSutherlandClip(20, 30, 300, 400, xmin, ymin, xmax, ymax);

    delay(5000);
    getchar();
    closegraph();
    return 0;
}
