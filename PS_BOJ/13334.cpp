#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    int d; cin >> d;
    vector<pair<int,int>> vv; vv.reserve(n);
    for (auto o : v) {
        auto [a, b] = minmax(o.first, o.second);
        if (b - a <= d) vv.push_back({b, a});
    }
    sort(vv.begin(), vv.end());
    priority_queue<int> pqu;
    int ans = 0;
    for (auto o : vv) {
        auto [f, s] = o;
        pqu.push({-s});
        while (!pqu.empty() && -pqu.top() < f - d) pqu.pop();
        ans = max(ans, (int)pqu.size());
    }
    cout << ans;
}