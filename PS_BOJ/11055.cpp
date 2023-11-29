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

int N, D[1010], S[1010], M;

int main() { FAST
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> D[i];
        for (int j = 1; j != i; ++j) if (D[i] > D[j])
            S[i] = max(S[i], S[j]);
        M = max(M, S[i] += D[i]);
    }
    cout << M << endl;
}
