#include <graphics.h>

#include <iostream>
using namespace std;

int x1 = 100, y1 = 200;
int x2 = 250, y2 = 200;
int x3 = 150, y3 = 280;

void DramTriangle() {
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
}

void translate() {
    int s_x = 0, s_y = 0;
    cout << "How many step do you want to translate (x, y):";
    cin >> s_x >> s_y;

    int i = 0;
    for (i = 0; i < min(abs(s_x), abs(s_y)); i++) {
        if (s_x >= 0) {
            x1 += 1;
            x2 += 1;
            x3 += 1;
        } else {
            x1 -= 1;
            x2 -= 1;
            x3 -= 1;
        }
        if (s_y >= 0) {
            y1 += 1;
            y2 += 1;
            y3 += 1;
        } else {
            y1 -= 1;
            y2 -= 1;
            y3 -= 1;
        }
        cleardevice();
        line(x1, y1, x2, y2);
        line(x1, y1, x3, y3);
        line(x2, y2, x3, y3);
        delay(10);
    }
    for (int j = i; j < abs(s_x); j++) {
        if (s_x >= 0) {
            x1 += 1;
            x2 += 1;
            x3 += 1;
        } else {
            x1 -= 1;
            x2 -= 1;
            x3 -= 1;
        }
        cleardevice();
        line(x1, y1, x2, y2);
        line(x1, y1, x3, y3);
        line(x2, y2, x3, y3);
        delay(10);
    }
    for (int k = i; k < abs(s_y); k++) {
        if (s_y >= 0) {
            y1 += 1;
            y2 += 1;
            y3 += 1;
        } else {
            y1 -= 1;
            y2 -= 1;
            y3 -= 1;
        }
        cleardevice();
        line(x1, y1, x2, y2);
        line(x1, y1, x3, y3);
        line(x2, y2, x3, y3);
        delay(10);
    }
}

void scaling() {
    cout << "Scale factor:";
    float sf;
    cin >> sf;
    line(x1 / sf, y1 * sf, x2 * sf, y2 * sf);
    line(x1 / sf, y1 * sf, x3, y3 * sf);
    line(x2 * sf, y2 * sf, x3, y3 * sf);
}

void question() {
    int x;
    while (true) {
        system("cls");
        cout << "Choose:" << endl;
        cout << "1. Translate" << endl;
        cout << "2. Scale" << endl;
        cin >> x;
        switch (x) {
            case 1:
                translate();
                break;
            case 2:
                scaling();
                break;
            default:
                break;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    DramTriangle();
    question();
    getchar();
    getchar();
    closegraph();
    return 0;
}