#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, X, D[10101][2];

main() { FAST
    cin >> N;
    cin >> D[1][1];
    if (N == 1) { cout << D[1][1]; return 0; }
    cin >> D[2][1];
    D[2][0] = D[2][1] + D[1][1];
    if (N == 2) { cout << D[2][0]; return 0; }
    for (int i = 3; i <= N; ++i) {
        cin >> X;
        D[i][1] = X + max(D[i-3][0],max(D[i-2][0],D[i-2][1]));
        D[i][0] = X + D[i-1][1];
    }
    cout << max(D[N][0],max(D[N][1],max(D[N-1][0],D[N-2][0])));
}