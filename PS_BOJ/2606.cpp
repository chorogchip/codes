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

int N, M, A, B, R, C[101];
vector<int> G[101];

void DFS(int i) {
    for (auto o : G[i]) if (!C[o]) {
        ++R;
        C[o] = 1;
        DFS(o);
    }
}

main() { FAST
    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    C[1] = 1;
    DFS(1);
    cout << R;
}

