#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 201010;
const int MID = INF/2;
const ll MOD = 1'000'000'000 + 7;

vector<int> g[INF];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        int n = str.size();
        int cnt = 0;
        int m = 0, M = 0;
        g[MID].push_back(0);
        for (int i = 0; i < n; ++i) {
            int x = (str[i] - '0' << 1) - 1;
            cnt += x;
            m = min(m, cnt);
            M = max(M, cnt);
            g[MID + cnt].push_back(i+1);
        }
        ll ans = 0;
        for (int i = m; i <= M; ++i) {
            auto& vec = g[MID+i];
            ll left_sum = 0;
            for (auto o : vec) {
                ll right = n+1 - o;
                ans += left_sum * right;
                ans %= MOD;
                left_sum += o + 1;
                //cout << o << ' ' << right << ' ' << left_sum << ' ' << ans << '\n';
            }
            vec.clear();
        }
        cout << ans % MOD << '\n';
    }
}