#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, i, X, S, R = -2101010101;

main() { FAST
    cin >> N;
    while (i++ != N) {
        cin >> X;
        R = max(R, S = max(X, S + X));
    }
    cout << R;
}