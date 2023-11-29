#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

int a[1024][1024];
bool v[1024][1024];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n, m; cin >> n >> m;
        int res = 0;
        memset(a, 0, sizeof(a));
        memset(v, 0, sizeof(v));
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
        
        queue<pii> qu;
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        if (!v[i][j] && a[i][j]) {
            int cnt = 0;
            qu.push({i, j});
            v[i][j] = 1;
            while (!qu.empty()) {
                auto o = qu.front(); qu.pop();
                cnt += a[o.x][o.y];
                #define AAA(xx, yy) if (!v[xx][yy] && a[xx][yy]) v[xx][yy] = 1, qu.push({xx,yy});
                AAA(o.x-1,o.y)
                AAA(o.x+1,o.y)
                AAA(o.x,o.y-1)
                AAA(o.x,o.y+1)
            }
            res = max(res, cnt);
        }
        cout << res << '\n';
    }
}
