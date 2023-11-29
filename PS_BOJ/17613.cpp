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

int T, X, Y, A[32], R;

main() { FAST
    for (int i = 1; i != 32; ++i) A[i] = (1<<i) - 1;
    cin >> T;
    while (T--) {
        cin >> X >> Y;
        
        cout << R;
    }
}

