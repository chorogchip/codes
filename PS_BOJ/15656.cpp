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
        return;
    }
    for (int i = 0; i != N; ++i) {
        P[depth] = i;
        pick(depth+1);
    }
}

main() { FAST
    cin >> N >> M;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    pick(0);
}

