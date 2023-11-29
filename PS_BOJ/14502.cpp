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

struct Pos {
    int a, b;
    Pos(int n, int m):a(n),b(m){}
    Pos operator+(const Pos& p) const { return Pos(a+p.a, b+p.b); }
} PPP[] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };
int N, M, S[3], D[10][10], R, P[10][10];
vector<Pos> PV, PW, PW2, PW3;

#include<queue>
queue<Pos> qu;

void asdf(Pos a, Pos b, Pos c) {
    int cnt = 3;
    int C[10][10]; memcpy(C, D, sizeof(C));
    C[a.a][a.b] = 1;
    C[b.a][b.b] = 1;
    C[c.a][c.b] = 1;
    for (auto o : PV) {
        qu.push(o);
        C[o.a][o.b] = 2;
    }
    while (!qu.empty()) {
        Pos p = qu.front(); qu.pop();
        if (!C[p.a-1][p.b]) C[p.a-1][p.b] = 2, ++cnt, qu.push(Pos(p.a-1,p.b));
        if (!C[p.a+1][p.b]) C[p.a+1][p.b] = 2, ++cnt, qu.push(Pos(p.a+1,p.b));
        if (!C[p.a][p.b-1]) C[p.a][p.b-1] = 2, ++cnt, qu.push(Pos(p.a,p.b-1));
        if (!C[p.a][p.b+1]) C[p.a][p.b+1] = 2, ++cnt, qu.push(Pos(p.a,p.b+1));
    }
    R = max(R, S[0] - cnt);
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
        cin >> D[i][j];
        ++S[D[i][j]];
        if (D[i][j] == 2) PV.push_back(Pos(i, j));
    }
    for (int i = 0; i <= N + 1; ++i) D[i][0] = D[i][M+1] = 1;
    for (int j = 0; j <= M + 1; ++j) D[0][j] = D[N+1][j] = 1;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) if (!D[i][j])
        if (D[i-1][j] || D[i+1][j] || D[i][j-1] || D[i][j+1] ||
            D[i-1][j-1] || D[i-1][j+1] || D[i+1][j-1] || D[i+1][j+1])
            P[i][j] = 1, PW.push_back(Pos(i, j));
    int s = PW.size();
    for (int i =     0; i < s; ++i)
    for (int j = i + 1; j < s; ++j)
    for (int k = j + 1; k < s; ++k)
        asdf(PW[i], PW[j], PW[k]);
    for (int i =     0; i < s; ++i)
    for (int j = i + 1; j < s; ++j) {
        Pos pi = PW[i];
        for (auto o : PPP) { Pos p2 = pi + o; if (!P[p2.a][p2.b] && !D[p2.a][p2.b])
            asdf(PW[i], PW[j], p2);
        }
        pi = PW[j];
        for (auto o : PPP) { Pos p2 = pi + o; if (!P[p2.a][p2.b] && !D[p2.a][p2.b])
            asdf(PW[i], PW[j], p2);
        }
    }
    for (int i =     0; i < s; ++i) {
        Pos pi = PW[i];
        for (auto o : PPP) { Pos p2 = pi + o; if (!P[p2.a][p2.b] && !D[p2.a][p2.b]) {
            P[p2.a][p2.b] = 2;
            for (auto o : PPP) { Pos p3 = pi + o; if (!P[p3.a][p3.b] && !D[p3.a][p3.b])
                asdf(pi, p2, p3);
            }
            for (auto o : PPP) { Pos p3 = p2 + o; if (!P[p3.a][p3.b] && !D[p3.a][p3.b])
                asdf(pi, p2, p3);
            }
            P[p2.a][p2.b] = 0;
        }}
    }
    cout << R << endl;
}
