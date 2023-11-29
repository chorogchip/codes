#include <bits/stdc++.h>
using namespace std;

long double MM = -1, mm = 1000000000.0L;

void asdf(int x0, int y0, int x1, int y1, int x2, int y2) {
    int dx1 = x1 - x0;
    int dx2 = x2 - x0;
    int dy1 = y1 - y0;
    int dy2 = y2 - y0; 
    if (dy2*dx1==dy1*dx2) {
        cout << "-1.0";
        exit(0);
    }
    dx1 *= dx1;
    dx2 *= dx2;
    dy1 *= dy1;
    dy2 *= dy2;
    long double res =
        sqrtl(dx1+dy1)+sqrtl(dx2+dy2);
    res *= 2.0L;
    MM = max(MM, res);
    mm = min(mm, res);
}

int main() {
    int x0, y0, x1, y1, x2, y2;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    asdf(x0, y0, x1, y1, x2, y2);
    asdf(x1, y1, x0, y0, x2, y2);
    asdf(x2, y2, x1, y1, x0, y0);
    printf("%.9Lf", MM-mm);
}