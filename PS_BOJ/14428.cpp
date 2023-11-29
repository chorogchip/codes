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

int N, NN, T[401010], M, A, I, V, IN[401010];

void change(int i, int s, int e) {
    if (I < s || e < I) return;
    if (s == e) {
        T[i] = V;
        return;
    }
    int md = s + e >> 1;
    change(i<<1, s, md);
    change((i<<1)+1, md+1, e);
    if (T[i<<1] <= T[(i<<1)+1]) T[i] = T[i<<1], IN[i] = IN[i<<1];
    else T[i] = T[(i<<1)+1], IN[i] = IN[(i<<1)+1];
}
ii get(int i, int s, int e) {
    if (V < s || e < I) return make_pair(INF<<1, 0);
    if (I <= s && e <= V) return make_pair(T[i], IN[i]);
    int md = s + e >> 1;
    return min(get(i<<1, s, md), get((i<<1)+1, md+1, e));
}
int main() { FAST
    cin >> N; NN = 1<<32-__builtin_clz(N);
    for (int i = 0; i != N; ++i) cin >> T[i + NN], IN[i + NN] = i+1;
    for (int i = N; i <= NN; ++i) T[i + NN] = INF<<1;
    for (int i = NN - 1; i; --i) 
        if (T[i<<1] <= T[(i<<1)+1]) T[i] = T[i<<1], IN[i] = IN[i<<1];
        else T[i] = T[(i<<1)+1], IN[i] = IN[(i<<1)+1];
    cin >> M;
    fore (i, M) {
        cin >> A >> I >> V;
        if (A == 2) cout << get(1, 1, NN).second << endl;
        else change(1, 1, NN);
    }
}
