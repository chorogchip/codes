#include<bits/stdc++.h>
using namespace std;

int d[2048][2048];
int par[101010];
int cnt[101010];

int find(int v) {
    if (par[v] == v) return v;
    else return par[v] = find(par[v]);
}

bool merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    if (bb == aa) return false;
    if (cnt[aa] < cnt[bb]) swap(aa, bb);
    par[bb] = aa;
    cnt[aa] += cnt[bb];
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    queue<tuple<int,int,int>> qu;
    for (int i = 1; i <= k; ++i) par[i] = i, cnt[i] = 1;
    for (int kk = 1; kk <= k; ++kk) {
        int a, b; cin >> a >> b;
        qu.push({kk, a, b});
    }
    int cc = 0;
    while(!qu.empty()) {
        int sz = qu.size();
        for (int i = 0; i < sz; ++i) {
            auto o = qu.front(); qu.pop();
            auto [kk, a, b] = o;
            if (a > 0 && b > 0 && a <= n && b <= n && !d[a][b]) {
                d[a][b] = kk;
                #define asd(xx, yy, tt) if (!d[xx][yy]) qu.push({tt, xx, yy}); else merge(kk, d[xx][yy]);
                asd(a+1, b, kk)
                asd(a-1, b, kk)
                asd(a, b+1, kk)
                asd(a, b-1, kk)
                if (cnt[find(1)] == k) { cout << cc; exit(0);}
            }
        }
        ++cc;
    }
}