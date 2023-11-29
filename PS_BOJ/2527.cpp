#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 0; i < 4; ++i) {
        int x0, y0, x1, y1, x2, y2, x3, y3;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (x1 < x2 || x3 < x0 || y1 < y2 || y3 < y0) goto D;
        if (x1 == x2 || x3 == x0) {
            if (y1 == y2 || y3 == y0) goto C;
            goto B;
        }
        if (y1 == y2 || y3 == y0) goto B;
        goto A;

        A: cout << "a\n"; continue;
        B: cout << "b\n"; continue;
        C: cout << "c\n"; continue;
        D: cout << "d\n"; continue;
    }
}