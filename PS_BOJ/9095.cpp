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

int T, X, D[12];

main() { FAST
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    for (int i = 4; i <= 11; ++i)
        D[i] = D[i-1] + D[i-2] + D[i-3];
    cin >> T;
    while (T--) cin >> X, cout << D[X] << endl;
}

