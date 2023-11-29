#include<iostream>
#include<cstdlib>
#include<vector>
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

typedef long long ll;
int T;
constexpr ll Ml = 1000000007LL;
ll N, K, A, B, C, F[4010101];
constexpr int Mi = 1000000007;

ll fact(ll i) {
    if (F[i]) return F[i];
    else return F[i] = (fact(i-1) * i) % Ml;
}
int main() { FAST
    cin >> T;
    F[0] = F[1] = 1LL;
    while (T--) {
        cin >> N >> K; C = 1LL;
        A = fact(N);
        B = fact(K) * fact(N-K) % Ml;
        for (int i = Mi - 2; i; i >>= 1) {
            if (i & 1) C *= B, C %= Ml;
            B *= B, B %= Ml;
        }
        cout << A * C % Ml << endl;
    }
}
