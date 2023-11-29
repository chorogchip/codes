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

int T, N, D[2][101010];

int main() { FAST
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> D[0][i];
        for (int i = 1; i <= N; ++i) cin >> D[1][i];
        for (int i = 2; i <= N; ++i) {
            D[0][i] += max(D[1][i-1], D[1][i-2]);
            D[1][i] += max(D[0][i-1], D[0][i-2]);
        }
        cout << max(D[0][N], D[1][N]) << endl;
    }
}
