#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int d[64];

int main() {
    int n, s; cin >> n >> s;
    int nn = n/2;
    for (int i = 0; i < n; ++i) cin >> d[i];
    if (n == 1) { cout << (d[0] == s); exit(0); }
    vector<int> a, b;
    a.reserve(1<<nn);
    b.reserve(1<<n-nn);
    for (int i = 0; i < nn; ++i) {
        int sz = a.size();
        for (int j = 0; j < sz; ++j) a.push_back(a[j] + d[i]);
        a.push_back(d[i]);
    }
    for (int i = nn; i < n; ++i) {
        int sz = b.size();
        for (int j = 0; j < sz; ++j) b.push_back(b[j] + d[i]);
        b.push_back(d[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<int,int>> aa, bb;
    aa.reserve(a.size());
    bb.reserve(b.size());
    aa.push_back({a[0], 1});
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == aa.back().first) aa.back().second++;
        else aa.push_back({a[i], 1});
    }
    bb.push_back({b[0], 1});
    for (int i = 1; i < b.size(); ++i) {
        if (b[i] == bb.back().first) bb.back().second++;
        else bb.push_back({b[i], 1});
    }
    ll res = 0;
    for (auto o : aa) {
        auto[n, c] = o;
        auto it = lower_bound(bb.begin(), bb.end(), make_pair(s-n, 0));
        if (it != bb.end() && it->first == s - n)
            res += (ll)c * (ll)it->second;
    }
    auto it = lower_bound(aa.begin(), aa.end(), make_pair(s, 0));
    if (it != aa.end() && it->first == s) res += it->second;
    it = lower_bound(bb.begin(), bb.end(), make_pair(s, 0));
    if (it != bb.end() && it->first == s) res += it->second;
    cout << res;
}