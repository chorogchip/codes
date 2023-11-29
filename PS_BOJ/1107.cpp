#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, R, B[10], AB[10], *p = AB;
char CH[10];

void asd(int n, int prev, int a) {
    if (!CH[n]) {
        R = min(R, abs(N - prev) + n);
        return;
    }
    a *= 10;
    a += CH[n] - '0';
    prev *= 10;
    for (int *i = AB; i != p; ++i) if (prev + *i > a) {
        asd(n+1, prev + *i, a);
        if (i != AB) asd(n+1, prev + *(i-1), a);
        return;
    }
    asd(n+1, prev + *(p-1), a);
    if (p-1 != AB) asd(n+1, prev + *(p-2), a);
}

main() { FAST 
    cin >> CH >> N;
    fore (i, N) B[cin >> R, R] = 1;
    fore (i, 10) if (!B[i]) *p++ = i;
    
    if (N < 10) {
        N = atoi(CH);
        R = abs(N - 100);

        asd(0, 0, 0);

        for (int i = 9; i > 0; --i) CH[i] = CH[i-1];
        CH[0] = '0';
        asd(0, 0, 0);

        char c = CH[1];
        for (int i = 0; i < 8; ++i) CH[i] = CH[i+2];
        if (CH[0]) asd(0, 0, c - '0');
    } else {
        N = atoi(CH);
        R = abs(N - 100);
    }
    cout << R;
}

