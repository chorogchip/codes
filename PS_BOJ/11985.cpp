#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll Amax[1024];
ll Amin[1024];
ll cost[1024];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m; ll k; cin >> k;
    for (int i = 1; i <= n; ++i) {
        ll x; cin >> x;
        ll tmp = cost[m] + k + m * (Amax[m] - Amin[m]);
        for (int j = m; j > 0; --j) {
            Amax[j] = max(Amax[j-1], x);
            Amin[j] = min(Amin[j-1], x);
            cost[j] = cost[j-1];
        }
        Amax[0] = Amin[0] = 0; cost[0] = tmp;
    }
}