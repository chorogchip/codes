#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

ll A, B, D[61];

ll asd(ll x) {
    ll S = x & 1LL;
    for (ll i = 1LL<<60LL, k = 59LL; k >= 0; i >>= 1LL, --k) if (x & i)
        S += D[k] + (x - i + 1), x -= i;
    return S;
}

int main() { FAST
    D[0] = 1LL;
    for (ll i = 1LL; i != 60LL; ++i)
        D[i] = (D[i-1] << 1LL) + (1LL << i);
    cin >> A >> B;
    cout << asd(B) - asd(A - 1);
}