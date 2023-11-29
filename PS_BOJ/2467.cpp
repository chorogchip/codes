#include<iostream>
#include<algorithm>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, D[101010], M1 = 0, M2 = 2010101010;

int main() { FAST
    cin >> N;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    for (int i = 0; i < N - 1; ++i) {
        int lo = i + 1, md, hi = N - 1;
        while (lo < hi) {
            md = lo + hi >> 1;
            if (0 > D[i] + D[md]) lo = md + 1;
            else hi = md;
        }
        if (abs(M1 + M2) > abs(D[i] + D[lo])) {
            M1 = D[i];
            M2 = D[lo];
        }
        if (lo - 1 != i && abs(M1 + M2) > abs(D[i] + D[lo - 1])) {
            M1 = D[i];
            M2 = D[lo - 1];
        }
    }
    cout << M1 << ' ' << M2;
}
