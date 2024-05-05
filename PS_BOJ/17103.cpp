#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1'000'000;
bool sieve[INF];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> v;
    for (int i = 4; i < INF; i += 2) sieve[i] = 1; v.push_back(2);
    for (ll i = 3; i < INF; i += 2) if (!sieve[i]) {
        v.push_back(i);
        for (ll j = i * i; j < INF; j += i + i) sieve[j] = 1;
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int cnt = 0;
        for (auto it1 = v.begin(), it2 = v.end()-1; it1 <= it2;) {
            int s = *it1 + *it2;
            if (s < n) ++it1;
            else if (s > n) --it2;
            else { ++cnt; ++it1; --it2; }
        }
        cout << cnt << '\n';
    }
}