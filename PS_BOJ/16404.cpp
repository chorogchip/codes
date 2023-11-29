#include <bits/stdc++.h>
using namespace std;

int IN[101010], OUT[101010], T[1<<17];
vector<int> G[101010];
void DFS(int v) {
    static int cnt = 0;
    IN[v] = ++cnt;
    for (int vv : G[v]) DFS(vv);
    OUT[v] = cnt;
}

int S, E, X;
void addd(int i, int l, int r) {
    if (r < S || E < l) return;
    if (S <= l && r <= E) {
        T[i] += X;
        return;
    }
    int md = l + r >> 1;
    addd(i<<1, l, md);
    addd((i<<1)+1, md+1, r);
}
int summ(int i, int l, int r) {
    if (r < S || S < l) return 0;
    if (l == r) return T[i];
    int md = l + r >> 1;
    return summ(i<<1, l, md) + summ((i<<1)+1, md+1, r);
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, x; cin >> n >> m >> x;
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        G[x].push_back(i);
    }
    DFS(1);
    for (int c = 1; c <= m; ++c) {
        int a; cin >> a;
        if (a == 1) {
            int i, w; cin >> i >> w;
            S = IN[i]; E = OUT[i]; X = w;
            addd(1, 1, 1<<17);
        } else {
            int i; cin >> i;
            S = IN[i];
            cout << summ(1, 1, 1<<17) << '\n';
        }
    }
}