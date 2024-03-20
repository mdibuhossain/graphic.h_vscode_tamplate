#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main() {
    int x1, y1, x2, y2, dx, dy, p;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    cout << "enter the value of x1,y1: ";
    cin >> x1 >> y1;
    cout << "enter the value of x2,y2: ";
    cin >> x2 >> y2;
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);
    p = 2 * dy - dx;
    while (x1 <= x2) {
        putpixel(x1, y1, WHITE);
        if (p < 0) {
            x1++;
            p = p + 2 * dy;
        } else {
            x1++;
            y1++;
            p = p + 2 * (dy - dx);
        }
    }
    getch();
    closegraph();
}