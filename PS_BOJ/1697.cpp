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

int N, K, KK, R, C[201010];
#include<queue>
queue<int> qu;

main() { FAST
    cin >> N >> K;
    KK = K << 1;
    C[N] = 1;
    qu.push(N);
ST:
    int s = qu.size();
    while (s--) {
        int a = qu.front(); qu.pop();
        if (a == K) goto EN;
        if (a < K) {
            if (!C[a+1]) C[a+1] = 1, qu.push(a + 1);
            if (a < K && !C[a<<1]) C[a<<1] = 1, qu.push(a << 1);
        }
        if (a > 0 && !C[a-1]) C[a-1] = 1, qu.push(a - 1);
    }
    ++R;
    goto ST;
EN:
    cout << R;
}

