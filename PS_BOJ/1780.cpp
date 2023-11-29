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

int A, B, C, N, D[2188][2188];

void asdf(int nn, int x, int y) {
    int cc = D[x][y];
    fore (i, nn) fore (j, nn) if (D[x+i][y+j] != cc) goto E;
    switch (cc) {
        case -1: ++A; break;
        case 0: ++B; break;
        case 1: ++C; break;
    } return;
    E: nn /= 3;
    int nnn = nn << 1;
    asdf(nn, x, y);
    asdf(nn, x, y + nn);
    asdf(nn, x, y + nnn);
    asdf(nn, x + nn, y);
    asdf(nn, x + nn, y + nn);
    asdf(nn, x + nn, y + nnn);
    asdf(nn, x + nnn, y);
    asdf(nn, x + nnn, y + nn);
    asdf(nn, x + nnn, y + nnn);
}

int main() { FAST
    cin >> N;
    fore (i, N) fore (j, N) cin >> D[i][j];
    asdf(N, 0, 0);
    cout << A << endl << B << endl << C << endl;
}
