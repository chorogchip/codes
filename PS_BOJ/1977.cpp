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

int A, B, S, R, RR, I;

main() { FAST
    cin >> A >> B;
    while ((RR = ++I * I) < A); --I;
    while((R = ++I * I) <= B)
        S += R;
    if (S) cout << S << endl << RR << endl;
    else cout << -1 << endl;
}
