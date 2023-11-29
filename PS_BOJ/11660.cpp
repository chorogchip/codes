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

int N, M, D[1025][1025], X1, Y1, X2, Y2;

int main() { FAST
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) cin >> D[i][j];
    for (int j = 2; j <= N; ++j) D[1][j] += D[1][j-1];
    for (int i = 2; i <= N; ++i) {
        int K = D[i][1];
        D[i][1] += D[i-1][1];
        for (int j = 2; j <= N; ++j) 
            D[i][j] = (K += D[i][j]) + D[i-1][j];
    }
    fore (i, M) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        cout << D[X2][Y2] - D[X2][Y1-1] - D[X1-1][Y2] + D[X1-1][Y1-1] << endl;
    }
}
