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

int L, P, V, R, I;

main() { FAST
    while (true) {
        ++I;
        cin >> L >> P >> V;
        if (L == 0) return 0;
        cout << "Case " << I << ": "
        << ((V / P) * L + min(V % P, L)) << endl;
    }
}

