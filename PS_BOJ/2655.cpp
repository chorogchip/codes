#include<bits/stdc++.h>
using namespace std;

int n;
int len[128], hei[128], wei[128];
vector<int> g[128];
int val[128];
vector<int> res;

int calc(int i) {
    if (val[i]) return val[i];
    int cnt = 0;
    for (auto o : g[i]) cnt = max(cnt, calc(o));
    return val[i] = cnt + hei[i];
}

void trace(int i) {
    res.push_back(i);
    if (g[i].empty()) return;
    int mx = 0, mxi;
    for (auto o : g[i])
        if (mx < val[o])
            mx = val[o], mxi = o;
    trace(mxi);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> len[i] >> hei[i] >> wei[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) if (j != i) {
            if (wei[j] > wei[i] && len[j] > len[i]) g[i].push_back(j);
        }
    }
    int mx = 0, mxi;
    for (int i = 1; i <= n; ++i) {
        calc(i);
        if (mx < val[i])
            mx = val[i], mxi = i;
    }
    trace(mxi);
    cout << res.size() << '\n';
    for (auto o : res) cout << o << '\n';
}