#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

ll arr[1<<20];
ll res = 1;
ll rres = 1;
ll counts[21];
ll facs[1<<20];
constexpr ll M = 998244353LL;
ll fac(ll i) {
    if (i <= 1) return 1;
    if (facs[i]) return facs[i];
    return facs[i] = (((ll)i * fac(i-1)) % M);
}

void no() {
    cout << '0';
    exit(0);    
}

ll solve(ll l, ll r, ll lv) {
    //cout << "sol " << l << ' ' << r << ' ' << lv << '\n';
    if (r == l) return arr[l];
    ll md = l + r >> 1;
    ll li = solve(l, md, lv+1);
    ll ri = solve(md+1, r, lv+1);
    //cout << "solll " << l << ' ' << r << ' ' << lv << ' ' << li << ' ' << ri << '\n';

    ll top = (1 << lv) + 1;
    ll bot = 2 << lv;
    if (li > ri) swap(li, ri);
    if (ri == -1) {
        // both -1
        counts[lv]++;
        rres *= 2;
        rres %= M;
        return -1;
    }
    if (li == -1) {
        // one -1
        if (ri > bot) no();
        else if (ri >= top) return -1;
        else {
            counts[lv]++;
            return ri;
        }
    }
    // no 0
    if (li > bot) no();
    if (ri > bot) no();
    else if (li >= top) return ri;
    else if (ri >= top) return li;
    else no();
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll k; cin >> k;
    ll n = 1 << k;
    for (ll i = 0; i < n; ++i) cin >> arr[i];
    ll rrr = solve(0, n-1, 0);
    if (rrr != 1 && rrr != -1) no();
    for (ll i = 0; i < 21; ++i) {
        res = ((res * fac(counts[i])) % M);
    }
    cout << ((res * rres) % M);
}
