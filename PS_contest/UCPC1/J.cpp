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

typedef long long ll;
int N;
ll A[501010], B[501010];
constexpr ll BBB = 1000LL*1000LL*1000LL;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
bool isJegob(ll a) {
    ll lo = 1, md, hi = max(3LL, min(a >> 1, BBB));
    while (lo < hi) {
        md = lo + hi >> 1LL;
        if (a > md * md) lo = md + 1LL;
        else hi = md;
    }
    return lo * lo == a;
}
int main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B, B + N);
    for (int i = 0; i != N; ++i) {
        ll gg = gcd(A[i], B[i]);
        A[i] /= gg; B[i] /= gg;
        if (!isJegob(A[i]) || !isJegob(B[i])) goto NO;
    }
    YES: cout << "YES"; return 0;
    NO: cout << "NO"; return 0;
}
