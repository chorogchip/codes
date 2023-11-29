#include<bits/stdc++.h>
using namespace std;

int par[2048*2048];

int find(int i) {
    if (par[i] == i) return i;
    else return par[i] = find(par[i]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    par[aa] = bb;
}

int r, c;
unsigned short d[2048 * 2048];

int to(int x, int y) {
    return x + y * 2048;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int r, c; cin >> r >> c;
    int st = 0, fn = 0;
    memset(d, -1, sizeof(d));
    queue<pair<int,int>> qu;
    for (int i = 1; i < 2048 * 2048; ++i) par[i] = i;
    for (int y = 1; y <= r; ++y) {
        for (int x = 1; x <= c; ++x) {
            char c; cin >> c;
            if (c == '.') qu.push({x, y});
            else if (c == 'X');
            else if (c == 'L') {
                qu.push({x, y});
                if (st == 0) st = to(x, y);
                else fn = to(x, y);
            }
        }
    }
    int cnt = 0;
    while (!qu.empty()) {
        int sz = qu.size();
        for (int s = 0; s < sz; ++s) {
            auto o = qu.front(); qu.pop();
            auto too = to(o.first, o.second);
            if (o.first > 0 && o.second > 0 && o.first <= c && o.second <= r &&
                d[too] == (unsigned short)-1) {
                d[too] = cnt;
                vector<int> res;
                #define ad(xx, yy) if (d[to(xx, yy)] != (unsigned short)-1) res.push_back(to(xx, yy)); else qu.push({xx, yy});
                ad(o.first+1, o.second)
                ad(o.first-1, o.second)
                ad(o.first, o.second+1)
                ad(o.first, o.second-1)
                #undef ad
                for (int i = 0; i < res.size(); ++i) merge(too, res[i]);
                if (find(st) == find(fn)) { cout << cnt; exit(0); }
            }
        }
        ++cnt;
    }

}