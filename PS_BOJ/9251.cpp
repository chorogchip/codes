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

int D[2][1010], i, j;
char A[1010], B[1010];

int main() { FAST
    cin >> A + 1 >> B + 1;
    for (i = 1; A[i]; ++i) for (j = 1; B[j]; ++j) {
        if (A[i] == B[j]) D[i&1][j] = D[i-1&1][j-1] + 1;
        else D[i&1][j] = max(D[i&1][j-1], D[i-1&1][j]);
    }
    cout << D[i-1&1][j-1];
}
