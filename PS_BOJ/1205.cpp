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

int N, S, P, D[52];

int main() { FAST
    cin >> N >> S >> P;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    if (N == P && S <= D[0]) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = N-1, k = 1; i >= 0; --i) {
        if (D[i] != D[i+1]) k = N - i;
        if (D[i] <= S) { cout << k << endl; return 0; }
    }
    cout << N+1 << endl;
}
