#include<bits/stdc++.h>
using namespace std;

struct { int p, l, r; } t[10101];
int mt[10101];
int len;
pair<int,int> ans;

void dfs(int v, int lev) {
    if (t[v].l) dfs(t[v].l, lev + 1);
    ++len;
    if (!mt[lev]) mt[lev] = len;
    pair<int,int> res = {len - mt[lev] + 1, -lev};
    if (ans < res) ans = res;
    if (t[v].r) dfs(t[v].r, lev + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, l, r; cin >> p >> l >> r;
        if (l != -1) t[p].l = l, t[l].p = p;
        if (r != -1) t[p].r = r, t[r].p = p;
    }
    int root = 1;
    while(t[root].p) root = t[root].p;
    dfs(root, 1);
    cout << -ans.second << ' ' << ans.first;
}