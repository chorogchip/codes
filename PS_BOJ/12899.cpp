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

int N, NN, Q, X, T[8010101];

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
    cin >> N;
    NN = 1<<32-__builtin_clz(2000000);
    fore (i, N) {
        cin >> Q >> X;
        if (Q == 1) insert(1, 1, NN);
        else cout << getNsub(1, 1, NN, X) << endl;
    }
}
