#include<iostream>
#include<cstdlib>
#include<vector>
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

typedef long long ll;
ll N, K, M, R = 1LL;
unsigned short C[2001][2001];

int main() { FAST
    cin >> N >> K >> M;
    if (K > N >> 1) K = N - K;
    for (int i = 0; i != M; ++i) {
        int cc = i + 2 >> 1;
        C[i][0] = 1;
        for (int j = 1; j != cc; ++j)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
        for (int j = cc; j <= i; ++j) C[i][j] = C[i][i-j];
    }
    while (N) {
        R *= C[N % M][K % M], R %= M;
        N /= M, K /= M;
    }
    cout << R;
}
