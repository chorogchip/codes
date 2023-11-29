#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, H, X, Y, P, C = 0;
    cin >> W >> H >> X >> Y >> P; H >>= 1;
    do {
        int x, y; cin >> x >> y;
        x -= X; y -= Y;
        if (x >= 0 && x <= W && y >= 0 && y <= H<<1) goto T;
        y -= H;
        if (x * x + y * y <= H * H) goto T;
        x -= W;
        if (x * x + y * y <= H * H) goto T;
        continue;
        T: ++C;
    } while (--P);
    cout << C;
}