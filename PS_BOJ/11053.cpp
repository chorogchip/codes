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

int N, X, K, A[1010], D[1010], DD[1010], H, M;

int main() { FAST
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> X;
        if (X > DD[H]) DD[++H] = X, D[i] = ++K, M = max(M, K);
        else {
            int lo = 0, md, hi = H;
            while (lo < hi) {
                md = lo + hi >> 1;
                if (X > DD[md]) lo = md + 1;
                else hi = md;
            }
            if (lo > 0) DD[lo] = X, D[i] = lo;
        }
    }
    cout << M << endl;
}
