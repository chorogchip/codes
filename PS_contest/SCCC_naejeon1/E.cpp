#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    const int INF = 1010101;
    int max0 = -1, max1 = -1, min0 = INF, min1 = INF;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            max0 = max(max0, i);
            min0 = min(min0, i);
        } else {
            max1 = max(max1, i);
            min1 = min(min1, i);
        }
    }
    int d0 = max0 - min0;
    int d1 = max1 - min1;
    if (d0 < d1) {
        swap(max0, max1);
        swap(min0, min1);
        swap(d0, d1);
    }
    // d0
    if (d0 == 0) {
        cout << -1;
        return 0;
    }
    ++min0;
    ++max0;
    cout << min0 << ' ' << max0 - 1 << ' ' << min0 + 1 << ' ' << max0;
}