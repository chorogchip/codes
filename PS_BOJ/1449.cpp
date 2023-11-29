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

int N, L, D[1010], R;

main() { FAST
    cin >> N >> L;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    --L;
    R = 1;
    int PP = D[0];
    for (int i = 0; i != N; ++i)
        if (D[i] - PP > L) PP = D[i], ++R;
    cout << R;
}

