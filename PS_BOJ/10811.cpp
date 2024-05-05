#include<bits/stdc++.h>
using namespace std;

int d[128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x, y, v = -1;
    for (int yy = 1; yy <= 9; ++yy) for (int xx = 1; xx <= 9; ++xx) {
        int a; cin >> a;
        if (a > v) v = a, x = xx, y = yy;
    }
    cout << v << '\n' << y << ' ' << x;
}