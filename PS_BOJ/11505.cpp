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

int N, NN, M, K;
ll D[4010101], A, B, C;
constexpr ll Mod = 1000000007LL;

ll query(int i, int l, int r, int s, int e) {
    if (e < l || r < s) return 1;
    else if (l <= s && e <= r) return D[i];
    int md = s + e >> 1;
    return query(i<<1, l, r, s, md) * query((i<<1)+1, l, r, md+1, e) % Mod;
}
void update(int i, int ii, ll x, int s, int e) {
    if (e < ii || ii < s) return;
    else if (s == e) {
        D[i] = x;
        return;
    }
    int md = s + e >> 1;
    if (ii <= md) update(i<<1, ii, x, s, md);
    else update((i<<1)+1, ii, x, md+1, e);
    D[i] = D[i<<1] * D[(i<<1)+1] % Mod;
}
int main() { FAST
    cin >> N >> M >> K;
    M += K;
    NN = 1<<32-__builtin_clz(N);
    int i;
    for (i = NN; i != NN + N; ++i) cin >> D[i];
    for (; i != NN + NN; ++i) D[i] = 1;
    for (i = NN - 1; i; --i) D[i] = D[i<<1] * D[(i<<1)+1] % Mod;
    fore (j, M) {
        cin >> A >> B >> C;
        if (A == 1) update(1, B, C, 1, NN);
        else cout << query(1, B, C, 1, NN) << endl;
    }
}
