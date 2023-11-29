#define TEMM
#ifdef TEMM
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
struct Pos {int x,y;};
typedef long long ll;
typedef vector<int> vi;
typedef vector<Pos> vp;
constexpr int INF = 1000*1000*1000;
#endif

int N;
ll A[501010], B[501010];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
bool isJ(ll n) {
    ll lo = 1, md, hi = 1000000000;
    while (lo < hi) {
        md = lo + hi >> 1LL;
        if (n > md * md) lo = md + 1LL;
        else hi = md;
    }
    return n == lo * lo;
}
int main() { FAST
    cin >> N;
    fore (i, N) cin >> A[i], B[i] = A[i];
    sort(B, B + N);
    fore (i, N) {
        ll g = gcd(A[i], B[i]);
        if (!isJ(A[i]/g) || !isJ(B[i]/g)) goto NO;
    }
    YES: cout << "YES\n"; return 0;
    NO: cout << "NO\n"; return 0;
}
