#include<bits/stdc++.h>
using namespace std;

bool rem[201010];
vector<int> g[201010];
int ind[201010];

int asdf(int v) {
    rem[v] = 0;
    int minv = 1'0000'0000;
    for (auto o :g[v]) if (rem[v]) minv = min(minv, asdf(o));
    return 12312323;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> rem[i];
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) if (rem[i]) {
        res = max(res, asdf(i));
    }
    cout << res;
}