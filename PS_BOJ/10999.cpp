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

int N, NN, M, K, A, B;
ll C, X, T[4010101], L[4010101];

void add(int i, ll val, int l, int r, int s, int e) {
    if (r < s || e < l) return;
    if (s == e) {
        T[i] += val;
        return;
    } else if (l <= s && e <= r) {
        T[i] += val * (e - s + 1);
        L[i] += val;
        return;
    }
    T[i] += val * (min(r, e) - max(l, s) + 1);
    int md = s + e >> 1LL;
    add(i<<1, val, l, r, s, md);
    add((i<<1)+1, val, l, r, md+1, e);
}

ll sum(int i, int l, int r, int s, int e, ll lz) {
    T[i] += lz * (e - s + 1);
    L[i] += lz;
    if (r < s || e < l) return 0LL;
    if (l <= s && e <= r) return T[i];
    ll lll = L[i];
    L[i] = 0LL;
    int md = s + e >> 1;
    return sum(i<<1, l, r, s, md, lll) + sum((i<<1)+1, l, r, md+1, e, lll);
}

int main() { FAST
    cin >> N >> M >> K;
    M += K;
    NN = 1<<32-__builtin_clz(N);
    for (int i = NN; i != NN + N; ++i) cin >> T[i];
    for (int i = NN - 1; i; --i) T[i] = T[i<<1] + T[(i<<1)+1];
    fore (i, M) {
        cin >> A;
        if (A == 1) {
            cin >> A >> B >> C;
            if (A > B) swap(A, B);
            add(1, C, A, B, 1, NN);
        } else {
            cin >> A >> B;
            if (A > B) swap(A, B);
            cout << sum(1, A, B, 1, NN, 0) << endl;
        }
    }
}
