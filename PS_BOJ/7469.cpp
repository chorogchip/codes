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

int N, NN, NNN, NNNN, Q, T[18*201010], A, B, C;
vii vec;

void merge(int x, int sz) {
    sz >>= 1;
    if (!sz) return;
    merge(x+NN, sz);
    merge(x+NN+sz, sz);
    int i = x + NN, j = x + NN + sz, k = x;
    while (i < x + NN + sz && j < x + NN + (sz<<1)) {
        if (T[i] < T[j]) T[k++] = T[i++];
        else T[k++] = T[j++];
    }
    while (i < x + NN + sz) T[k++] = T[i++];
    while (j < x + NN + (sz<<1)) T[k++] = T[j++];
}

void putIntv(int x, int ii, int sz) {
    if (B < ii || ii + sz <= A) return;
    if (A <= ii && ii + sz - 1 <= B) {
        vec.emplace_back(x, x + sz);
        return;
    }
    sz >>= 1; x += NN;
    putIntv(x, ii, sz);
    putIntv(x + sz, ii+sz, sz);
}

int getcnt(int x) {
    int cnt = 0;
    for (auto o : vec)
        cnt += upper_bound(T + o.first, T + o.second, x)
            - (T + o.first);
    return cnt;
}

int main() { FAST
    cin >> N >> Q;
    NNN = 33-__builtin_clz(N);
    NN = 1<<NNN-1;
    NNNN = (NNN-1)*NN;
    for (int i = NNNN; i != NNNN + N; ++i) cin >> T[i];
    merge(0, NN);
    fore (i, Q) {
        cin >> A >> B >> C; --A; --B;
        vec.clear();
        putIntv(0, 0, NN);
        int lo = -INF, md, hi = INF;
        while (lo < hi) {
            md = lo + hi;
            if (md < 0) md = md - 1 >> 1;
            else md >>= 1;
            if (getcnt(md) >= C) hi = md;
            else lo = md + 1;
        }
        cout << lo << endl;
    }
}
