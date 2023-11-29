#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

typedef long long ll;
ll N, B, BB[5][5], D[5][5], T[5][5];
constexpr ll M = 1000;

int main() { FAST
    cin >> N >> B;
    fore (i, N) fore (j, N) cin >> BB[i][j];
    fore (i, N) D[i][i] = 1LL;
    for (ll b = B; b; b >>= 1LL) {
        if (b & 1LL) {
            fore (i, N) fore (j, N) {
                T[i][j] = 0LL;
                fore (k, N) T[i][j] += D[i][k] * BB[k][j] % M, T[i][j] %= M;
            }
            fore (i, N) fore (j, N) D[i][j] = T[i][j];
        }
        fore (i, N) fore (j, N) {
            T[i][j] = 0LL;
            fore (k, N) T[i][j] += BB[i][k] * BB[k][j] % M, T[i][j] %= M;
        }
        fore (i, N) fore (j, N) BB[i][j] = T[i][j];
    }
    fore (i, N) {
        fore (j, N) cout << D[i][j] << ' ';
        cout << endl;
    }
}
