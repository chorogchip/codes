#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

unsigned int N, D[101010], lo, hi, md;
unsigned long long M, S;

MAIN { FAST
    cin >> M >> N;
    foreach (i, N) cin >> D[i];
    lo = 0, hi = M;
    while (lo < hi) {
        md = lo + hi >> 1U;
        for (int i = 0; i != N; ++i)
            if (D[i] > md) S += D[i] - md;
        if (S > M) lo = md + 1;
        else hi = md;
    }
    S = 0ULL;
    for (int i = 0; i != N; ++i) if (D[i] > lo) {
        S += D[i] - lo;
        D[i] = lo;
    }
    sort(D, D + N);
    S = M - S;
    while (S) {
        --D[N-1], --S;
        for (int i = N - 2; S && i >= 0 && D[i] == D[i+1]+1; --D[i--], --S);
    }
    for (int i = 0; i != N; ++i) {
        M = (unsigned long long)D[i];
        S += M * M;
    }
    cout << S;
}