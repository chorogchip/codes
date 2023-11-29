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

int A, B, k;

int main() { FAST
    cin >> A >> B;
    while (A < B) {
        if (B & 1)
            if (B % 10 != 1) { cout << -1 << endl; return 0; }
            else B /= 10;
        else B >>= 1;
        ++k;
    }
    cout << (A == B ? k + 1 : -1) << endl;
}
