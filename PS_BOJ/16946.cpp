#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int N, M;
char D[1010][1010];
int U[1010][1010], S[1010101], K = 1;

int main() {
    scanf("%d %d", &N, &M); getchar();
    for1 (i, N) { for1 (j, M) D[i][j] = getchar()-'0'; getchar(); }
    for1 (i, N) D[i][0] = D[i][M+1] = 1;
    for1 (j, M) D[0][j] = D[N+1][j] = 1;
    D[0][0] = D[N+1][0] = D[0][M+1] = D[N+1][M+1] = 1;
    for1 (i, N) for1 (j, M) if (!D[i][j] && !U[i][j]) {
        queue<ii> qu;
        int rr = 0;
        qu.push({i, j});
        while (!qu.empty()) {
            auto o = qu.front(); qu.pop();
            if (!U[o.first][o.second] && !D[o.first][o.second]) {
                U[o.first][o.second] = K;
                ++rr;
                qu.push({o.first + 1, o.second});
                qu.push({o.first - 1, o.second});
                qu.push({o.first, o.second + 1});
                qu.push({o.first, o.second - 1});
            }
        }
        S[K] = rr;
        ++K;
    }
    vi v;
    for1 (i, N) for1 (j, M) if (D[i][j]) {
        v.clear();
        int sum = 1;
        #define ASD(x, y) if (!D[(x)][(y)] && std::find(v.begin(), v.end(), U[(x)][(y)]) == v.end()) \
        v.push_back(U[(x)][(y)]), sum += S[U[(x)][(y)]];
        ASD(i-1, j)
        ASD(i+1, j)
        ASD(i, j-1)
        ASD(i, j+1)
        D[i][j] = sum;
    }
    char res[1010101], *p = res;
    for1 (i, N) {
        for1 (j, M) *p++ = D[i][j]%10 + '0';
        *p++ = '\n';
    }
    fwrite(res, 1, N * (M + 1), stdout);
}