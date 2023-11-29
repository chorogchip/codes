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

int N, H, D[501010], T[501010], M = 2110101010, C, X, Y;

int main() { FAST
    cin >> N >> H; N >>= 1;
    for (int i = 1; i <= N; ++i) {
        cin >> X >> Y;
        ++D[X];
        ++T[H - Y + 1];
    }
    for (int i = H; i != 1; --i) D[i-1] += D[i];
    for (int i = 1; i != H; ++i) T[i+1] += T[i];
    for (int i = 1; i <= H; ++i) {
        X = D[i] + T[i];
        if (M == X) ++C;
        else if (M > X) M = X, C = 1; 
    }
    cout << M << ' ' << C;
}
