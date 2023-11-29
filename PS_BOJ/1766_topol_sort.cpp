#include<bits/stdc++.h>
using namespace std;

vector<int> G[101010];
int connect_cnt[101010];
priority_queue<int> qu;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        connect_cnt[b]++;
    }
    for (int i = 1; i <= n; ++i) if (!connect_cnt[i])
        qu.push(-i);
    while (!qu.empty()) {
        int o = -qu.top(); qu.pop();
        cout << o << ' ';
        for (auto oo : G[o]) {
            if (!--connect_cnt[oo]) qu.push(-oo);
        }
    }
}