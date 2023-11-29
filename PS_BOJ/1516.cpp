#include<bits/stdc++.h>
using namespace std;

int t[512];
vector<int> g[512];
int dp[512];

int solve(int i) {
    if (dp[i]) return dp[i];
    int res = 0;
    for (auto o : g[i])
        res = max(res, solve(o));
    return dp[i] = res + t[i];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        for (int x; cin >> x, x != -1;)
            g[i].push_back(x);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        cout << solve(i) << '\n';
}