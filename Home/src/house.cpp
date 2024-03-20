#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line(150, 70, 300, 70);
    line(150, 70, 100, 130);
    line(300, 70, 350, 130);
    line(100, 130, 350, 130);
    rectangle(120, 130, 330, 250);
    rectangle(150, 170, 180, 200);
    rectangle(210, 180, 250, 250);
    // circle(290, 190, 20);

    setcolor(GREEN);
    rectangle(400, 70, 550, 150);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(401, 71, GREEN);

    setcolor(RED);
    circle(480, 110, 30);
    setfillstyle(SOLID_FILL, RED);
    floodfill(490, 110, RED);

    setcolor(WHITE);
    rectangle(390, 65, 400, 250);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(391, 66, WHITE);

    getch();
    closegraph();
}