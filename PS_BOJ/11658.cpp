#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
constexpr int INF = 1000*1000*1000;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int N, NN, M, T[101010], E[1030][1030], W, A, B, C, D;

void addd(int i, int x1, int y1, int x2, int y2) {
    if (A < x1 || x2 < A || B < y1 || y2 < B) return;
    T[i] += C;
    if (x1 == x2) return;
    int mdx = x1 + x2 >> 1;
    int mdy = y1 + y2 >> 1;
    if (A <= mdx)
        if (B <= mdy) addd(i<<2, x1, y1, mdx, mdy);
        else addd((i<<2)+1, x1, mdy+1, mdx, y2);
    else 
        if (B <= mdy) addd((i<<2)+2, mdx+1, y1, x2, mdy);
        else addd((i<<2)+3, mdx+1, mdy+1, x2, y2);
}

int summ(int i, int x1, int y1, int x2, int y2) {
    if (C < x1 || x2 < A || D < y2 || y1 < B) return 0;
    if (A <= x1 && x2 <= C && B <= y1 && y2 <= D) return T[i];
    int mdx = x1 + x2 >> 1;
    int mdy = y1 + y2 >> 1;
    return summ(i<<2, x1, y1, mdx, mdy) +
           summ((i<<2)+1, x1, mdy+1, mdx, y2) +
           summ((i<<2)+2, mdx+1, y1, x2, mdy) +
           summ((i<<2)+3, mdx+1, mdy+1, x2, y2);
}

int main() { FAST
    cin >> N >> M;
    NN = 1<<32-__builtin_clz(N);
    for1 (i, N) for1 (j, N) {
        cin >> C;
        E[i][j] = C;
        A = i;
        B = j;
        addd(1, 1, 1, NN, NN);
    }
    fore (i, M) {
        cin >> W;
        if (W) {
            cin >> A >> B >> C >> D;
            cout << summ(1, 1, 1, NN, NN) << endl;
        } else {
            cin >> A >> B >> D;
            C = D - E[A][B];
            E[A][B] = D;
            addd(1, 1, 1, NN, NN);
        }
    }
}
