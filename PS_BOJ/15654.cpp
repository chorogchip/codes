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

int N, M, D[8], I, P[8];

void pick(int depth) {
    if (depth == M) {
        for (int i = 0; i != M; ++i)
            cout << D[P[i]] << " ";
        cout << endl;
    }
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != depth; ++j)
            if (P[j] == i) goto E;
        P[depth] = i;
        pick(depth+1);
        E:;
    }
}

main() { FAST
    cin >> N >> M;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    pick(0);
}

