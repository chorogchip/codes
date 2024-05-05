#include<bits/stdc++.h>
using namespace std;

int ac[2048][2048][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int p = 0; p < 2; ++p)
                ac[i][j][p] = ac[i-1][j][p] + ac[i][j-1][p] - ac[i-1][j-1][p];
            char c; cin >> c;
            ++ac[i][j][c=='B'^i+j&1];
        } 
    }
    int res = k*k;
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            for (int p = 0; p < 2; ++p) {
                int cur = ac[i][j][p] - ac[i-k][j][p] - ac[i][j-k][p] + ac[i-k][j-k][p];
                res = min(res, k*k - cur);
            }
        }
    }
    cout << res;
}