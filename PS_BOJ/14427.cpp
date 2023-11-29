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
int main() { FAST
    cin >> N; NN = 1<<32-__builtin_clz(N);
    for (int i = 0; i != N; ++i) cin >> T[i + NN], IN[i + NN] = i+1;
    for (int i = N; i <= NN; ++i) T[i + NN] = INF;
    for (int i = NN - 1; i; --i) 
        if (T[i<<1] <= T[(i<<1)+1]) T[i] = T[i<<1], IN[i] = IN[i<<1];
        else T[i] = T[(i<<1)+1], IN[i] = IN[(i<<1)+1];
    cin >> M;
    fore (i, M) {
        cin >> A;
        if (A == 2) cout << IN[1] << endl;
        else {
            cin >> I >> V;
            change(1, 1, NN);
        }
    }
}
