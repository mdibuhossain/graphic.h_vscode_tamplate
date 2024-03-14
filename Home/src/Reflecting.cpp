#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>

#include <iostream>
using namespace std;

char IncFlag;
int PolygonPoints[3][2] = {{10, 100}, {110, 100}, {110, 200}};

void DrawAxis() {
    cleardevice();
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
}

void Triangle() {
    int iCnt;
    cleardevice();
    DrawAxis();
    for (iCnt = 0; iCnt < 3; iCnt++) {
        line(PolygonPoints[iCnt][0], PolygonPoints[iCnt][1],
             PolygonPoints[(iCnt + 1) % 3][0], PolygonPoints[(iCnt + 1) % 3][1]);
    }
}
void Reflect(int xis) {
    float Angle;
    int iCnt;
    int Tx, Ty;
    for (iCnt = 0; iCnt < 3; iCnt++)
        PolygonPoints[iCnt][xis] = (((xis == 1) ? getmaxy() : getmaxx()) - PolygonPoints[iCnt][xis]);
}

void question() {
    int x;
    int inp;
    while (true) {
        system("cls");
        setcolor(WHITE);
        cout << "Choose:" << endl;
        cout << "1. Reflect" << endl;
        cout << "2. Shearing" << endl;
        cin >> x;
        switch (x) {
            case 1:
                DrawAxis();
                Triangle();
                cout << "Which axis do you want to reflect?" << endl;
                cout << "1. X-axis" << endl;
                cout << "OTHER. Y-axis" << endl;
                cin >> inp;
                if (inp == 1) {
                    Reflect(0);
                    Triangle();
                } else {
                    Reflect(1);
                    Triangle();
                }
                break;
            case 2:
                cleardevice();

                line(100, 0, 200, 0);
                line(200, 0, 200, 200);
                line(200, 200, 100, 200);
                line(100, 200, 100, 0);
                cout << "Which Axis do you want to Shearing:" << endl;
                cout << "1. X-axis Shearing" << endl;
                cout << "OTHER. Y-axis Shearing" << endl;
                cin >> inp;
                if (inp == 1) {
                    float shx;
                    cout << "Enter shear factor along x-axis :";
                    cin >> shx;
                    setcolor(12);
                    line((100 + (0 * shx)), 0, (200 + (0 * shx)), 0);
                    line((200 + (0 * shx)), 0, (200 + (200 * shx)), 200);
                    line((200 + (200 * shx)), 200, (100 + (200 * shx)), 200);
                    line((100 + (200 * shx)), 200, (100 + (0 * shx)), 0);
                } else {
                    float shy;
                    cout << "Enter shear factor along y-axis :";
                    cin >> shy;
                    setcolor(12);
                    line(100, 10 + (shy * 100), 200, 10 + (shy * 200));
                    line(200, 10 + (shy * 200), 200, 200 + (shy * 200));
                    line(200, 200 + (shy * 200), 100, 200 + (shy * 100));
                    line(100, 200 + (shy * 100), 100, 10 + (shy * 100));
                }
                break;
            default:
                break;
        }
    }
}

int main() {
    int gDriver = DETECT, gMode;
    int iCnt;
    initgraph(&gDriver, &gMode, "");
    DrawAxis();
    for (iCnt = 0; iCnt < 3; iCnt++) {
        PolygonPoints[iCnt][0] += (getmaxx() / 2);
        PolygonPoints[iCnt][1] = (getmaxy() / 2) - PolygonPoints[iCnt][1];
    }

    question();
}
