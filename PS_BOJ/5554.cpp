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

int S, X;

int main() { FAST
    fore (i, 4) {
        cin >> X;
        S += X;
    }
    cout << S/60 << endl << S%60 << endl;
}
