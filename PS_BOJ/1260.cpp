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

int N, M, V, X, Y, C[1010];
vector<int> G[1010];

void DFS(int v) {
    cout << v << " ";
    C[v] = 1;
    for (auto vv : G[v]) if (!C[vv]) DFS(vv);
}

#include<queue>
void BFS(int v) {
    queue<int> qu;
    qu.push(v);
    C[v] = 1;
    while (!qu.empty()) {
        v = qu.front();
        qu.pop();
        cout << v << " ";
        for (auto vv : G[v]) if (!C[vv]) {
            qu.push(vv);
            C[vv] = 1;
        }
    }
}

MAIN { FAST
    cin >> N >> M >> V;
    for (int i = 1; i <= M; ++i) {
        cin >> X >> Y;
        G[X].push_back(Y);
        G[Y].push_back(X);
    }
    for (int i = 1; i <= N; ++i) sort(G[i].begin(), G[i].end());
    DFS(V);
    memset(C, 0, sizeof(C));
    cout << endl;
    BFS(V);
}
