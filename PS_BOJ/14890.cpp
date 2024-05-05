#include<bits/stdc++.h>
using namespace std;

int arr[128][128];

int n, l;

vector<pair<int,int>> cc(const vector<int>& v) {
    vector<pair<int,int>> ret;
    for (auto o : v) {
        if (ret.empty()) ret.push_back({o, 1});
        else if (ret.back().first == o) ret.back().second++;
        else ret.push_back({o, 1});
    }
    return ret;
}

bool possible(vector<int>& v) {
    auto vv = cc(v);
    int sz = vv.size();
    for (int i = 1; i < sz; ++i)
        if (abs(vv[i].first - vv[i-1].first) > 1) return false;
    for (int i = 1; i < sz; ++i) {
        if (vv[i].first < vv[i-1].first) {
            vv[i].second -= l;
            if (vv[i].second < 0) return false;
        } else {
            vv[i-1].second -= l;
            if (vv[i-1].second < 0) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> l;
    for (int yy = 1; yy <= n; ++yy)
    for (int xx = 1; xx <= n; ++xx) cin >> arr[yy][xx];
    int cnt = 0;
    for (int yy = 1; yy <= n; ++yy) {
        vector<int> v(n);
        for (int xx = 1; xx <= n; ++xx) v[xx-1] = arr[yy][xx];
        cnt += possible(v);
        for (int xx = 1; xx <= n; ++xx) v[xx-1] = arr[xx][yy];
        cnt += possible(v);
    }
    cout << cnt;
}