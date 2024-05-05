#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> v(n); for (auto& o : v) cin >> o;
    int lo = 0, hi = 0;
    for (auto o : v) lo = max(lo, o), hi += o;
    while (lo < hi) {
        int md = lo + hi >> 1;
        int cnt = 1;
        int rem = md;
        for (auto o : v) {
            if (o > rem) ++cnt, rem = md;
            rem -= o;
        }
        if (cnt > m) lo = md + 1;
        else hi = md;
    }
    cout << lo;
}