#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

void BresenhamCircle(int h, int k, int r) {
    int x = 0;
    int y = r;
    int d = 3 - (2 * r);

    while (x <= y) {
        putpixel(x + h, y + k, WHITE);
        putpixel(y + h, x + k, WHITE);
        putpixel(-x + h, y + k, WHITE);
        putpixel(x + h, -y + k, WHITE);
        putpixel(y + h, -x + k, WHITE);
        putpixel(-y + h, x + k, WHITE);
        putpixel(-x + h, -y + k, WHITE);
        putpixel(-y + h, -x + k, WHITE);
        if (d <= 0) {
            d = d + (4 * x) + 6;
        } else {
            d = d + (4 * x) - (4 * y) + 10;
            y--;
        }
        x++;
    }
}

int main(void) {
    int h, k, r, gdriver = DETECT, gmode, errorcode;

    char data[] = "";
    initgraph(&gdriver, &gmode, data);

    errorcode = graphresult();

    if (errorcode != grOk) {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);
    }

    printf("Enter the values of h and k :");
    cin >> h >> k;
    printf("Enter the value of radius  :");
    cin >> r;
    BresenhamCircle(h, k, r);

    getch();
    closegraph();
    return 0;
}