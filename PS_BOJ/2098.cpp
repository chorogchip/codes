#include<bits/stdc++.h>
using namespace std;

const int INF = 10'0000'0000;

int n, st;
int w[16][16];
int dp[16][1<<16];

int gooo(int ed, int path) {
    if (dp[ed][path]) return dp[ed][path];
    int res = INF;
    int pp = path;
    while(pp) {
        int j = __builtin_ctz(pp);
        pp &= pp-1;
        res = min(res, gooo(j, path & ~(1<<j)) + w[j][ed]);
    }
    /*
    for (int j = 0; j < n; ++j) if (path & 1<<j) {
        res = min(res, gooo(j, path & ~(1<<j)) + w[j][ed]);
    }*/
    return dp[ed][path] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        cin >> w[i][j];
        if (w[i][j] == 0) w[i][j] = INF;
    }
    int res = INF;
    for (int i = 0; i < n; ++i) {
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < n; ++j) dp[j][0] = w[i][j];
        st = i;
        res = min(res, gooo(i, (1<<n)-1 & ~(1<<i)));
    }
    cout << res;
}