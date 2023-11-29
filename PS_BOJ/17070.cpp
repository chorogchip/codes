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

int N, D[20][20], S;

void DFS(int y, int x, int dir) {
    if (y == N && x == N) {
        ++S;
        return;
    }
    if (dir == 0) {
        if (!D[y][x+1]) DFS(y, x+1, 0);
        if (!D[y+1][x+1]&&!D[y][x+1]&&!D[y+1][x]) DFS(y+1, x+1, 1);
    } else if (dir == 1) {
        if (!D[y][x+1]) DFS(y, x+1, 0);
        if (!D[y+1][x+1]&&!D[y][x+1]&&!D[y+1][x]) DFS(y+1, x+1, 1);
        if (!D[y+1][x]) DFS(y+1, x, 2);
    } else {
        if (!D[y+1][x+1]&&!D[y][x+1]&&!D[y+1][x]) DFS(y+1, x+1, 1);
        if (!D[y+1][x]) DFS(y+1, x, 2);
    }
}

int main() { FAST
    cin >> N;
    for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) cin >> D[i][j];
    for (int i = 0; i <= N + 1; ++i) D[0][i] = D[i][0] = D[N+1][i] = D[i][N+1] = 1;
    DFS(1, 2, 0);
    cout << S << endl;
}
