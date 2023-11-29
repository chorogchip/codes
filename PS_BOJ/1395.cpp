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

int N, NN, M, A, B, C, T[401010], L[401010];

void rv(int i, int s, int e, int lz) {
    if (lz) T[i] = e - s + 1 - T[i],
    L[i] ^= 1;
    if (C < s || e < B) return;
    if (B <= s && e <= C) {
        T[i] = e - s + 1 - T[i];
        L[i] ^= 1;
        return;
    }
    int md = s + e >> 1;
    int lll = L[i];
    L[i] = 0;
    rv(i<<1, s, md, lll);
    rv((i<<1)+1, md+1, e, lll);
    T[i] = T[i<<1] + T[(i<<1)+1];
}
int sum(int i, int s, int e, int lz) {
    if (lz) T[i] = e - s + 1 - T[i],
    L[i] ^= 1;
    if (C < s || e < B) return 0;
    if (B <= s && e <= C) return T[i];
    int md = s + e >> 1;
    int lll = L[i];
    L[i] = 0;
    return sum(i<<1, s, md, lll) + sum((i<<1)+1, md+1, e, lll);
}

int main() { FAST
    cin >> N >> M;
    NN = 1<<32-__builtin_clz(N);
    fore (i, M) {
        cin >> A >> B >> C;
        if (A) cout << sum(1, 1, NN, 0) << endl;
        else rv(1, 1, NN, 0);
    }
}
