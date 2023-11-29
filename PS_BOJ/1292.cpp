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

int A, B, D[1001], S;

main() { FAST
    int i = 1, c = 0;
    while (++c, i <= 1000)
        for (int k = 0; k != c && i <= 1000; ++k)
            D[i++] = c;
    cin >> A >> B;
    for (int i = A; i <= B; ++i)
        S += D[i];
    cout << S;
    
}

