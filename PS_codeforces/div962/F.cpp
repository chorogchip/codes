#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll A[201010], B[201010], R[201010];

constexpr inline ll calc(ll a, ll c, ll b) {
    ll ret = a * c;
    ret -= b * ((c-1) * c >> 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        for (int i = 1; i <= n; ++i) cin >> B[i];
        ll lo = 0, hi = std::numeric_limits<ll>::max()/2;
        ll score, ops;
        while (lo < hi) {
            const ll md = lo + hi >> 1;
            score = ops = 0;
            for (int i = 1; i <= n; ++i) {
                ll gap = A[i] - md;
                if (gap <= 0) {
                    R[i] = A[i];
                    continue;
                }
                ll cnt = gap / B[i];
                ll rem = gap % B[i];
                if (rem) ++cnt;
                R[i] = A[i] - cnt * B[i];
                score += calc(A[i], cnt, B[i]);
                ops += cnt;
                if (R[i] < 0) {
                    R[i] = 0;
                }
            }
            if (ops > k) lo = md + 1;
            else hi = md;
        }
        {
            const ll md = lo + hi >> 1;
            score = ops = 0;
            for (int i = 1; i <= n; ++i) {
                ll gap = A[i] - md;
                if (gap <= 0) {
                    R[i] = A[i];
                    continue;
                }
                ll cnt = gap / B[i];
                ll rem = gap % B[i];
                if (rem) ++cnt;
                R[i] = A[i] - cnt * B[i];
                score += calc(A[i], cnt, B[i]);
                ops += cnt;
                if (R[i] < 0) {
                    R[i] = 0;
                }
            }
        }
        ll rem_ops = k - ops;
        sort(R+1, R+1+n);
        for (int i = n; i >= max(1LL, n - rem_ops + 1LL); --i) score += R[i];
        cout << score << '\n';
    }   
}