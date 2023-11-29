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

typedef unsigned long long ull;
ull M, N, A[101010], S;
int main() { FAST
    cin >> M >> N;
    fore (i, N) cin >> A[i];
    ull lo = 0, md, hi = INF << 1;
    while (lo < hi) {
        ull sum = 0;
        md = lo + hi >> 1;
        fore (i, N) if (A[i] > md) sum += A[i] - md;
        if (sum > M) lo = md + 1;
        else hi = md;
    }
    ull sum = 0;
    fore (i, N) if (A[i] > lo) sum += A[i] - lo, A[i] = lo;
    ull rem = M - sum;
    sort(A, A + N);
    for (int i = N - 1; i >= 0 && rem; --i) {
        --A[i];
        --rem;
    }
    fore (i, N) S += A[i] * A[i];
    cout << S;
}
