#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v[32];

int process() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        //for (auto o : v[i]) cout << o << ' '; cout << " => ";

        auto& vv = v[i];
        int sz = vv.size();
        int idx = 0;
        for (int j = 1; j < sz; ++j) {
            if (vv[idx] == vv[j]) {
                res = max(res, vv[idx] *= 2);
                if (++j < sz) vv[++idx] = vv[j];
            } else {
                vv[++idx] = vv[j];
            }
        }
        vv.resize(min(sz, idx + 1));

        //for (auto o : v[i]) cout << o << ' '; cout << '\n';
    }
    return res;
}

int ans(int dep, const int (&arr)[32][32], int flag) {
    /*
    static const int tb1[] = { 1<<20, 1<<22|2, 1<<24|8|1, 1<<26|32|4|2, 1<<28|128|16|8|0, 1<<30|512|64|32|0|2 };
    static const int tb2[] = { 1<<20, 1<<22 };
    for (auto o : tb1) if (o == flag) {
        cout << dep << '\n';
        for (int y = 1; y <= n; ++y) {
            for (int x = 1; x <= n; ++x) cout << arr[y][x] << ' ';
            cout << '\n';
        }
        cout << '\n';
        break;
    }*/

    if (dep <= 0) return 0;

    int d[32][32];
    int res = 0;

    // left
    for (int i = 1; i <= n; ++i) v[i].clear();
    for (int y = 1; y <= n; ++y) for (int x = 1; x <= n; ++x)
        if (arr[y][x]) v[y].push_back(arr[y][x]);
    res = max(res, process());
    for (int y = 1; y <= n; ++y) for (int x = 1; x <= n; ++x)
        d[y][x] = x <= v[y].size() ? v[y][x-1] : 0;
    res = max(res, ans(dep-1, d, flag << 2));

    // right
    for (int i = 1; i <= n; ++i) v[i].clear();
    for (int y = 1; y <= n; ++y) for (int x = n; x >= 1; --x)
        if (arr[y][x]) v[y].push_back(arr[y][x]);
    res = max(res, process());
    for (int y = 1; y <= n; ++y) for (int x = n; x >= 1; --x)
        d[y][x] = n-x < v[y].size() ? v[y][n-x] : 0;
    res = max(res, ans(dep-1, d, flag << 2 | 1));

    // up
    for (int i = 1; i <= n; ++i) v[i].clear();
    for (int x = 1; x <= n; ++x) for (int y = 1; y <= n; ++y)
        if (arr[y][x]) v[x].push_back(arr[y][x]);
    res = max(res, process());
    for (int x = 1; x <= n; ++x) for (int y = 1; y <= n; ++y)
        d[y][x] = y <= v[x].size() ? v[x][y-1] : 0;
    res = max(res, ans(dep-1, d, flag << 2 | 2));
    
    // down
    for (int i = 1; i <= n; ++i) v[i].clear();
    for (int x = 1; x <= n; ++x) for (int y = n; y >= 1; --y)
        if (arr[y][x]) v[x].push_back(arr[y][x]);
    res = max(res, process());
    for (int x = 1; x <= n; ++x) for (int y = n; y >= 1; --y)
        d[y][x] = n-y < v[x].size() ? v[x][n-y] : 0;
    res = max(res, ans(dep-1, d, flag << 2 | 3));

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int d[32][32];
    cin >> n;
    int res = 0;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            cin >> d[y][x];
            res = max(res, d[y][x]);
        }
    }
    cout << max(res, ans(5, d, 1<<20));
}