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

int N, M, D[501][501], R;

int main() { FAST
    cin >> N >> M;
    fore (i, N) fore (j, M) cin >> D[i][j];
    for (int i = 0; i != N-1; ++i) for (int j = 0; j != M-1; ++j)
        R = max(R, D[i][j]+D[i][j+1]+D[i+1][j]+D[i+1][j+1]);
    for (int i = 0; i != N; ++i) for (int j = 0; j != M-3; ++j)
        R = max(R, D[i][j]+D[i][j+1]+D[i][j+2]+D[i][j+3]);
    for (int i = 0; i != N-3; ++i) for (int j = 0; j != M; ++j)
        R = max(R, D[i][j]+D[i+1][j]+D[i+2][j]+D[i+3][j]);
    for (int i = 0; i != N-1; ++i) for (int j = 0; j != M-2; ++j) {
        R = max(R, D[i][j]+D[i+1][j]+D[i][j+1]+D[i][j+2]);
        R = max(R, D[i][j]+D[i+1][j]+D[i+1][j+1]+D[i+1][j+2]);
        R = max(R, D[i][j]+D[i][j+1]+D[i][j+2]+D[i+1][j+2]);
        R = max(R, D[i+1][j]+D[i+1][j+1]+D[i+1][j+2]+D[i][j+2]);
        R = max(R, D[i][j]+D[i][j+1]+D[i+1][j+1]+D[i][j+2]);
        R = max(R, D[i+1][j]+D[i+1][j+1]+D[i][j+1]+D[i+1][j+2]);
        R = max(R, D[i][j]+D[i][j+1]+D[i+1][j+1]+D[i+1][j+2]);
        R = max(R, D[i+1][j]+D[i+1][j+1]+D[i][j+1]+D[i][j+2]);
    }
    for (int i = 0; i != N-2; ++i) for (int j = 0; j != M-1; ++j) {
        R = max(R, D[i][j]+D[i][j+1]+D[i+1][j]+D[i+2][j]);
        R = max(R, D[i][j]+D[i][j+1]+D[i+1][j+1]+D[i+2][j+1]);
        R = max(R, D[i][j]+D[i+1][j]+D[i+2][j]+D[i+2][j+1]);
        R = max(R, D[i][j+1]+D[i+1][j+1]+D[i+2][j+1]+D[i+2][j]);
        R = max(R, D[i][j]+D[i+1][j]+D[i+1][j+1]+D[i+2][j]);
        R = max(R, D[i][j+1]+D[i+1][j]+D[i+1][j+1]+D[i+2][j+1]);
        R = max(R, D[i][j]+D[i+1][j]+D[i+1][j+1]+D[i+2][j+1]);
        R = max(R, D[i][j+1]+D[i+1][j+1]+D[i+1][j]+D[i+2][j]);
    }
    cout << R << endl;
}
