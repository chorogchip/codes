#include<bits/stdc++.h>
using namespace std;

int ans[512][512];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> a(n), b(n);
    for (int i = 0; i < n; ++i) a[i].second = b[i].second = i;
    for (auto& o : a) cin >> o.first;
    for (auto& o : b) cin >> o.first;
    sort(a.begin(), a.end(), greater{});
    for (int i = 0; i < n; ++i) {
        sort(b.begin(), b.end(), greater{});
        int cnt = a[i].first;
        for (int j = 0; j < n && cnt > 0; ++j) {
            if (b[j].first) --b[j].first, --cnt, ans[a[i].second][b[j].second] = 1;
        }
        if (cnt > 0) goto E;
    }
    for (int j = 0; j < n; ++j) if (b[j].first) goto E;
    cout << 1 << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << ans[i][j];
        cout << '\n';
    }
    return 0;
    E: cout << -1;
}