#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct {
private:
    ll given;
    vector<pair<ll,int>> v;
public:
    void init() { given = 1; v.push_back({0, 0}); }
    void push(int x, ll cnt) {
        if (x == v.back().second) v.back().first += cnt;
        else v.push_back({v.back().first + cnt, x});
    }
    pair<ll,ll> pop(ll cnt) {
        const ll index = given;
        const ll pop_size = min(cnt, v.back().first+1 - given);
        given += pop_size;
        return {index, pop_size};
    }
    int quarry(ll ind) {
        return lower_bound(v.begin(), v.end(), make_pair(ind, 0))->second;
    }
} trashes;

struct {
private:
    map<int,pair<ll,ll>> mp;
public:
    int get(int cnt) {
        auto o = trashes.pop(cnt);
        int id = mp.size()+1;
        mp.insert({id, o});
        return id;
    }
    int quarry(int id, ll offset) {
        auto o = mp[id];
        if (offset >= o.second) return 0;
        return trashes.quarry(o.first + offset);
    }
} trash_handler;

struct {
private:
    int nn;
    pair<ll,ll> t[2001010];
    pair<ll,ll> quarry_(int i, int s, int e, int ind) {
        if (t[i] != make_pair(0LL, 0LL))
            return {t[i].first, t[i].second + ind - s};
        int md = s + e >> 1;
        if (ind <= md) return quarry_(i<<1, s, md, ind);
        return quarry_((i<<1)+1, md+1, e, ind);
    }
    int update_(int i, int s, int e, int l, int r, int num, ll offset) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) {
            t[i] = {num, offset};
            return e - s + 1;
        }
        ll sz = e - s >> 1;
        if (t[i] != make_pair(0LL, 0LL)) {
            t[i<<1] = t[i];
            t[(i<<1)+1] = t[i];
            t[(i<<1)+1].second += sz + 1;
            t[i] = {0, 0};
        }
        ll res = update_(i<<1, s, s+sz, l, r, num, offset);
        return res + update_((i<<1)+1, s+sz+1, e, l, r, num, offset+res);
    }
public:
    void init(int cnt) {
        nn = 1<<32-__builtin_clz(cnt-1);
    }
    int quarry(int ind) {
        auto o = quarry_(1, 1, nn, ind);
        return trash_handler.quarry(o.first, o.second);
    }
    void update(int l, int r) {
        const int num = trash_handler.get(r - l + 1);
        update_(1, 1, nn, l, r, num, 0);
    }
} burner;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k, q; cin >> n >> m >> k >> q;
    trashes.init();
    burner.init(m);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        trashes.push(x, 1);
    }
    burner.update(1, m);
    while(q--) {
        int o; cin >> o;
        if (o == 1) {
            int l, r; cin >> l >> r;
            burner.update(l, r);
        } else if (o == 2) {
            int i; cin >> i;
            cout << burner.quarry(i) << ' ';
        } else if (o == 3) {
            int a, b; cin >> a >> b;
            trashes.push(a, b);
        } else {
            ll t; cin >> t;
            trashes.pop(t);
        }
    }
    cout << '\n';
    for (int i = 1; i <= m; ++i) cout << burner.quarry(i) << ' ';
}