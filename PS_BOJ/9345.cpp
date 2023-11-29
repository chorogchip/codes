
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int T, N, NN, K, TM[401010], Tm[401010], Q, A, B;

int getM(int i, int s, int e) {
    if (B < s || e < A) return 0;
    if (A <= s && e <= B) return TM[i];
    int md = s + e >> 1;
    return max(getM(i<<1, s, md), getM((i<<1)+1, md+1, e));
}
int getm(int i, int s, int e) {
    if (B < s || e < A) return INF;
    if (A <= s && e <= B) return Tm[i];
    int md = s + e >> 1;
    return min(getm(i<<1, s, md), getm((i<<1)+1, md+1, e));
}

int main() { FAST
    cin >> T;
    do {
        cin >> N >> K;
        NN = 1<<32-__builtin_clz(N);
        fore (i, N) Tm[NN+i] = TM[NN+i] = i;
        for (int i = NN - 1; i; --i) {
            TM[i] = max(TM[i<<1], TM[(i<<1)+1]);
            Tm[i] = min(Tm[i<<1], Tm[(i<<1)+1]);
        }
        fore (k, K) {
            cin >> Q >> A >> B;
            if (Q) {
                ++A; ++B;
                if (getM(1, 1, NN) == B - 1 && getm(1, 1, NN) == A - 1)
                    cout << "YES\n";
                else cout << "NO\n";
            } else {
                int tmp = Tm[NN + A];
                Tm[NN+A] = TM[NN+A] = Tm[NN + B];
                Tm[NN+B] = TM[NN+B] = tmp;
                for (int i = NN + A >> 1; i; i >>= 1) {
                    TM[i] = max(TM[i<<1], TM[(i<<1)+1]);
                    Tm[i] = min(Tm[i<<1], Tm[(i<<1)+1]);
                }
                for (int i = NN + B >> 1; i; i >>= 1) {
                    TM[i] = max(TM[i<<1], TM[(i<<1)+1]);
                    Tm[i] = min(Tm[i<<1], Tm[(i<<1)+1]);
                }
            }
        }
    } while (--T);
}
