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

int N, M, D[10], C[10], CC[10];

void choose(int dpt, int st) {
    if (dpt == M) {
        for (int i = 1; i != dpt; ++i) if (C[i-1] <= C[i]) goto E;
        if (dpt == 1) goto E;
        return;
        E:
        for (int i = 0; i != dpt; ++i) if (CC[i] != C[i]) goto F;
        return;
        F:
        for (int i = 0; i != dpt; ++i) cout << (CC[i] = C[i]) << ' '; cout << endl;
        return;
    }
    for (int i = st; i != N; ++i) {
        C[dpt] = D[i];
        choose(dpt + 1, i);
    }
}

int main() { FAST
    cin >> N >> M;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    CC[0] = D[0] - 1;
    choose(0, 0);
}
