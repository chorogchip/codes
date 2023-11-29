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

int N, K, A[1010], D[1010], DL[1010], DR[1010], LL[1010], LR[1010], M;

int main() { FAST
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        if (A[i] > D[K]) D[++K] = DL[i] = A[i], LL[i] = K;
        else {
            int lo = 0, md, hi = K;
            while (lo < hi) {
                md = lo + hi >> 1;
                if (A[i] > D[md]) lo = md + 1;
                else hi = md;
            }
            if (lo) D[lo] = A[i];
        }
    }
    memset(D, 0, sizeof(D)); K = 0;
    for (int i = N; i; --i) {
        if (A[i] > D[K]) D[++K] = DR[i] = A[i], LR[i] = K;
        else {
            int lo = 0, md, hi = K;
            while (lo < hi) {
                md = lo + hi >> 1;
                if (A[i] > D[md]) lo = md + 1;
                else hi = md;
            }
            if (lo) D[lo] = A[i];
            if (lo == K) DR[i] = A[i];
            else DR[i] = DR[i+1];
            LR[i] = LR[i+1];
        }
    }

    for (int i = 1; i <= N; ++i) if (DL[i])
        for (int j = i + 1; j <= N + 1; ++j) if (DL[i] > DR[j])
            M = max(M, LL[i] + LR[j]);
    cout << M << endl;
}
