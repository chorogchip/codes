#include<bits/stdc++.h>
using namespace std;

using ll = long long;

std::tuple<ll, ll, ll> gcd(ll a_, ll a, ll b_, ll b, ll c, ll d) {
    ll q = c / d;
    ll r = c % d;
    if (r == 0) return make_tuple(a, b, d);
    return gcd(a, a_ - q * a, b, b_ - q * b, d, r);
}

int main() {
    ll n, m, S; cin >> n >> m >> S;
    if (n == S || m == S) goto YES;
    { auto[a, b, d] = gcd(1, 0, 0, 1, n, m);
    if (S % d != 0) goto NO;
    {
        ll A = S / d;
        ll a_ = a * A;
        ll b_ = b * A;
        ll p = n / d;
        ll q = m / d;
        while (a_ <= 0) {
            a_ += q;
            b_ -= p;
        }
        while (b_ <= 0) {
            b_ += p;
            a_ -= q;
        }
        if (a_ > 0) goto YES;
        else goto NO;


    }}
    YES: cout << "YES"; exit(0);
    NO: cout << "NO"; exit(0);
    
}