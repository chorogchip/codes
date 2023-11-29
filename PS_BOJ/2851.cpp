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

int R, X;
int main() { FAST
    fore (i, 10) {
        cin >> X;
        if (R + X <= 100) R += X;
        else if (R < 100 && 100 - R >= R + X - 100) R += X;
        else break;
    }
    cout << R;
}
