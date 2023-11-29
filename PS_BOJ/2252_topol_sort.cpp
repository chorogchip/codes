#include <bits/stdc++.h>
using namespace std;

vector<int> G[32101];
unsigned char state[32101];
vector<int> res;

void write(int i) {
    state[i] = 1;
    for (auto o : G[i]) if (!state[o])
        write(o);
    res.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) if (!state[i]) {
        write(i);
    }
    for (int i = res.size() - 1; i >= 0; --i)
        cout << res[i] << ' ';
}