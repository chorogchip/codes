#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (auto& [b, a] : v) cin >> a;
    for (auto& [b, a] : v) cin >> b;
    sort(v.begin(), v.end());
    ll res = v[0].second;
    priority_queue<ll> pq;
    for (int i = 2; i < n; i += 2) {
        pq.push(v[i-1].second);
        pq.push(v[i].second);
        res += pq.top(); pq.pop();
    }
    cout << res;
}