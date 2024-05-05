#include<bits/stdc++.h>
using namespace std;

int n, m;
int d[1024][1024], ans[1024][1024];
int px, py;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            cin >> d[y][x];
            if (d[y][x] == 2) px=x, py=y;
            ans[y][x] = -1;
            if (d[y][x] == 0) ans[y][x] = -2;
        }
    }
    queue<pair<int,int>> qu;
    qu.push({px, py});
    int dist = 0;
    while(!qu.empty()) {
        int sz = (int)qu.size();
        for (int i = 0; i < sz; ++i) {
            auto [xx, yy] = qu.front(); qu.pop();
            if (ans[yy][xx] == -1) {
                ans[yy][xx] = dist;
                qu.push({xx+1,yy});
                qu.push({xx-1,yy});
                qu.push({xx,yy+1});
                qu.push({xx,yy-1});
            }
        }
        ++dist;
    }
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            int asd = ans[y][x];
            int res;
            if (asd == -2) res = 0;
            else if (asd == -1) res = -1;
            else res = asd;
            cout << res << ' ';
        }
        cout << '\n';
    }
}