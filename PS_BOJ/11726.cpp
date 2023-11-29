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

int N, D[1010];

main() { FAST
    D[1] = 1;
    D[2] = 2;
    cin >> N;
    for (int i = 3; i <= N; ++i)
        D[i] = (D[i-1] + D[i-2]) % 10007;
    cout << D[N];
}

