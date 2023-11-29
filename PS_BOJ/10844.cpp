#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, D[101][10], R;

main() { FAST
    cin >> N;
    for (int j = 1; j <= 9; ++j)
        D[1][j] = 1;
    for (int i = 2; i <= N; ++i) {
        D[i][0] = D[i-1][1];
        for (int j = 1; j < 9; ++j)
            D[i][j] = (D[i-1][j-1] + D[i-1][j+1]) % 1000000000;
        D[i][9] = D[i-1][8];
    }
    for (int j = 0; j <= 9; ++j)
        R = (R + D[N][j]) % 1000000000;
    cout << R;
}