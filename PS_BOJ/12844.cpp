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

int N, NN, T[2010101], M, A, B, K, L[2010101];

void xorr(int i, int val, int l, int r, int s, int e) {
    if (e < l || r < s) return;
    else if (s == e) {
        T[i] ^= val;
        return;
    } else if (l <= s && e <= r) {
        L[i] ^= val;
        return;
    }
    if (min(r, e) - max(l, s) + 1 & 1) T[i] ^= val;
    int md = s + e >> 1;
    xorr(i<<1, val, l, r, s, md);
    xorr((i<<1)+1, val, l, r, md+1, e);
}

int sum(int i, int val, int l, int r, int s, int e, int lz) {
    if (e == s) T[i] ^= lz;
    L[i] ^= lz;
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return T[i];
    int lll = L[i];
    L[i] = 0;
    int md = s + e >> 1;
    return sum(i<<1, val, l, r, s, md, lll) ^ sum((i<<1)+1, val, l, r, md+1, e, lll);
}

int main() { FAST
    cin >> N;
    for (NN = 1<<30; NN >= N; NN >>= 1); NN <<= 1;
    for (int i = NN; i != NN + N; ++i) cin >> T[i];
    for (int i = NN - 1; i; --i) T[i] = T[i<<1] ^ T[(i<<1)+1];
    cin >> M;
    fore (i, M) {
        cin >> A;
        if (A == 1) {
            cin >> A >> B >> K;
            xorr(1, K, A+1, B+1, 1, NN);
        } else {
            cin >> A >> B;
            cout << sum(1, K, A+1, B+1, 1, NN, 0) << endl;
        }
    }
}
