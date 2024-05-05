#include<bits/stdc++.h>
using namespace std;

bool d[128][128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int sum = 0, n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        for (int xx = x; xx < x + 10; ++xx)
        for (int yy = y; yy < y + 10; ++yy) if (!d[yy][xx])
            d[yy][xx] = 1, ++sum;
    }
    cout << sum;
}