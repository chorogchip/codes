#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> col(n), row(m);
    vector<pair<ll,ll>> pol(k);
    for (auto& o : col) cin >> o, o += 500'000LL;
    for (auto& o : row) cin >> o, o += 500'000LL;
    for (auto& [ox, oy] : pol) cin >> ox >> oy, ox += 500'000LL, oy += 500'000LL;
    row.push_back(1);
    row.push_back(100'000LL);
    row.push_back(1000'000LL);
    row.push_back(1200'000LL);
    col.push_back(1);
    col.push_back(100'000LL);
    col.push_back(1000'000LL);
    col.push_back(1200'000LL);
    sort(col.begin(), col.end());
    sort(row.begin(), row.end());
    ll res = 0, sum, cnt;
    vector<pair<ll,ll>> vec; vector<ll>::iterator vec_it;
    sort(pol.begin(), pol.end());
    sum = 0, cnt = 0; vec.clear(); vec_it = col.begin();
    for (auto [ox, oy] : pol) {
        res += ox * cnt - sum;
        auto it = lower_bound(col.begin(), col.end(), ox);
        if (it != vec_it) {
            vec.clear();
            vec.push_back({1LL, 0LL});
            vec.push_back({ox, ox});
            vec_it = it;
        } else {
            ll nxt = *it;
            ll cur = *(it-1);
            ll opp = nxt - (ox - cur);
            auto it_mid = lower_bound(vec.begin(), vec.end(), make_pair(opp, 0LL));
            ll left_cnt = it_mid - vec.begin() - 1LL;
            ll right_cnt = vec.end() - it_mid;
            res += (it_mid - 1)->second * 2LL;
            res -= cur * 2LL * left_cnt;
            res += 2LL * right_cnt * (nxt - ox);
            vec.push_back({ox, ox + vec.back().second});
        }
        sum += ox;
        ++cnt;
    }
    for (auto& [ox, oy] : pol) swap(ox, oy);
    sort(pol.begin(), pol.end());
    sum = 0, cnt = 0; vec.clear(); vec_it = row.begin();
    for (auto [oy, ox] : pol) {
        res += oy * cnt - sum;
        auto it = lower_bound(row.begin(), row.end(), oy);
        if (it != vec_it) {
            vec.clear();
            vec.push_back({1LL, 0LL});
            vec.push_back({oy, oy});
            vec_it = it;
        } else {
            ll nxt = *it;
            ll cur = *(it-1);
            ll opp = nxt - (oy - cur);
            auto it_mid = lower_bound(vec.begin(), vec.end(), make_pair(opp, 0LL));
            ll left_cnt = it_mid - vec.begin() - 1LL;
            ll right_cnt = vec.end() - it_mid;
            res += (it_mid - 1)->second * 2LL;
            res -= cur * 2LL * left_cnt;
            res += 2LL * right_cnt * (nxt - oy);
            vec.push_back({oy, oy + vec.back().second});
        }
        sum += oy;
        ++cnt;
    }
    cout << res;
}