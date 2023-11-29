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

int T, N, M, NN, TR[1001010], X, XX, D[101010], K, KK;

int find(int i, int s, int e) {
    if (e < XX || KK < s) return 0;
    if (XX <= s && e <= KK) return TR[i];
    int md = s + e >> 1;
    return find(i<<1, s, md) + find((i<<1)+1, md+1, e);
}

int main() { FAST
    cin >> T;
    do {
        cin >> N >> M;
        NN = 1<<32-__builtin_clz(N + M);
        memset(TR + NN, 0, NN<<2);
        for (K = NN; K != NN + N; ++K) TR[K] = 1;
        for (int i = NN - 1; i; --i) TR[i] = TR[i<<1]+TR[(i<<1)+1];
        for1 (i, N) D[i] = NN + N - i;
        fore (m, M) {
            cin >> X;
            XX = D[X] - NN + 2;
            KK = K - NN;
            cout << find(1, 1, NN) << ' ';
            for (int i = D[X]; i; i >>= 1) --TR[i];
            D[X] = K++;
            for (int i = D[X]; i; i >>= 1) ++TR[i];
        }
        cout << endl;
    } while (--T);
}
