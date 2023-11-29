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

int N, K, KK, R, S;
int C[201010];
#include<queue>
queue<int> qu;

main() {
    cin >> N >> K; KK = K << 1;
    if (N > K) goto E;
    if (N == 0) C[0] = 1, qu.push(0);
    else for (int i = N; i <= KK; i <<= 1) C[i] = 1, qu.push(i);
ST:
    S = qu.size();
    do {
        int a = qu.front(); qu.pop();
        if (a == K) {
            cout << R << endl;
            return 0;
        } 
        for (int i = a+1; i <= KK; i <<= 1) if (!C[i]) C[i] = 1, qu.push(i);
        if (a > 1) for (int i = a-1; i <= KK; i <<= 1) if (!C[i]) C[i] = 1, qu.push(i);
        else if (a == 1) if (!C[0]) C[0] = 1, qu.push(0);
    } while (--S);
    ++R;
    goto ST;
E:
    cout << N - K << endl;
}

