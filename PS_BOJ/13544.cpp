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

int N, NN, NNN, M, A, B, K, T[4010101], *L, *R, LA;

void sorrt(int* i, int sz) {
    if (sz == 1) return;
    sort(i, i + sz);
    int md = sz>>1;
    i += NN;
    sorrt(i, md);
    sorrt(i + md, md);
}
int find(int* i, int sz, int* l) {
    if (R <= l || l + sz <= L) return 0;
    if (L <= l && l + sz <= R)
        return (i + sz) - upper_bound(i, i + sz, K);
    int mds = sz >> 1; i += NN;
    return find(i, mds, l) + find(i + mds, mds, l + mds);
}

int main() { FAST
    cin >> N; NNN = 33-__builtin_clz(N); NN = 1<<NNN-1;
    fore (i, N) cin >> T[i];
    for (int i = NN; i != NN*NNN; ++i) T[i] = T[i-NN];
    cin >> M;
    sorrt(T, NN);
    fore (i, M) {
        cin >> A >> B >> K;
        A ^= LA; B ^= LA; K ^= LA;
        L = T + A - 1; R = T + B;
        cout << (LA = find(T, NN, T)) << endl;
    }
}
