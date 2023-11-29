#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
constexpr int INF = 1000*1000*1000;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int N, K, KK, T[0x10000], X, D[251010];
ll S;

inline void add1(int i) {
    while (i <= 0xffff) T[i] += 1, i += i&-i;
}
inline void sub1(int i) {
    while (i <= 0xffff) T[i] -= 1, i += i&-i;
}
inline int getS(int i) {
    int s = 0;
    while (i) s += T[i], i -= i&-i;
    return s;
}
inline int getM(int prev) {
    int lo = 0, md = prev, hi = 0xffff;
    while (lo < hi) {
        if (getS(md) < KK) lo = md + 1;
        else hi = md;
        md = lo + hi >> 1;
    }
    return lo;
}

int main() { FAST
    cin >> N >> K;
    KK = K + 1 >> 1;
    int k = 0, kk = 0, prev = 10;
    fore (i, K) {
        cin >> D[k];
        add1(D[k]);
        ++k;
    }
    prev = getM(prev);
    S += prev;
    for (int i = K; i != N; ++i) {
        sub1(D[kk]);
        ++kk;
        cin >> D[k];
        add1(D[k]);
        ++k;
        prev = getM(prev);
        S += prev;
    }
    cout << S;
}
