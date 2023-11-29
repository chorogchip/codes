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

int N, M, X, XX;
long long R, F[41];
long long getF(int n) {
    if (F[n]) return F[n];
    if (n <= 1) return F[n] = 1;
    return F[n] = getF(n-2) + getF(n-1);
}

int main() { FAST
    cin >> N >> M;
    R = 1;
    fore (i, M) {
        cin >> X;
        R *= getF(X - XX - 1);
        XX = X;
    }
    R *= getF(N - XX);
    cout << R << endl;
}
