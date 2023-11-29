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

int N, D[8];

main() { FAST
    cin >> N;
    fore (i, N) D[i] = i+1;
    do fore (i, N) cout << D[i] << " ";
    while (cout << endl, next_permutation(D, D + N));
}

