#include<bits/stdc++.h>
using namespace std;

int n, m;
int d[512][512];
int nd[512][512];
bool mask[512][512];

bool all_zero() {
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) if (d[i][j]) return false;
    return true;
}

void dfs(int i, int j) {
    if (mask[i][j]) return;
    mask[i][j] = 1;
    if (d[i+1][j]) dfs(i+1, j);
    if (d[i-1][j]) dfs(i-1, j);
    if (d[i][j+1]) dfs(i, j+1);
    if (d[i][j-1]) dfs(i, j-1);
}
int count() {
    memset(mask, 0, sizeof(mask));
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) if (d[i][j] && !mask[i][j]) {
        ++cnt;
        dfs(i, j);
    }
    return cnt;
}

void process() {
    memcpy(nd, d, sizeof(d));
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        int c =
            (d[i+1][j] == 0) +
            (d[i-1][j] == 0) +
            (d[i][j+1] == 0) +
            (d[i][j-1] == 0);
        nd[i][j] = max(0, d[i][j] - c);
    }
    memcpy(d, nd, sizeof(d));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> d[i][j];
    int time = 0;
    while (!all_zero()) {
        int cnt = count();
        if (cnt >= 2) { cout << time; exit(0); }
        process();
        ++time;
    }
    cout << 0;
}