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
int N, M, K, D[1001][1001], R[1001][1001][11];
unsigned int A = -1;
struct P {int x,y,k;P(int a,int b,int c):x(a),y(b),k(c){}P operator+(const P& p){return P(x+p.x,y+p.y,k+p.k);}}
dp[] = {P(1,0,0),P(-1,0,0),P(0,1,0),P(0,-1,0)};

MAIN {
    queue<P> qu;
    scanf("%d%d%d", &N, &M, &K);
    getchar();
    for (int i = 1; i <= N; ++i ) {
        for (int j = 1; j <= M; ++j)
            D[i][j] = getchar() - '0';
        getchar();
    }
    qu.push(P(1, 1, K));
    R[1][1][K] = 1;
    int cnt = 1;
    while (!qu.empty()) {
        cnt++;
        int qulen = qu.size();
        for (int c = 0; c != qulen; ++c) {
            P p = qu.front(); qu.pop();
            for (auto o : dp) {
                P p2 = p + o;
                if (p2.y>0&&p2.y<=N&&p2.x>0&&p2.x<=M) {
                    if (D[p2.y][p2.x]) {  // wall
                        p2.k--;
                        if (p2.k>=0&&!R[p2.y][p2.x][p2.k]) {
                            R[p2.y][p2.x][p2.k] = cnt;
                            qu.push(p2);
                        }
                    } else {  // not wall
                        if (!R[p2.y][p2.x][p2.k]) {
                            R[p2.y][p2.x][p2.k] = cnt;
                            qu.push(p2);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i <= K; ++i) if (R[N][M][i]) A = min(A, (unsigned int)R[N][M][i]);
    cout << (int)A;
}