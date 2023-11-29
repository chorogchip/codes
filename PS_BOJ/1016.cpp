#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sieve(ll n) {

}

ll cnt(ll n) {

}

ll sq(ll n) {
    ll lo = 1, md, hi = n;
    while(lo < hi) {
        ll md = lo + hi >> 1;
        if (md * md < n) md = lo + 1;
        else hi = md;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, M; cin >> m >> M;
    ll sqr = sq(M);
    sieve(sqr);
    cout << M - m + 1 - cnt(M) + cnt(m-1);
}