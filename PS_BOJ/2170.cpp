#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int,bool>> v;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        v.push_back({a, 0});
        v.push_back({b, 1});
    }
    sort(v.begin(), v.end());
    int cnt = 0, prev = 0, ans = 0;
    for (auto o : v) {
        auto [x, b] = o;
        if (b) {
            if (--cnt == 0) ans += x - prev;
        } else {
            if (cnt++ == 0) prev = x;
        }
    }
    cout << ans;
}