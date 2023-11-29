#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int X, N, D[1010101];

int main() { FAST
    while (cin >> X, !cin.eof()) {
        X *= 10000000;
        cin >> N;
        fore (i, N) cin >> D[i];
        sort(D, D + N);
        for (int i = 0; i < N - 1; ++i) {
            int* b = lower_bound(D + i + 1, D + N, X - D[i]);
            if (b != D + N && X - D[i] == *b) {
                cout << "yes " << D[i] << ' ' << *b << endl;
                goto P;
            }
        }
        cout << "danger\n";
        P:;
    }
}
