#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll d[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) cin >> d[i];
    ll res = 0, cost; cin >> cost;
    for (int i = 1; i < n; ++i) {
        ll x; cin >> x;
        res += d[i] * cost;
        cost = min(cost, x);
    }  
    cout << res;
}