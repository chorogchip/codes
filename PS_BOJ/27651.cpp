#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll srr[1010101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; ll r = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        ll x; cin >> x; sum += x;
        srr[i] = srr[i-1] + x;
    }
    for (int sec_beg = n; sec_beg >= 3; sec_beg--) {
        ll rem = srr[sec_beg - 1];
        ll tail = sum - rem;
        int lo = 1, hi = sec_beg - 1;
        if (rem <= tail) break;
        while (lo < hi) {
            int md = lo + hi >> 1;
            ll head = srr[md];
            if (head < tail && rem - head > tail) lo = md + 1;
            else hi = md;
        }
        r += lo - 1;
    }
    cout << r;
}