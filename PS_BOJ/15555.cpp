#include<bits/stdc++.h>
using namespace std;

string arr[3010];
int dh[4096][4096], dv[4096][4096], d[4096][4096];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] = "#" + arr[i];
    }
    
    for (int y = 1; y <= n; ++y) {
        int s = 0;
        for (int x = 1; x <= m; ++x) {
            if (x >= 3 && arr[y][x] == 'W' &&
                arr[y][x-1] == 'G' && arr[y][x-2] == 'R') ++s;
            dh[y][x] = dh[y-1][x] + s;
        }
    }
    for (int x = 1; x <= m; ++x) {
        int s = 0;
        for (int y = 1; y <= n; ++y) {
            if (y >= 3 && arr[y][x] == 'W' &&
                arr[y-1][x] == 'G' && arr[y-2][x] == 'R') ++s;
            dv[y][x] = dv[y][x-1] + s;
        }
    }
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            d[y][x] = d[y-1][x] + d[y][x-1] - d[y-1][x-1];
            if (arr[y][x] == 'W') {
                if (y >= 3 && arr[y-1][x] == 'G' && arr[y-2][x] == 'R') {
                    d[y][x] = max(d[y][x],
                        d[y-3][x] + d[y][x-1] - d[y-3][x-1] + 1);
                }
                if (x >= 3 && arr[y][x-1] == 'G' && arr[y][x-2] == 'R') {
                    d[y][x] = max(d[y][x],
                        d[y][x-3] + d[y-1][x] - d[y-1][x-3] + 1);
                }
            }
        }
    }
    cout << d[n][m];
}