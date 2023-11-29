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

int AN, AM, BN, BM, A[101][101], B[101][101], C[101][101];

int main() { FAST
    cin >> AN >> AM;
    fore (i, AN) fore (j, AM) cin >> A[i][j];
    cin >> BN >> BM;
    fore (i, BN) fore (j, BM) cin >> B[i][j];
    fore (i, AN) fore (j, BM) fore (k, AM) C[i][j] += A[i][k] * B[k][j];
    fore (i, AN) {
        fore (j, BM) cout << C[i][j] << " ";
        cout << endl;
    }
}
