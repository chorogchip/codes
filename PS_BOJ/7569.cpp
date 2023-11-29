#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
struct Pos {
    int x, y, z;
    Pos(int x_,int y_, int z_): x(x_), y(y_), z(z_) {}
    Pos operator+(const Pos& p) const {
        Pos res(this->x + p.x, this->y + p.y, this->z + p.z);
        return res;
    }
};

int M, N, H, R, D[101][101][101];
queue<Pos> qu;
Pos arr[] {Pos(1,0,0),Pos(-1,0,0),Pos(0,1,0),Pos(0,-1,0),Pos(0,0,1),Pos(0,0,-1)};

MAIN { FAST
    cin >> M >> N >> H;
    foreach (i, H) foreach (j, N) foreach (k, M) {
        cin >> D[i][j][k];
        if (D[i][j][k] == 1) qu.push(Pos(k, j, i));
    }
    while (!qu.empty()) {
        ++R;
        int sz = qu.size();
        for (int aa = 0; aa != sz; ++aa) {
            Pos p = qu.front(); qu.pop();
            for(auto& o : arr) {
                Pos p2 = p + o;
                if (p2.x >= 0 && p2.x < M &&
                    p2.y >= 0 && p2.y < N &&
                    p2.z >= 0 && p2.z < H &&
                    D[p2.z][p2.y][p2.x] == 0) {
                    D[p2.z][p2.y][p2.x] = 1;
                    qu.push(p2);
                }
            }
        }
    }

    foreach (i, H) foreach (j, N) foreach (k, M) if (D[i][j][k] == 0) {
        cout << "-1";
        return 0;
    }
    cout << R - 1;
}