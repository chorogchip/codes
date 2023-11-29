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

int L, N, A, B, D[51];

int main() { FAST
    cin >> L;
    fore (i, L) cin >> D[i];
    cin >> N;
    sort(D, D + L);
    int lo, md, hi;
    lo = 0, hi = L - 1;
    while (lo < hi) {
        md = lo + hi >> 1;
        if (N > D[md]) lo = md + 1;
        else hi = md;
    }
    if (hi == 0) {
        B = D[0];
        A = 0;
    } else if (N == D[L-1]) {
        B = N + 1;
        A = N - 1;
    } else {
        B = D[lo];
        A = D[max(0, lo-1)];
    }
    cout << max(0, (N - A) * (B - N) - 1) << endl;
}
