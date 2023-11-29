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
typedef pair<int,ii> iii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

int N, M, R;
char D[23][23], C[100];

int DFS(int i, int j) {
    int m = 1, a;
    if (!C[a=D[i-1][j]]) C[a]=1, m = max(m, DFS(i-1, j)+1), C[a]=0;
    if (!C[a=D[i+1][j]]) C[a]=1, m = max(m, DFS(i+1, j)+1), C[a]=0;
    if (!C[a=D[i][j-1]]) C[a]=1, m = max(m, DFS(i, j-1)+1), C[a]=0;
    if (!C[a=D[i][j+1]]) C[a]=1, m = max(m, DFS(i, j+1)+1), C[a]=0;
    return m;
}

int main() { FAST
    cin >> N >> M;
    for1 (i, N) for1 (j, M) cin >> D[i][j];
    C[0] = 1;
    ++C[D[1][1]];
    cout << DFS(1, 1);
}
