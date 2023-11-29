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

int N, NN, A[4010], B[4010], C[4010], D[4010], E[16010101], F[16010101];
ll R;

int main() { FAST
    cin >> N; NN = N * N;
    fore (i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];
    fore (i, N) fore (j, N) E[i*N+j] = A[i] + B[j], F[i*N+j] = C[i] + D[j];
    sort(E, E + NN);
    sort(F, F + NN);
    fore (i, NN)
        R += upper_bound(F, F + NN, -E[i]) - lower_bound(F, F + NN, -E[i]);
    cout << R;
}
