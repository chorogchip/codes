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

int N, A, B, C[101010];
vector<int> G[101010];

void BFS(int v) {
    for (auto o : G[v]) if (!C[o]) {
        C[o] = v;
        BFS(o);
    }
}

int main() { FAST
    cin >> N;
    for (int i = 1; i != N; ++i) {
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    C[1] = -1;
    BFS(1);
    for (int i = 2; i <= N; ++i) cout << C[i] << endl;
}
