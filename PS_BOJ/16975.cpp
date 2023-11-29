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

int N, NN, M, Q, A, B; ll T[401010], L[401010], K;

void add(int i, int s, int e) {
    if (B < s || e < A) return;
    if (s == e) {
        T[i] += K;
        return;
    }
    if (A <= s && e <= B) {
        L[i] += K;
        return;
    }
    //T[i] += K * (min(B, e) - max(A, s) + 1);
    int md = s + e >> 1;
    add(i<<1, s, md);
    add((i<<1)+1, md+1, e);
}

ll get(int i, int s, int e) {
    if (K < s || e < K) return 0;
    if (s == e) return T[i];
    int md = s + e >> 1;
    if (md >= K) return L[i] + get(i<<1, s, md);
    else return L[i] + get((i<<1)+1, md+1, e);
}

int main() { FAST
    cin >> N;
    for (NN = 1; NN < N; NN <<= 1);
    for (int i = NN; i != NN + N; ++i) cin >> T[i];
    cin >> M;
    fore (i, M) {
        cin >> Q;
        if (Q == 1) cin >> A >> B >> K, add(1, 1, NN);
        else cin >> K, cout << get(1, 1, NN) << endl;
    }
}
