#include<bits/stdc++.h>
using namespace std;


bool d[128][128];

int calc(int y, int x) {
    d[y][x] = 1;
    int sum = 1;
    if (!d[y-1][x]) sum += calc(y-1, x);
    if (!d[y+1][x]) sum += calc(y+1, x);
    if (!d[y][x-1]) sum += calc(y, x-1);
    if (!d[y][x+1]) sum += calc(y, x+1);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i <= m; ++i) d[0][i] = d[n+1][i] = 1;
    for (int i = 0; i <= n; ++i) d[i][0] = d[i][m+1] = 1;
    while(k--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1+1; y <= y2; ++y)
        for (int x = x1+1; x <= x2; ++x) d[y][x] = 1;
    }
    vector<int> res;
    for (int y = 1; y <= n; ++y)
    for (int x = 1; x <= m; ++x) if (!d[y][x]) res.push_back(calc(y, x));
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto o : res) cout << o << ' ';
}