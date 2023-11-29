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

int N, D[12][12], B[12][12];

int dfs(int x, int y, int dep) {
    do {
        ++y;
        if (y > N) y = 1, ++x;
        if (x > N) return 0;
    } while (D[x][y]);
    int res = dfs(x, y, dep+1);
    for1 (i, N) for1 (j, N) if (x+y == i+j || x-y == i-j) {
        if (B[i][j]) goto E;
        if (!D[i][j]) D[i][j] = dep;
    }
    B[x][y] = 1;
    res = max(res, dfs(x, y, dep+1)+1);
    E:
    for1 (i, N) for1 (j, N) if (D[i][j] == dep) D[i][j] = 0;
    B[x][y] = 0;
    return res;
}

int main() { FAST
    cin >> N;
    for1 (i, N) for1 (j, N) cin >> D[i][j], D[i][j] = !D[i][j];
    cout << dfs(1, 0, 2);
}
