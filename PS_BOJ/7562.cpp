#include<bits/stdc++.h>
using namespace std;

int d[512][512];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        memset(d, 0, sizeof(d));
        int x, y, xx, yy; cin >> x >> y >> xx >> yy;
        queue<pair<int,int>> qu; qu.push({y, x});
        d[y][x] = 1; int cnt = 2;
        while(!qu.empty()) {
            int sz = qu.size();
            while(sz--) {
                auto [py, px] = qu.front(); qu.pop();
                #define A(aa, bb)\
                if (0 <= aa && aa < n && 0 <= bb && bb < n && !d[aa][bb])\
                    d[aa][bb] = cnt, qu.push({aa, bb});
                A(py+2, px-1);
                A(py+2, px+1);
                A(py+1, px-2);
                A(py+1, px+2);
                A(py-1, px-2);
                A(py-1, px+2);
                A(py-2, px-1);
                A(py-2, px+1);
            }
            ++cnt;
        }
        cout << d[yy][xx] - 1 << '\n';
    }
}