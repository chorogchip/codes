#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[101010], s[101010];
priority_queue<int> pq;
priority_queue<pair<ll,ll>> ppq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; ll k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<pair<ll,ll>> lr(m);
    for (int i = 0; i < m; ++i) cin >> lr[i].first >> lr[i].second;
    sort(lr.begin(), lr.end());
    int it1 = 0; ll sum = 0;
    for(int i = 1; i <= n; ++i) {
        while (it1 < lr.size() && lr[it1].first == i) {
            ++sum;
            pq.push(-lr[it1].second);
            ++it1;
        }
        s[i] = sum;
        ppq.push({sum, i});
        while (!pq.empty() && -pq.top() == i) {
            --sum;
            pq.pop();
        }
    }
    ll kk = k;
    while(kk > 0 && !ppq.empty()) {
        auto o = ppq.top(); ppq.pop();
        if ((ll)a[o.second] <= kk) {
            a[o.second] = 0;
            kk -= a[o.second];
        } else {
            a[o.second] -= kk;
            kk = 0;
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) res += (ll)a[i] * (ll)s[i];
    cout << res;
}