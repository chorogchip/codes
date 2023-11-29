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

int M, N, I, R[32];

main() { FAST
    cin >> M >> N;
    do R[I++] = M % N;
    while (M /= N);
    while (I--) cout << (char)(R[I] + (R[I] <= 9 ? '0' : 'A' - 10));
}

