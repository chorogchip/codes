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

int N, NN, MM, m[401010], A, B;


int querym(int i, int l, int r, int s, int e) {
    if (e < l || r < s) return INF;
    if (l <= s && e <= r) return m[i];
    int md = s + e >> 1;
    return min(querym(i<<1, l, r, s, md), querym((i<<1)+1, l, r, md+1, e));
}

int main() { FAST
    cin >> N >> MM;
    NN = 1<<32-__builtin_clz(N);
    for (int i = NN; i != N + NN; ++i) cin >> m[i];
    for (int i = NN - 1; i; --i) m[i] = min(m[i<<1], m[(i<<1)+1]);
    fore (i, MM) {
        cin >> A >> B;
        cout << querym(1, A, B, 1, NN) << endl;
    }
}
