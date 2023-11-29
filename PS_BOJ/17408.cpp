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

int N, NN, M, A, B, C;
ii T[401010];

ii pm(const ii& a, const ii& b) {
    if (a.first > b.first) {
        if (a.second > b.first) return make_pair(a.first, a.second);
        else return make_pair(a.first, b.first);
    } else {
        if (b.second > a.first) return make_pair(b.first, b.second);
        else return make_pair(b.first, a.first);
    }
}

void change(int i, int s, int e) {
    if (B < s || e < B) return;
    if (s == e) {
        T[i].first = C;
        return;
    }
    int md = s + e >> 1;
    change(i<<1, s, md);
    change((i<<1)+1, md+1, e);
    T[i] = pm(T[i<<1], T[(i<<1)+1]);
}

ii get(int i, int s, int e) {
    if (C < s || e < B) return { 0, 0 };
    if (B <= s && e <= C) return T[i];
    int md = s + e >> 1;
    return pm(get(i<<1, s, md), get((i<<1)+1, md+1, e));
}

int main() { FAST
    cin >> N;
    for (NN = 1; NN < N; NN <<= 1);
    for (int i = NN; i != NN + N; ++i) cin >> T[i].first;
    for (int i = NN - 1; i; --i) T[i] = pm(T[i<<1], T[(i<<1)+1]);
    cin >> M;
    fore (i, M) {
        cin >> A >> B >> C;
        if (A == 1) change(1, 1, NN);
        else {
            ii ret = get(1, 1, NN);
            cout << ret.first + ret.second << endl;
        }
    }
}
