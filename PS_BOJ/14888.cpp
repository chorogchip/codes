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

int N, D[12], OP[4], M = -2101010101, m = 2101010101;

void asd(int val, int dep) {
    if (dep == N) {
        M = max(M, val);
        m = min(m, val);
        return;
    }
    if (OP[0]) --OP[0], asd(val + D[dep], dep + 1), ++OP[0];
    if (OP[1]) --OP[1], asd(val - D[dep], dep + 1), ++OP[1];
    if (OP[2]) --OP[2], asd(val * D[dep], dep + 1), ++OP[2];
    if (OP[3]) --OP[3], asd(val / D[dep], dep + 1), ++OP[3];
}

int main() { FAST
    cin >> N;
    fore (i, N) cin >> D[i];
    cin >> OP[0] >> OP[1] >> OP[2] >> OP[3];
    asd(D[0], 1);
    cout << M << endl << m << endl;
}
