#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

#include<queue>
int N, M, D[101][101];
struct Pos {
    int x, y;
    Pos(int x_,int y_): x(x_), y(y_) {}
    Pos operator+(const Pos& p) const {
        Pos res(this->x + p.x, this->y + p.y);
        return res;
    }
} dxys[] {Pos(1,0),Pos(-1,0),Pos(0,1),Pos(0,-1)};

MAIN {
    scanf("%d%d", &N, &M); getchar();
    foreach (i, N) { foreach (j, M) D[i][j] = getchar() - '0'; getchar(); }
    queue<Pos> qu;
    qu.push(Pos(0, 0));
    int cnt = D[0][0] = 2;
    while (!qu.empty()) {
        cnt++;
        int qsize = qu.size();
        foreach (i, qsize) {
            Pos p = qu.front(); qu.pop();
            for (auto o : dxys) {
                Pos p2 = p + o;
                if (p2.x >= 0 && p2.x < M &&
                    p2.y >= 0 && p2.y < N &&
                    D[p2.y][p2.x] == 1) {
                    D[p2.y][p2.x] = cnt;
                    qu.push(p2);
                }
            }
        }
    }
    cout << D[N - 1][M - 1] - 1;
}