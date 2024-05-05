#include<bits/stdc++.h>
using namespace std;
using ll = long long;

inline bool isp(ll n) {
    for (ll i = 2; i * i <= n; ++i) if (n % i == 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        if (n <= 2) { cout << "2\n"; continue; }
        for (ll nn = n;; ++nn) if (isp(nn)) { cout << nn << '\n'; break; }
    }
}