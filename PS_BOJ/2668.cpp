#include<bits/stdc++.h>
using namespace std;

int to[128];
int d[128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x; to[i] = x;
        d[x]++;
    }
    queue<int> qu;
    for (int i = 1; i <= n; ++i) if (d[i] == 0) qu.push(i);
    int res = n;

    while (!qu.empty()) {
        auto o = qu.front(); qu.pop();
        --res;
        if (--d[to[o]] == 0) qu.push(to[o]);
        to[o] = 0;
    }
    vector<int> ress;
    for (int i = 1; i <= n; ++i) if (to[i]) ress.push_back(i);
    sort(ress.begin(), ress.end());
    cout << res << '\n';
    for (auto o : ress) cout << o << '\n';
}