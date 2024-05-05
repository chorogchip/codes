#include<bits/stdc++.h>
using namespace std;

bool d[128][128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int xx = x1; xx < x2; ++xx)
        for (int yy = y1; yy < y2; ++yy) if (!d[yy][xx])
            ++res, d[yy][xx] = 1;
    }
    cout << res;
}