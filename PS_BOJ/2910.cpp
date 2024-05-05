#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, c; cin >> n >> c;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first, v[i].second = i;
    sort(v.begin(), v.end());
    vector<tuple<int,int,int>> v2;  // -cnt, ord, num
    for (auto o : v) {
        auto [num, ord] = o;
        if (!v2.empty() && get<2>(v2.back()) == num) {
            get<0>(v2.back())--;
            get<1>(v2.back()) = min(get<1>(v2.back()), ord);
        }
        else v2.push_back({-1, ord, num});
    }
    sort(v2.begin(), v2.end());
    for (auto o : v2) {
        auto [cnt, ord, num] = o;
        for (int i = 0; i < -cnt; ++i) cout << num << ' ';
    }
}