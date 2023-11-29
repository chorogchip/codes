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

int N, R, SQ[225], lo, md, hi;

int main() { FAST
    cin >> N;
    for (int i = 0; i != 225; ++i) SQ[i] = i * i;
    lo = 0, hi = 225-1;
    while (lo < hi) {
        md = lo + hi >> 1;
        if (N > SQ[md]) lo = md + 1;
        else hi = md;
    } R = lo + 1;
    if (SQ[lo] == N) { cout << 1 << endl; return 0; }
    for (int i = 1; SQ[i] < N; ++i) {
        hi = R;
        ST:
        md = SQ[i] + SQ[--hi];
        if (md == N) { cout << 2 << endl; return 0; }
        else if (md > N)
            { if (i < hi) goto ST; }
    }
    for (int i = 1; SQ[i] < N; ++i)
        for (int j = i; SQ[j] < N; ++j)
            for (int k = j; SQ[k] < N; ++k)
                if ((lo = SQ[i] + SQ[j] + SQ[k]) == N)
                    { cout << 3 << endl; return 0; }
                else if (lo > N) break;
    cout << 4 << endl;
}
