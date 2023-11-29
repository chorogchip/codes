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

constexpr ll Mod = INF + 7;
struct tr {
    int lt, lb, rt, rb, pc;
    ll s[2];
};
ll F[101010] = { 1, 1, 1, 2, 0, };
tr T[401010];
int N, NN, Q, A, X, Y;

void insert(int i, int s, int e) {
    tr& ths = T[i];
    ++ths.pc;
    if (ths.pc == 1 || s == e) {
        if (X == 1) ths.lt = ths.rt = Y, ths.lb = INF, ths.rb = -INF;
        else ths.lb = ths.rb = Y, ths.lt = INF, ths.rt = -INF;
        ths.s[0] = ths.s[1] = 1;
        if (s == e) return;
    } else {
        if (X == 1) ths.lt = min(ths.lt, Y), ths.rt = max(ths.rt, Y);
        else ths.lb = min(ths.lb, Y), ths.rb = max(ths.rb, Y);
    }
    int md = s + e >> 1;
    if (Y <= md) insert(i<<1, s, md);
    else insert((i<<1)+1, md+1, e);
    tr& lft = T[i<<1];
    tr& rit = T[(i<<1)+1];
    if (lft.pc == 0) {
        ths.s[0] = rit.s[0];
        ths.s[1] = rit.s[1];
        return;
    } else if (rit.pc == 0) {
        ths.s[0] = lft.s[0];
        ths.s[1] = lft.s[1];
        return;
    }
    if (lft.pc & 1) {
        ths.s[1] = (lft.s[1] * rit.s[0] % Mod);
        int gap = min(rit.lt, rit.lb)-max(lft.rt, lft.rb);
        if (rit.lt == rit.lb || lft.rt == lft.rb)
            ths.s[0] = 0;
        else if ((rit.lt < rit.lb) == (lft.rt > lft.rb) && (gap & 1) == 0)
            ths.s[0] = 0;
        else if ((rit.lt < rit.lb) != (lft.rt > lft.rb) && (gap & 1))
            ths.s[0] = 0;
        else
            ths.s[0] = (lft.s[0] * rit.s[1] % Mod) * F[gap] % Mod;
    } else {
        ths.s[0] = (lft.s[0] * rit.s[0] % Mod);
        int gap = min(rit.lt, rit.lb)-max(lft.rt, lft.rb);
        if (rit.lt == rit.lb || lft.rt == lft.rb)
            ths.s[1] = 0;
        else if ((rit.lt < rit.lb) == (lft.rt > lft.rb) && (gap & 1) == 0)
            ths.s[1] = 0;
        else if ((rit.lt < rit.lb) != (lft.rt > lft.rb) && (gap & 1))
            ths.s[1] = 0;
        else ths.s[1] = (lft.s[1] * rit.s[1] % Mod) * F[gap] % Mod;
    }
}

void sub(int i, int s, int e) {
    tr& ths = T[i];
    --ths.pc;
    if (s == e) {
        if (X == 1) ths.lt = INF, ths.rt = -INF;
        else ths.lb = INF, ths.rb = -INF;
        ths.s[0] = ths.s[1] = 1;
        return;
    }
    int md = s + e >> 1;
    if (Y <= md) sub(i<<1, s, md);
    else sub((i<<1)+1, md+1, e);
    tr& lft = T[i<<1];
    tr& rit = T[(i<<1)+1];
    if (lft.lt == INF) ths.lt = rit.lt;
    else ths.lt = lft.lt;
    if (lft.lb == INF) ths.lb = rit.lb;
    else ths.lb = lft.lb;
    if (rit.rt == -INF) ths.rt = lft.rt;
    else ths.rt = rit.rt;
    if (rit.rb == -INF) ths.rb = lft.rb;
    else ths.rb = rit.rb;
    if (lft.pc == 0) {
        ths.s[0] = rit.s[0];
        ths.s[1] = rit.s[1];
        return;
    } else if (rit.pc == 0) {
        ths.s[0] = lft.s[0];
        ths.s[1] = lft.s[1];
        return;
    }
    if (lft.pc & 1) {
        ths.s[1] = (lft.s[1] * rit.s[0] % Mod);
        int gap = min(rit.lt, rit.lb)-max(lft.rt, lft.rb);
        if (rit.lt == rit.lb || lft.rt == lft.rb)
            ths.s[0] = 0;
        else if ((rit.lt < rit.lb) == (lft.rt > lft.rb) && (gap & 1) == 0)
            ths.s[0] = 0;
        else if ((rit.lt < rit.lb) != (lft.rt > lft.rb) && (gap & 1))
            ths.s[0] = 0;
        else
            ths.s[0] = (lft.s[0] * rit.s[1] % Mod) * F[gap] % Mod;
    } else {
        ths.s[0] = (lft.s[0] * rit.s[0] % Mod);
        int gap = min(rit.lt, rit.lb)-max(lft.rt, lft.rb);
        if (rit.lt == rit.lb || lft.rt == lft.rb)
            ths.s[1] = 0;
        else if ((rit.lt < rit.lb) == (lft.rt > lft.rb) && (gap & 1) == 0)
            ths.s[1] = 0;
        else if ((rit.lt < rit.lb) != (lft.rt > lft.rb) && (gap & 1))
            ths.s[1] = 0;
        else ths.s[1] = (lft.s[1] * rit.s[1] % Mod) * F[gap] % Mod;
    }
}

ll getC() {
    tr& ths = T[1];
    if (T[1].pc == 0) return F[N+1];
    return ths.s[1] * (
        F[min(ths.lt, ths.lb)] * F[N+1-max(ths.rt, ths.rb)] % Mod
    ) % Mod;
}

void prtTree(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << "Tree #" << i << endl;
        cout << T[i].lt << ' ' << T[i].lb << ' ' << T[i].rt << ' ' << T[i].rb << endl;
        cout << T[i].pc << ' ' << T[i].s[0] << ' ' << T[i].s[1] << endl;
    }
}

int main() { FAST
    cin >> N >> Q;
    for (int i = 4; i <= N+1; ++i) F[i] = (F[i-1] + F[i-2]) % Mod;
    NN = 1<<32-__builtin_clz(N);
    for (int i = 1; i != NN << 1; ++i) {
        T[i].lt = T[i].lb = INF;
        T[i].rt = T[i].rb = -INF;
        T[i].pc = 0;
        T[i].s[0] = T[i].s[1] = 1;
    }
    T[1].s[0] = F[N+1];
    int iii = 1;
    fore (i, Q) {
        cin >> A >> X >> Y;
        if (A == 1) insert(1, 1, NN);
        else sub(1, 1, NN);
        if (iii) cout << "0\n";
        else cout << getC() << endl;
        iii ^= 1;
        prtTree(NN);
    }
}
