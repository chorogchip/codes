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

int N, S;
char C[201010];

int main() { FAST
    cin >> N >> C + 1;
    for (int i = N; i; i -= 2)
        if (S & 1) {
            if (C[i] < C[i-1]) ++S;
        } else {
            if (C[i] > C[i-1]) ++S;
        }
    cout << S << endl;
}
