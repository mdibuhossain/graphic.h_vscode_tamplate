#include <graphics.h>
#include <math.h>
#include <stdio.h>

int x1, x2, y1, y2, mx, my, depth;

void draw();

void scale();

int main() {
    int gd = DETECT, gm, c;

    initgraph(&gd, &gm, "d:\\tc\\bgi");

    printf("\n\t\t3D Transformation Scaling\n\n");

    printf("Enter 1st top value (x1, y1): ");

    scanf("%d%d", &x1, &y1);

    printf("Enter right bottom value (x2, y2): ");

    scanf("%d%d", &x2, &y2);

    depth = (x2 - x1) / 4;

    mx = (x1 + x2) / 2;

    my = (y1 + y2) / 2;

    draw();

    getch();

    closegraph();

    return 0;
}

void draw()

{
    // Draw the original 3D cuboid

    bar3d(x1, y1, x2, y2, depth, 1);
}

void scale() {
    int x, y, a1, a2, b1, b2, dep;

    printf("\n\nEnter scaling factors along x and y axes: ");

    scanf("%d%d", &x, &y);

    a1 = mx + (x1 - mx) * x;

    a2 = mx + (x2 - mx) * x;

    b1 = my + (y1 - my) * y;

    b2 = my + (y2 - my) * y;

    dep = (a2 - a1) / 4;

    // Set the graphics color to highlight the original cuboid in a different color

    setcolor(RED);

    draw();

    // Draw the scaled 3D cuboid

    setcolor(WHITE);

    bar3d(a1, b1, a2, b2, dep, 1);
}