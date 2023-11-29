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

typedef unsigned long long ull;
ull A, B;

ull xxoorr(ull N) {
    ull R;
    if ((N & 3ULL) == 1ULL || (N & 3ULL) == 2ULL) R = 1ULL;
    else R = 0ULL;
    if ((N & 1ULL) == 0ULL) for (ull i = 1ULL; i != 63ULL; ++i)
        if ((N & (2ULL<<i)-1ULL) >= 1ULL<<i) R |= 1ULL<<i;
    return R;
}

int main() { FAST
    cin >> A >> B;
    cout << (xxoorr(A-1ULL) ^ xxoorr(B)) << endl;
}
