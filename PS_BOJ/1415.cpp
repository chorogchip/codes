#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[501010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    a.push_back(-1);
    int cnt = 0;
    dp[0] = 1;
    for (int i = 0, cnt = 1; i < n; ++i) {
        if (a[i] == a[i+1]) { ++cnt; continue; }
        if (a[i] == 0) { dp[0] += cnt; cnt = 1; continue; }
        for (int j = 500'000 - a[i]; j >= 0; --j)
            for (int k = 1; k <= cnt; ++k) {
                int dest = j + k * a[i];
                if (dest > 500'000) break;
                dp[dest] += dp[j];
            }
        cnt = 1;
    }
    ll sum = dp[2];
    for (int i = 4; i <= 500'000; i += 2) dp[i] = -1;
    for (int i = 3; i <= 500'000; i += 2) if (dp[i] != -1) {
        sum += dp[i];
        for (ll j = (ll)i * i; j <= 500'000LL; j += i + i) dp[j] = -1;
    }
    cout << sum;
}
