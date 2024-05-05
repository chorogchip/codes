#include<bits/stdc++.h>
using namespace std;

int u[501010];

int par(int i) {
    if (i == u[i]) return i;
    else return u[i] = par(u[i]);
}

int asd(int a, int b, int t) {
    int aa = par(a);
    int bb = par(b);
    if (aa == bb) return t;
    else u[aa] = bb;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; ++i) u[i] = i;
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        if (ans) continue;
        ans = asd(a, b, i);
    }
    cout << ans;
}