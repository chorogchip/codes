#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

typedef long long int ll;
ll M, S, N, X;
constexpr ll Mod = 1000000007LL;

int main() { FAST
    cin >> M;
    fore (i, M) {
        cin >> N >> X;
        ll r = 1LL;
        for (ll j = Mod - 2; j; j >>= 1) {
            if (j & 1) r *= N, r %= Mod;
            N *= N; N %= Mod;
        }
        X *= r, X %= Mod;
        S += X, S %= Mod;
    }
    cout << S << endl;
}
