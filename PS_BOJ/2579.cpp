#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, X, D[301][2];

main() { FAST
    cin >> N;
    cin >> D[1][1];
    for (int i = 2; i <= N; ++i) {
        cin >> X;
        D[i][1] = X + max(D[i-2][0],D[i-2][1]);
        D[i][0] = X + D[i-1][1];
    }
    cout << max(D[N][0],D[N][1]);
}