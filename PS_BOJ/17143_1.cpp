#include<bits/stdc++.h>
using namespace std;

struct sh { int s, d, z; };
sh d1[128][128], d2[128][128];
int R, C, M;

void mv() {
    memset(d2, 0, sizeof(d2));
    for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c)
        if (d1[r][c].z) {
            int nr = r;
            int nc = c;
            int s = d1[r][c].s;
            int d = d1[r][c].d;
            int z = d1[r][c].z;
            switch(d1[r][c].d) {
                case 1:  {// up, -r
                    nr = r - s;
                    if (nr < 1) d ^= 1^2, nr = 2 - nr;
                    if (nr > R) d ^= 1^2, nr = 2*R - nr;
                }
                break;
                case 2: { // down, +r
                    nr = r + s;
                    if (nr > R) d ^= 1^2, nr = 2*R - nr;
                    if (nr < 1) d ^= 1^2, nr = 2 - nr;
                }
                break;
                case 3: { // right, +c
                    nc = c + s;
                    if (nc > C) d ^= 3^4, nc = 2*C - nc;
                    if (nc < 1) d ^= 3^4, nc = 2 - nc;
                }
                break;
                case 4: { // left, -c
                    nc = c - s;
                    if (nc < 1) d ^= 3^4, nc = 2 - nc;
                    if (nc > C) d ^= 3^4, nc = 2*C - nc;
                }
                break;
            }
            if (d2[nr][nc].z == 0 || d2[nr][nc].z < z)
                d2[nr][nc] = sh{s, d, z};
        }
    memcpy(d1, d2, sizeof(d1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> R >> C >> M;
    int sum = 0;
    for (int i = 0; i < M; ++i) {
        int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
        switch(d) {
            case 1: case 2:
                if (R == 1) s = 0;
                else s %= (R-1)*2;
                break;
            case 3: case 4:
                if (C == 1) s = 0;
                else s %= (C-1)*2;
                break;
        }
        d1[r][c] = sh{s, d, z};
    }
    for (int i = 1; i <= C; ++i) {
        for (int j = 1; j <= R; ++j) if (d1[j][i].z) {
            sum += d1[j][i].z;
            d1[j][i] = sh{};
            break;
        }
        mv();
    }
    cout << sum;
}