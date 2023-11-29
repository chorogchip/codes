#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int N, D, S, A[101010];
ll DP[101010];
vector<ll> vec;
struct res {
    ll m, l, r, s;
};
ll gett() {
    memset(DP, 0, sizeof(DP));
    DP[0] = vec[0];
    ll m = DP[0];
    for (int i = 1; i != S; ++i) {
        if (DP[i-1] < 0) DP[i] = vec[i];
        else DP[i] = DP[i-1]+vec[i];
        m = max(m, DP[i]);  
    }
    return m;
}

int dp(int* beg, int* end) {
    int s = end - beg;
    ll m = -INF * (1LL<<30);
    for (int i = 0; i < D && i < s; ++i) DP[i] = beg[i];
    for (int i = D; i < s; ++i) {
        DP[i] = -INF * (1LL<<30);
        for (int j = 1; j <= D && i - j >= 0; ++j)
            DP[i] = max(DP[i], DP[i-j] + beg[i]);
    }
    for (int i = 1; i <= D && s - i >= 0; ++i) m = max(m, DP[s - i]);
    return m;
}

int gettttt() {
    int m = -INF;
    for (int i = 0; i != N; ++i) m = max(m, A[i]);
    return m;
}

int main() { FAST
    cin >> N >> D;
    fore (i, N) cin >> A[i];
    int i = 0;
    while (i < N && A[i] < 0) ++i;
    while (i < N) {
        ll s = 0;
        while (i < N && A[i] >= 0) s += A[i++];
        vec.push_back(s);
        if (i >= N) break;
        int *beg = A + i;
        while (i < N && A[i] < 0) ++i;
        int *end = A + i;
        ll d = dp(beg, end);
        if (d != -INF * (1LL<<30)) vec.push_back(d);
    }
    if (vec.size() && vec.back() < 0) vec.pop_back();
    S = vec.size();
    if (S == 0) cout << gettttt();
    else cout << gett();
}
