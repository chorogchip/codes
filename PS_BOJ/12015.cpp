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

int N, K, X, D[1010101];

int main() { FAST
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> X;
        if (X > D[K]) D[++K] = X;
        else {
            int lo = 0, md, hi = K;
            while (lo < hi) {
                md = lo + hi >> 1;
                if (X > D[md]) lo = md + 1;
                else hi = md;
            }
            if (lo) D[lo] = X; 
        }
    }
    cout << K << endl;
}
