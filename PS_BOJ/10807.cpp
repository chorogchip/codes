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

int N, X, D[201];

main() { FAST
     cin >> N;
     fore (i, N) {
        cin >> X;
        ++D[X + 100];
     }
     cin >> X;
     cout << D[X + 100];
}

