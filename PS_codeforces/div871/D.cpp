#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

ll get_2(ll a) {
    ll res = 0;
    while (a % 2 == 0) {
        ++res;
        a >>= 1;
    }
    return res;
}

ll get_3(ll a) {
    ll res = 0;
    while (a % 3 == 0) {
        ++res;
        a /= 3;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        ll n, m; cin >> n >> m;
        {
            if (m > n) goto NO;
            ll n2 = get_2(n);
            ll m2 = get_2(m);
            if (n2 > m2) goto NO;
            ll gap2 = m2 - n2;
            m >>= gap2;
            for (int i = 0; i < gap2; ++i) m *= 3;
            if (n % m != 0) goto NO;
            ll rem = n / m;
            while (rem != 1) {
                if (rem % 3 != 0) goto NO;
                rem /= 3;
            }
            goto YES;
        }
        YES: cout << "YES\n"; continue;
        NO: cout << "NO\n"; continue;
    }
}
