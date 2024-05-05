#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    const int INF = 100'000;
    int xm = INF, xM = -INF, ym = INF, yM = -INF;
    int n; cin >> n;
    while(n--) {
        int x, y; cin >> x >> y;
        xm = min(xm, x);
        xM = max(xM, x);
        ym = min(ym, y);
        yM = max(yM, y);
    }
    cout << (long long)(yM - ym) * (xM - xm);
}