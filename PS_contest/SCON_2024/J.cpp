#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<pair<int,ll>> g[301010];
int m[301010];

bool can_fs(ll mask, int ms) {
    int st = 1;
    queue<int> qu; qu.push(st);
    while (!qu.empty()) {
        auto o = qu.front(); qu.pop();
        if (o == n) return true;
        for (auto [oo, w] : g[o]) if (m[oo] < ms && (w & ~mask) == 0) {
            m[oo] = ms;
            qu.push(oo);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k; cin >> n >> k;
    while(k--) {
        int a, b; ll w; cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    ll mask = (1LL<<62)-1; int ms = 1;
    for (ll i = 61LL; i >= 0LL; --i) {
        if (can_fs(mask & ~(1LL<<i), ms++))
            mask = mask & ~(1LL<<i);
    }
    cout << mask;
}