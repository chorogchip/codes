#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<int,int>> ops(m);
    for (int i = 0; i < m; ++i) {
        int a, c; cin >> a >> c;
        ops[i] = {c, a};
    }
    sort(ops.begin(), ops.end());
    int rem = n;
    ll cost = 0;
    for (int i = 0; i < m; ++i) {
        if (rem == 1) break;
        int prev = rem;
        rem = gcd(rem, ops[i].second);
        int con = prev - rem;
        cost += (ll)con * (ll)ops[i].first;
    }
    if (rem == 1) cout << cost;
    else cout << -1;
}