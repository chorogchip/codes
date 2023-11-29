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

int X, S, R, lo, hi;
char isNP[2010101];
vector<int> primes;

main() { FAST
    primes.push_back(2);
    for (int i = 3; i <= 4000000; i += 2) if (!isNP[i>>1]) {
        primes.push_back(i);
        for (int k = i << 1, j = i + k; j <= 4000000; j += k)
            isNP[j>>1] = 1;
    }
    cin >> X;
    S = 2;
    int ss = primes.size();
    while (hi != ss && primes[lo] <= X) {
        if (S == X) {
            ++R;
            S -= primes[lo++];
            S += primes[++hi];
        } else if (S < X) {
            S += primes[++hi];
        } else {
            S -= primes[lo++];
        }
    }
    cout << R;
}

