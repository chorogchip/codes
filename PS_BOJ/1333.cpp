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

int L, N, D, R;

main() { FAST
    cin >> N >> L >> D;
    int C = L;
    int PH = 0;
    N *= L + 5;
    N -= 5;
    while (PH < N || C < N) {
        if (C == PH) {
            cout << C << endl;
            return 0;
        }
        else if (C > PH) PH += D;
        else if (C + 5 > PH) {
            cout << PH << endl;
            return 0;
        } else C += L + 5;
    } 
    cout << PH << endl;
}

