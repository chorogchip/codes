#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while(n--) {
        ll x; cin >> x; pq.push(x);
    }
    ll s = 0;
    while (pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        s += a+b;
        pq.push(a+b);
    }
    cout << s;
}