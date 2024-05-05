#include<bits/stdc++.h>
using namespace std;

bool d[64][64];
int x, y;
void b(int yy, int xx) {
    d[yy][xx] = 0;
#define A(aa, bb) if (d[(aa)][(bb)]) b((aa), (bb));
    A(yy-1, xx)
    A(yy-1, xx-1)
    A(yy, xx-1)
    A(yy+1, xx-1)
    A(yy+1, xx)
    A(yy+1, xx+1)
    A(yy, xx+1)
    A(yy-1, xx+1)
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(1) {
        cin >> x >> y;
        if (x == 0 && y == 0) exit(0);
        memset(d, 0, sizeof(d));
        for (int yy = 1; yy <= y; ++yy)
        for (int xx = 1; xx <= x; ++xx) cin >> d[yy][xx];
        int sum = 0;
        for (int yy = 1; yy <= y; ++yy)
        for (int xx = 1; xx <= x; ++xx) if (d[yy][xx])
            ++sum, b(yy, xx);
        cout << sum << '\n';
    }
}