#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n;
    vector<pair<ll,ll>> a(n);
    for (auto& o : a) cin >> o.first >> o.second;
    cin >> m;
    deque<pair<ll,ll>> b(m);
    for (auto& o : b) cin >> o.first >> o.second;
    int l, r; cin >> l >> r;
    queue<pair<ll,ll>> qu;
    ll res = 0, sum = 0;
    for (auto o : a) {
        while (!b.empty() && b.front().first <= o.first + r)
            sum += b.front().second, qu.push(b.front()), b.pop_front();
        while (!qu.empty() && qu.front().first < o.first + l)
            sum -= qu.front().second, qu.pop();
        res += sum * o.second;
    }
    cout << res;
}