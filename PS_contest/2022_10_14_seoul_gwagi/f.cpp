#include<iostream>
#include<vector>
using namespace std;

int N, T[201010], R;
char C[201010];
vector<int> G[201010];

void bfs(int t, int cost, int prev) {
    
}

int main() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i) {
        cin >> C[i];
    }
    bfs(1, 1, 0);
    cout << R;
}