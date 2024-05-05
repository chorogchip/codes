#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool sieve[10'000'000];
bool is_pal(int i) {
    vector<int> v;
    do v.push_back(i%10); while (i/=10);
    int sz = v.size();
    for (int i = 0; i < sz/2; ++i)
        if (v[i] != v[sz-1-i]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; int nn = (n + 500'000) * 3;
    sieve[1] = 1;
    for (int i = 4; i < nn; i += 2) sieve[i] = 1;
    for (ll i = 3; i * i <= nn; i += 2) if (!sieve[i])
        for (ll j = i * i; j <= nn; j += i + i) sieve[j] = 1;
    for (int i = n;; ++i) if (!sieve[i] && is_pal(i)) {
        cout << i; exit(0);
    }
}