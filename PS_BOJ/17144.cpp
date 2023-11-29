#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

int R, C, T, D[152][152], D2[152][152], X, S;

int main() {
    cin >> R >> C >> T;
    for1 (i, R) for1 (j, C) {
        cin >> D[i][j];
        if (D[i][j] == -1) X = i;
    } --X;
    D[X][1] = D[X+1][1] = 0;
    do {
        D2[1][1] = D[1][2]/5 + D[2][1]/5;
        D2[1][C] = D[1][C-1]/5 + D[2][C]/5;
        D2[R][1] = D[R][2]/5 + D[R-1][1]/5;
        D2[R][C] = D[R][C-1]/5 + D[R-1][C]/5;
        for (int i = 2; i != C; ++i)
            D2[1][i] = D[1][i-1]/5 + D[1][i+1]/5 + D[2][i]/5,
            D2[R][i] = D[R][i-1]/5 + D[R][i+1]/5 + D[R-1][i]/5;
        for (int i = 2; i != R; ++i)
            D2[i][C] = D[i-1][C]/5 + D[i+1][C]/5 + D[i][C-1]/5;
        for (int i = 2; i <= X-2; ++i)
            D2[i][1] = D[i-1][1]/5 + D[i+1][1]/5 + D[i][2]/5;
        for (int i = X+3; i < R; ++i)
            D2[i][1] = D[i-1][1]/5 + D[i+1][1]/5 + D[i][2]/5;
        D2[X-1][1] = D[X-2][1]/5 + D[X-1][2]/5;
        D2[X+2][1] = D[X+3][1]/5 + D[X+2][2]/5;
        for (int i = 2; i != R; ++i) for (int j = 2; j != C; ++j)
            if (j != 2 || (i != X && i != X+1))
                D2[i][j] = D[i-1][j]/5 + D[i+1][j]/5 + D[i][j-1]/5 + D[i][j+1]/5;
        D2[X][2] = D[X][3]/5 + D[X-1][2]/5 + D[X+1][2]/5;
        D2[X+1][2] = D[X+1][3]/5 + D[X][2]/5 + D[X+2][2]/5;
        D[1][1] -= D[1][1]/5*2;
        D[1][C] -= D[1][C]/5*2;
        D[R][1] -= D[R][1]/5*2;
        D[R][C] -= D[R][C]/5*2;
        for (int i = 2; i != C; ++i)
            D[1][i] -= D[1][i]/5*3,
            D[R][i] -= D[R][i]/5*3;
        for (int i = 2; i != R; ++i)
            D[i][C] -= D[i][C]/5*3;
        for (int i = 2; i <= X - 2; ++i)
            D[i][1] -= D[i][1]/5*3;
        for (int i = X + 3; i != R; ++i)
            D[i][1] -= D[i][1]/5*3;
        D[X-1][1] -= D[X-1][1]/5*2;
        D[X+2][1] -= D[X+2][1]/5*2;
        for (int i = 2; i != R; ++i) for (int j = 2; j != C; ++j)
            if (j != 2 || (i != X && i != X+1))
                D[i][j] -= D[i][j]/5*4;
        D[X][2] -= D[X][2]/5*3;
        D[X+1][2] -= D[X+1][2]/5*3;
        for1 (i, R) for1 (j, C)
            D[i][j] += D2[i][j];
        for (int i = X; i > 1; --i) D[i][1] = D[i-1][1]; D[X][1] = 0;
        for (int i = X + 1; i < R; ++i) D[i][1] = D[i+1][1]; D[X+1][1] = 0;
        for (int i = 1; i != C; ++i) D[1][i] = D[1][i+1], D[R][i] = D[R][i+1];
        for (int i = 1; i < X; ++i) D[i][C] = D[i+1][C];
        for (int i = R; i > X + 1; --i) D[i][C] = D[i-1][C];
        for (int i = C; i > 1; --i) D[X][i] = D[X][i-1], D[X+1][i] = D[X+1][i-1];
    } while (--T);
    for1 (i, R) for1 (j, C) S += D[i][j];
    cout << S;
}