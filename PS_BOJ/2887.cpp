#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct { int i, x, y, z; } d[101010];
int p[101010];

int par(int i) {
    if (i == p[i]) return i;
    else return p[i] = par(p[i]);
}

vector<tuple<int,int,int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        d[i].i = p[i] = i;
        cin >> d[i].x >> d[i].y >> d[i].z;
    }
    sort(d, d + n, [] (auto& a, auto& b) -> bool { return a.x < b.x; });
    for (int i = 1; i < n; ++i) v.push_back({abs(d[i].x - d[i-1].x), d[i].i, d[i-1].i});
    sort(d, d + n, [] (auto& a, auto& b) -> bool { return a.y < b.y; });
    for (int i = 1; i < n; ++i) v.push_back({abs(d[i].y - d[i-1].y), d[i].i, d[i-1].i});
    sort(d, d + n, [] (auto& a, auto& b) -> bool { return a.z < b.z; });
    for (int i = 1; i < n; ++i) v.push_back({abs(d[i].z - d[i-1].z), d[i].i, d[i-1].i});
    sort(v.begin(), v.end());
    ll res = 0;
    for (auto [c, a, b] : v) {
        int aa = par(a);
        int bb = par(b);
        if (aa != bb) {
            res += c;
            p[aa] = bb;
        }
    }
    cout << res;
}