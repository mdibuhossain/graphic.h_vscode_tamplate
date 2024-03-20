#include <graphics.h>

#include <iostream>
using namespace std;

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
        code |= TOP;
    else if (y > ymax)
        code |= BOTTOM;

    return code;
}

// Function to clip a line segment from (x1, y1) to (x2, y2) using Cohen-Sutherland algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);

    bool accept = false;

    while (true) {
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        putpixel(x1, y1, WHITE);
        putpixel(x2, y2, WHITE);
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
            if (codeOut & BOTTOM) {
                // Point is above the clip window
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & TOP) {
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
        setcolor(YELLOW);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the clipping window coordinates
    int xmin = 50, ymin = 50, xmax = 400, ymax = 300;

    // Draw the clipping window
    rectangle(xmin, ymin, xmax, ymax);

    // Draw the original line
    setcolor(12);
    line(20, 40, 500, 320);

    // Clip the line using Cohen-Sutherland algorithm
    cohenSutherlandClip(20, 40, 500, 320, xmin, ymin, xmax, ymax);

    getchar();
    closegraph();
    return 0;
}
