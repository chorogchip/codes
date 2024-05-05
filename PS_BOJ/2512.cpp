#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (auto& o : v) cin >> o;
    int m; cin >> m;
    int lo = 0, hi = m;
    while (lo < hi) {
        int md = lo + hi + 1 >> 1;
        int sum = 0;
        for (auto o : v) sum += min(md, o);
        if (sum > m) hi = md - 1;
        else lo = md;
    }
    int mx = 0; for (auto o : v) mx = max(mx, min(lo, o));
    cout << mx;
}