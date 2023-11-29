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
    int x, y;
    Pos(int x_,int y_): x(x_), y(y_) {}
    Pos operator+(const Pos& p) const {
        Pos res(this->x + p.x, this->y + p.y);
        return res;
    }
};

int N, M, D[1001][1001];
queue<Pos> qu, qu2;
Pos arr[] {Pos(1,0),Pos(-1,0),Pos(0,1),Pos(0,-1)};

MAIN { FAST
    cin >> N >> M;
    foreach (i, M) foreach (j, N) {
        cin >> D[i][j];
        if (D[i][j] == 1) qu.push(Pos(i, j));
    }
    int k = -2;
    while (k++, !qu.empty()) {
        while(!qu.empty()) {
            Pos p = qu.front(); qu.pop();
            for(auto& o : arr) {
                Pos p2 = p + o;
                if (p2.x >= 0 && p2.x < M &&
                    p2.y >= 0 && p2.y < N &&
                    D[p2.x][p2.y] == 0) {
                    D[p2.x][p2.y] = 1;
                    qu2.push(p2);
                }
            }
        }
        while(!qu2.empty()) qu.push(qu2.front()), qu2.pop();
    }

    foreach (i, M) foreach (j, N) if (D[i][j] == 0) {
        cout << "-1";
        return 0;
    }
    cout << k;
}