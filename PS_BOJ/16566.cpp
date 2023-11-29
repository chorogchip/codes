#include<bits/stdc++.h>
using namespace std;

int par[4'010'101];

int find(int v) {
    if (par[v] == v) return v;
    else return par[v] = find(par[v]);
}

void merge(int lo, int hi) {
    int hh = find(hi);
    par[lo] = hh;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> vec(m);
    for (int i = 0; i < m; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end());
    int kk = 0;
    for (int i = 1; i <= n; ++i)
        if (i == vec[kk]) par[i] = i, ++kk;
        else par[i] = vec[kk];
    while(k--) {
        int x; cin >> x;
        int xx = find(x+1); cout << xx << '\n';
        merge(xx, xx+1);
    }
}