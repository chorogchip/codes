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
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

ll A, D, Q, B, L, R;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
ll getA(ll i) {
    return A + D * (i - 1);
}

int main() { FAST
    cin >> A >> D >> Q;
    fore (i, Q) {
        cin >> B >> L >> R;
        if (B == 1)
            cout << ((R - L + 1LL) * (getA(L) + getA(R)) >> 1LL) << endl;
        else if (L == R) cout << getA(L) << endl;
        else cout << gcd(D, getA(L)) << endl;
    }
}
