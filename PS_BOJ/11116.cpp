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

int T, M, D[2][201];

void remv(int i, int j) {
    for (int k = 0; k != M; ++k) if (D[i][k] == j) {
        D[i][k] = 0;
        return;
    }
}
int main() { FAST
    cin >> T;
    while (T--) {
        cin >> M;
        fore (i, M) cin >> D[0][i];
        fore (i, M) cin >> D[1][i];
        sort(D[0], D[0] + M);
        sort(D[1], D[1] + M);
        int i = 0, j = 0, ll = 0;
        while (i < M && j < M) {
            if (D[0][i] < D[1][j]) {
                ++ll;
                remv(0, D[0][i]+500);
                remv(1, D[0][i]+1000);
                remv(1, D[0][i]+1500);
                D[0][i] = 0;
                while (++i < M && !D[0][i]);
                while (j < M && !D[1][j++]);--j;
            } else {
                remv(1, D[1][j]+500);
                remv(0, D[1][j]+1000);
                remv(0, D[1][j]+1500);
                D[1][j] = 0;
                while (++j < M && !D[1][j]);
                while (i < M && !D[1][i++]);--i;
            }
        }
        cout << ll << endl;
    }
}
