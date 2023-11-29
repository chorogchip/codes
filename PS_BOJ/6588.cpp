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

int X;
char isNP[510101];

main() { FAST
    for (int i = 3; i <= 1000000; i += 2) if (!isNP[i>>1])
        for (int k = i << 1, j = i + k; j <= 1000000; j += k)
            isNP[j>>1] = 1;
    while (true) {
        cin >> X;
        if (X == 0) return 0;
        for (int i = 3;; i += 2)
            if (!isNP[i>>1] && !isNP[X-i>>1]) {
                cout << X << " = " << i << " + " << X-i << endl;
                break;
            }
    }
}

