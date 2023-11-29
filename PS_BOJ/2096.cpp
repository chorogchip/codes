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

int N, A, B, C, D[2][6];

int main() { FAST
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A >> B >> C;
        D[i&1][0] = A + max(D[i-1&1][0], D[i-1&1][1]);
        D[i&1][1] = B + max(D[i-1&1][0], max(D[i-1&1][1], D[i-1&1][2]));
        D[i&1][2] = C + max(D[i-1&1][1], D[i-1&1][2]);
        D[i&1][3] = A + min(D[i-1&1][3], D[i-1&1][4]);
        D[i&1][4] = B + min(D[i-1&1][3], min(D[i-1&1][4], D[i-1&1][5]));
        D[i&1][5] = C + min(D[i-1&1][4], D[i-1&1][5]);
    }
    cout << max(D[N&1][0], max(D[N&1][1], D[N&1][2])) << ' ' << 
            min(D[N&1][3], min(D[N&1][4], D[N&1][5])) << endl;
}
