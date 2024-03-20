#include <conio.h>
#include <graphics.h>
#include <math.h>

#include <iostream>
using namespace std;

void drawellipse(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, 15);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, 15);
}
void ellipse_midpoint(int xc, int yc, int rx, int ry) {
    // REGION 1
    int x = 0, y = ry, x2, y2;
    float p1 = (ry * ry) - (rx * rx * ry) + (rx * rx) / 4;
    int a = 2 * ry * ry * x;
    int b = 2 * rx * rx * y;
    while (a <= b) {
        drawellipse(xc, yc, x, y);
        x++;
        if (p1 < 0) {
            a = 2 * ry * ry * x;
            p1 = p1 + a + (ry * ry);
        } else {
            y--;
            a = 2 * ry * ry * x;
            b = 2 * rx * rx * y;
            p1 = p1 + a - b + (ry * ry);
        }
        drawellipse(xc, yc, x, y);
        delay(10);
    }
    // REGION 2
    float p2 = ((ry * ry) * (x + 0.5) * (x + 0.5)) + ((rx * rx) * (y - 1) * (y - 1)) - ((rx * rx) * (ry * ry));
    a = 0;
    b = 0;
    while (y >= 0) {
        drawellipse(xc, yc, x, y);
        y--;
        if (p2 < 0) {
            x++;
            a = 2 * ry * ry * x;
            b = 2 * rx * rx * y;
            p2 = p2 + a - b + (rx * rx);
        } else {
            b = 2 * rx * rx * y;
            p2 = p2 - b + (rx * rx);
        }
        drawellipse(xc, yc, x, y);
    }
}

int main() {
    int xc, yc, rx, ry;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    cout << "Enter center coordinate of ellipse :";
    cin >> xc >> yc;
    cout << "Enter radius of Ellipse(rx) :";
    cin >> rx;
    cout << "Enter radius of Ellipse(ry) :";
    cin >> ry;
    ellipse_midpoint(xc, yc, rx, ry);
    getch();
    closegraph();
    return 0;
}
