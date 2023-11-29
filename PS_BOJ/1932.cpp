#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, i, D[501][501], R;

main() { FAST
    cin >> N >> D[1][1];
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= i; ++j)
            cin >> D[i][j];
        D[i][1] += D[i-1][1];
        D[i][i] += D[i-1][i-1];
        for (int j = 2; j < i; ++j)
            D[i][j] += max(D[i-1][j-1],D[i-1][j]);
    }
    for (int i = 1; i <= N; ++i) R = max(R, D[N][i]);
    cout << R;
}