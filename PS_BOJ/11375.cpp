#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

int N, M, C[1010], D[1010], X, XX, R;
vi G[1010];

bool DFS(int i) {
    for (auto o : G[i]) if (!C[o]) {
        C[o] = 1;
        if (!D[o] || DFS(D[o])) {
            D[o] = i;
            return true;
        }
    }
    return false;
}

int main() { FAST
    cin >> N >> M;
    for1 (i, N) {
        cin >> X;
        fore (j, X) cin >> XX, G[i].push_back(XX);
    }
    for1 (i, N) {
        memset(C, 0, sizeof(C));
        if (DFS(i)) ++R;
    }
    cout << R;
}
