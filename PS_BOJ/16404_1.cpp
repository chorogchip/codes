#include<bits/stdc++.h>
using namespace std;

struct {
    int par;
    int l, r;
    vector<int> g;
} t[101010];
int seg[801010];

int DFS(int i, int num) {
    t[i].l = num;
    num++;
    for (auto o : t[i].g) num = DFS(o, num);
    t[i].r = num-1;
    return num;
}

void add(int i, int s, int e, int l, int r, int val) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) { seg[i] += val; return; }
    int md = s + e >> 1;
    add(i<<1, s, md, l, r, val);
    add((i<<1)+1, md+1, e, l, r, val);
}

int sum(int i, int s, int e, int x) {
    if (x < s || e < x) return 0;
    int ret = seg[i];
    if (s == e) return ret;
    int md = s + e >> 1;
    return ret + sum(i<<1, s, md, x) + sum((i<<1)+1, md+1, e, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i].par;
        if (i != 1) t[t[i].par].g.push_back(i);
    }
    DFS(1, 0);
    int nn = 32 - __builtin_clz(n-1);
    while(m--) {
        int a, i; cin >> a >> i;
        if (a == 1) {
            int w; cin >> w;
            add(1, 0, n-1, t[i].l, t[i].r, w);
        } else cout << sum(1, 0, n-1, t[i].l) << '\n';
    }
}