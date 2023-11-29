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

int TT, N, NN, K, X, I, T[401010];
char C;

int find(int i, int s, int e) {
    if (X < s || e < I) return 1;
    if (I <= s && e <= X) return T[i];
    int md = s + e >> 1;
    return find(i<<1, s, md) * find((i<<1)+1, md+1, e);
}

int main() { FAST
    while (cin >> N) {
        cin >> K;
        NN = 1<<32-__builtin_clz(N);
        for (int i = NN; i != NN + N; ++i) cin >> X, T[i] = (X > 0) - (X < 0);
        for (int i = NN - 1; i; --i) T[i] = T[i<<1] * T[(i<<1)+1];
        fore (i, K) {
            cin >> C;
            if (C == 'C') {
                cin >> I >> X;
                I += NN - 1;
                T[I] = (X > 0) - (X < 0); I >>= 1;
                do T[I] = T[I<<1] * T[(I<<1)+1]; while (I >>= 1);
            } else {
                cin >> I >> X;
                int r = find(1, 1, NN);
                if (!r) cout << '0';
                else if (r == 1) cout << '+';
                else cout << '-';
            }
        }
        cout << endl;
    }
}
