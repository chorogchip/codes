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

int N, NN, T[2001010], L[2001010], M, R, A, B, C;

void xorr(int i, int val, int s, int e) {
    if (e < A || B < s) return;
    if (A <= s && e <= B) {
        if (e == s) T[i] ^= val;
        L[i] ^= val;
        return;
    }
    if (e - s + 1 & 1) T[i] ^= val;
    int md = s + e >> 1;
    xorr(i<<1, val, s, md);
    xorr((i<<1)+1, val, md+1, e);
}

int get(int i, int ind, int s, int e, int lz) {
    if (e - s + 1 & 1) T[i] ^= lz;
    L[i] ^= lz;
    if (ind < s || e < ind) return 0;
    if (s == e) return T[i];
    int md = s + e >> 1;
    int lll = L[i];
    L[i] = 0;
    return get(i<<1, ind, s, md, lll) ^ get((i<<1)+1, ind, md+1, e, lll);
}

int main() { FAST
    cin >> N;
    for (NN = 1; NN < N; NN <<= 1);
    for (int i = NN; i != NN + N; ++i) cin >> T[i];
    for (int i = NN - 1; i; --i) T[i] = T[i<<1] ^ T[(i<<1)+1];
    cin >> M;
    fore (i, M) {
        cin >> R;
        if (R == 1) cin >> A >> B >> C, ++A, ++B, xorr(1, C, 1, NN);
        else cin >> A, cout << get(1, A+1, 1, NN, 0) << endl;
    }
}
