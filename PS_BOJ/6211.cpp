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

int C, B, D[22], M;


int main() { FAST
    cin >> C >> B;
    fore (i, B) cin >> D[i];
    int S = 1 << B;
    for (int i = 0; i != S; ++i) {
        int aa = 0;
        for (int j = 1, c = 0; j != S; j <<= 1, ++c)
            if (i & j) aa += D[c];
        if (aa <= C) M = max(M, aa);
    }
    cout << M;

}
