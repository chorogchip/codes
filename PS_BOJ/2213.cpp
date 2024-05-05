#include<bits/stdc++.h>
using namespace std;

int w[10101];
vector<int> g[10101];
vector<int> chl[10101];
pair<int,int> cal[10101];

void calc(int v, int prev) {
    int resa = 1, resb = 0;
    for (auto o : g[v]) if (o != prev) {
        calc(o, v);
        auto [a, b] = cal[o];
        resa += b;
        if (a > b) { chl.push_back(o); resb += a; }
        else resb += b;
    }
    cal[v] = {resa, resb};
}

vector<int> res;

void ans(int v, bool prev) {
    if (prev) {
        for (auto o : cal[v]) ans(o, false);
    } else {
        auto [a, b] = cal[v];
        if (a > b) {
            res.push_back(v);
            for (auto o : cal[v])
        } else {
            for (auto o : cal[v]) ans(o, false); 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    calc(1, 0);
    ans(1, false);
}