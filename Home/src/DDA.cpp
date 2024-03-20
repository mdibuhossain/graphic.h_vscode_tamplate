#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

// function for rounding off the pixels
int roundCustom(float n) {
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 1);
}

// Function for line generation
void DDALine(int x0, int y0, int x1, int y1) {
    // Calculate dx and dy
    int dx = x1 - x0;
    int dy = y1 - y0;

    int step;

    // If dx > dy we will take step as dx
    // else we will take step as dy to draw the complete
    // line
    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    // Calculate x-increment and y-increment for each step
    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;

    // Take the initial points as x and y
    float x = x0;
    float y = y0;

    for (int i = 0; i < step; i++) {
        putpixel(roundCustom(x), roundCustom(y), WHITE);
        // cout << round(x) << " " << round(y) << "\n";
        x += x_incr;
        y += y_incr;
        // delay(10);
    }
}

// Driver code
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 200, y0 = 180, x1 = 180, y1 = 160;

    // Function call
    DDALine(x0, y0, x1, y1);

    getchar();

    return 0;
}