#include<bits/stdc++.h>
using namespace std;

int par[101010];
int dif[101010];
int dep[101010];

pair<int,int> find(int a) {
    int ret = 0;
    while (par[a] != a) ret += dif[a], a = par[a];
    return {a, ret};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(true) {
        int n, m; cin >> n >> m;
        if (n == 0) break;
        for (int i = 1; i <= n; ++i) par[i] = i, dif[i] = dep[i] = 0;
        while(m--) {
            char c; int a, b; cin >> c >> a >> b;
            if (c == '!') {
                int w; cin >> w;
                auto ao = find(a);
                auto bo = find(b);
                if (dep[ao.first] > dep[bo.first]) swap(ao, bo), w = -w;
                par[ao.first] = bo.first;
                if (dep[ao.first] == dep[bo.first]) ++dep[bo.first];
                dif[ao.first] = -ao.second + bo.second - w;
            } else {
                auto ao = find(a);
                auto bo = find(b);
                if (ao.first == bo.first) cout << bo.second - ao.second << '\n';
                else cout << "UNKNOWN\n";
            }
        }
    }
}