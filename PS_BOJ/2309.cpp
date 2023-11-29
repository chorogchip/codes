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

int R[9], S, i, j, k;

main() { FAST
    fore(i, 9) cin >> R[i];
    sort(R, R + 9);
    for (i = 0; i != 8; ++i)
    for (j = i+1; j != 9; ++j) if (i != j) {
        S = 0;
        for (k = 0; k != 9; k++)
            if (k != i && k != j) S += R[k];
        if (S == 100) goto E;
    }
    E:
    for (k = 0; k != 9; ++k)
        if (k != i && k != j)
            cout << R[k] << endl;
}

