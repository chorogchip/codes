#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
constexpr int INF = 1000*1000*1000;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int N, NN, K, X, T[4010101], C;

void insert(int i, int s, int e) {
    ++T[i];
    if (s == e) return;
    int md = s + e >> 1;
    if (X <= md) insert(i<<1, s, md);
    else insert((i<<1)+1, md+1, e);
}

int getNsub(int i, int s, int e, int k) {
    --T[i];
    if (s == e) return s;
    int md = s + e >> 1;
    if (T[i<<1] >= k) return getNsub(i<<1, s, md, k);
    else return getNsub((i<<1)+1, md+1, e, k-T[i<<1]);
}

int main() { FAST
    cin >> N >> K;
    NN = 1<<32-__builtin_clz(1000000);
    for (X = 1; X <= N; ++X) insert(1, 1, NN);
    cout << '<';
    X = 0; --K; C = N;
    for (int i = 1; i != N; ++i) {
        X += K;
        X %= C;
        cout << getNsub(1, 1, NN, X + 1) << ", ";
        --C;
    }
    X += K;
    X %= C;
    cout << getNsub(1, 1, NN, X + 1) << '>';
}
