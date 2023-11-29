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

int N, arr, X;
string S;

main() { FAST 
    cin >> N;
    while (N--) {
        cin >> S;
        if (S[0] == 'c') cin >> X, cout << (bool)(arr & 1 << X) << endl;
        else if (S[0] == 'a' && S[1] == 'd') cin >> X, arr |= 1 << X;
        else if (S[0] == 'r') cin >> X, arr &= ~(1 << X);
        else if (S[0] == 't') cin >> X, arr = arr ^ 1 << X;
        else if (S[0] == 'e') arr = 0;
        else arr = -1;
    }
}

