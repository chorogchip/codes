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

int N, M, G[101][101], A, B, C;

int main() { FAST
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            G[i][j] = 1010101010;
    fore (i, M) {
        cin >> A >> B >> C;
        if (C < G[A][B]) G[A][B] = C;
    }
    for (int m = 1; m <= N; ++m)
        for (int st = 1; st <= N; ++st)
            for (int to = 1; to <= N; ++to)
                if (G[st][to] > G[st][m] + G[m][to])
                    G[st][to] = G[st][m] + G[m][to];
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            if (i == j || G[i][j] == 1010101010) cout << 0 << ' ';
            else cout << G[i][j] << ' ';
        cout << endl;
    }
}
