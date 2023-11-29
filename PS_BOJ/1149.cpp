#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, i, X1, X2, X3, R[1000], G[1000], B[1000];

main() { FAST
    cin >> N >> R[0] >> G[0] >> B[0];
    for (i = 1; i != N; ++i) {
        cin >> X1 >> X2 >> X3;
        R[i] = X1 + min(G[i-1], B[i-1]);
        G[i] = X2 + min(B[i-1], R[i-1]);
        B[i] = X3 + min(R[i-1], G[i-1]);
    }
    cout << min(R[N-1],min(G[N-1],B[N-1]));
}