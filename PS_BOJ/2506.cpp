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

int N, S, R, X;

int main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> X;
        if (X == 0) R = 0;
        else S += ++R;
    }
    cout << S;
}
