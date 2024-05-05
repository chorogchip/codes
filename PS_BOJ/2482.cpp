#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll M = 1'000'000'003LL;

ll dp_not[1024], dp_chs[1024];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    ll res = 0;
    dp_not[0] = 1;
    dp_chs[1] = 2;
    for (int i = 2; i < n; ++i) {
        for (int kk = k; kk > 0; --kk) {
            dp_not[kk] += dp_chs[kk];
            dp_not[kk] %= M;
            dp_chs[kk] = dp_not[kk-1];
        }
    }
    res += dp_not[k] + dp_chs[k];
    cout << res % M;
}