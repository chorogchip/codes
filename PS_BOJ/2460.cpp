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

int R, A, B, S;

int main() { FAST
    fore(i, 10) {
        cin >> A >> B;
        S += B - A;
        R = max(S, R);
    }
    cout << R;
}
