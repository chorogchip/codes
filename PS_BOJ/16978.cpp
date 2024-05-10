#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, d[101010];

struct {
private:
    ll t[101010];
public:
    void add(int i, int x) {
        while (i <= n) t[i] += x, i += i&-i;
    }
    ll sum(int i) {
        ll s = 0;
        while (i) s += t[i], i -= i&-i;
        return s;
    }
    void change(int i, int v) {
        int gap = v - d[i];
        add(i, gap);
        d[i] = v;
    };
    ll sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
} fenwick;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        fenwick.add(i, d[i]);
    }
    int m; cin >> m;
    int quarry1 = 0, quarry2 = 2;
    vector<tuple<int,int,int,int>> qs;
    qs.reserve(m);
    for (int mm = 0; mm < m; ++mm) {
        int a; cin >> a;
        if (a == 1) {
            int i, v; cin >> i >> v;
            qs.push_back({++quarry1, 1, i, v});
        } else {
            int k, i, j; cin >> k >> i >> j;
            qs.push_back({k, quarry2++, i, j});
        }
    }
    sort(qs.begin(), qs.end());
    vector<ll> res(quarry2-2);
    for (auto& [id, a, b, c] : qs) {
        if (a == 1) fenwick.change(b, c);
        else res[a-2] = fenwick.sum(b, c);
    }
    for (auto o : res) cout << o << '\n';
}