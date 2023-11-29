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

int N, K, S[10101], R;

main() { FAST
    cin >> N >> K;
    fore (i, N) cin >> S[i];
    if (K >= N) {
        cout << 0;
        return 0;
    }
    sort(S, S + N);
    R = S[N-1] - S[0];
    for (int i = N-1; i; --i)
        S[i] -= S[i-1];
    sort(S + 1, S + N);
    --K;
    for (int i = 0, j = N; i != K; ++i)
        R -= S[--j];
    cout << R;
}

