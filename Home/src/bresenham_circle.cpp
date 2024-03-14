#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

void BresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r, d = 3 - (2 * r);

    while (x <= y) {
        if (d <= 0) {
            d = d + (4 * x) + 6;
        } else {
            d = d + (4 * x) - (4 * y) + 10;
            y = y - 1;
        }
        x = x + 1;
        putpixel(x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(y + xc, x + yc, WHITE);
        putpixel(y + xc, -x + yc, WHITE);
        putpixel(-y + xc, -x + yc, WHITE);
        putpixel(-y + xc, x + yc, WHITE);
    }
}

int main(void) {
    int xc, yc, r, gdriver = DETECT, gmode, errorcode;
    /* initialize graphics and local variables */

    char data[] = "C:\\TDM-GCC-32\\lib\\libbgi.a";  // static file
    initgraph(&gdriver, &gmode, data);

    errorcode = graphresult();

    if (errorcode != grOk) {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);
    }
    printf("Enter the values of xc and yc :");
    cin >> xc >> yc;
    printf("Enter the value of radius  :");
    cin >> r;
    BresenhamCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}