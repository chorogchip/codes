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

int N, M, A, B, C[1010], R;
vector<int> G[1010];

void BFS(int v) {
    for (auto o : G[v]) if (!C[o])
        C[o] = 1, BFS(o);
}

main() { FAST
    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    for (int i = 1; i <= N; ++i) if (!C[i])
        ++R, C[i] = 1, BFS(i);
    cout << R;
}

