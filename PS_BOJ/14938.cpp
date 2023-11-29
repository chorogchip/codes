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

int N, M, R, D[101][101], A, B, W, I[101], S;

int main() { FAST
    cin >> N >> M >> R;
    for1 (i, N) cin >> I[i];
    for1 (i, R) {
        cin >> A >> B >> W;
        D[A][B] = W;
        D[B][A] = W;
    }
    for1 (i, N) for1 (j, N)
        if (!D[i][j] && i != j) D[i][j] = INF;
    for1 (k, N) for1 (i, N) for1 (j, N)
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    for1 (i, N) {
        int sum = 0;
        for1 (j, N) if (D[i][j] <= M) sum += I[j];
        S = max(S, sum);
    }
    cout << S;
}
