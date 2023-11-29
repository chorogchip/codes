#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

struct N {
    N* ptr;
};
N g[2048][2048];

N* getan(N* a) {
    if (a->ptr == a) return a;
    return a->ptr = getan(a->ptr);
}

void un(N* a, N* b) {
    N* aa = getan(a);
    N* bb = getan(b);
    aa->ptr = bb;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) g[i][j].ptr = &g[i][j];
        for (int kk = 0; kk < k; ++kk) {
            int a, b, c, d; 
            cin >> a >> b >> c >> d;
            un(&g[a][b], &g[c][d]);
        }
        for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j) {
            N *ns[4];
            ns[0] = getan(&g[i][j]);
            ns[1] = getan(&g[i][j+1]);
            ns[2] = getan(&g[i+1][j]);
            ns[3] = getan(&g[i+1][j+1]);
            if (ns[0] == ns[1] || ns[1] == ns[3] || ns[3] == ns[2] || ns[2] == ns[0]) goto NO;
            if (ns[0] == ns[3] && ns[1] == ns[2]) goto NO;
        }
        YES: cout << "YES\n"; continue;
        NO: cout << "NO\n"; continue;
    }
}

/*

0A00B
A00B0
00000
00000
00000
00000
C000D
0C0D0


BABCB
ACABA
BABCB
CBCAC
BABCB
00000
BABAB
CBCBC

*/