#include<bits/stdc++.h>
using namespace std;

int arr[64][64];

pair<int,int> get_dir(int dir) {
    if (dir == 0) return {-1, 0};
    if (dir == 1) return {0, 1};
    if (dir == 2) return {1, 0};
    if (dir == 3) return {0, -1};
    return {0, 0};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int r, c, d; cin >> r >> c >> d;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) cin >> arr[y][x];
    }
    int cnt = 0;
    while (true) {
        if (arr[r][c] == 0) arr[r][c] = 2, ++cnt;
        bool nxt =
            arr[r+1][c] == 0 || arr[r-1][c] == 0 ||
            arr[r][c+1] == 0 || arr[r][c-1] == 0;
        if (nxt) {
            d = (d + 3) % 4;
            auto [yy, xx] = get_dir(d);
            if (arr[r+yy][c+xx] == 0) r+=yy, c+=xx;
        } else {
            auto [yy, xx] = get_dir(d);
            if (arr[r-yy][c-xx] != 1) r-=yy, c-=xx;
            else break;
        }
    }
    cout << cnt;
}