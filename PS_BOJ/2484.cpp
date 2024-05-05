#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, ans = 0; cin >> n;
    while(n--) {
        int a[4]; cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a + 4);
        vector<pair<int,int>> v;
        v.push_back({-1, a[0]});
        for (int i = 1; i < 4; ++i)
            if (v.back().second == a[i]) --v.back().first;
            else v.push_back({-1, a[i]});
        sort(v.begin(), v.end());
        int res = 0;
        if (v[0].first == -4) res = 50'000 + 5'000 * v[0].second;
        else if (v[0].first == -3) res = 10'000 + 1'000 * v[0].second;
        else if (v[0].first == -2) {
            if (v[1].first == -2) res = 2'000 + 500 * v[0].second + 500 * v[1].second;
            else res = 1'000 + 100 * v[0].second;
        } else res = 100 * v[3].second;
        ans = max(ans, res);
    }
    cout << ans;
}