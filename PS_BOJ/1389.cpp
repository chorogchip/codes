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

int N, M, X, Y, R = 90909090, RP;
char C[101];
vector<int> G[101];
#include<queue>
queue<int> qu;

main() { FAST 
    cin >> N >> M;
    fore (i, M) {
        cin >> X >> Y;
        G[X].push_back(Y);
        G[Y].push_back(X);
    }
    for (int i = 1; i <= N; ++i) {
        memset(C, 0, sizeof(C));
        int sum = 0;
        int count = 1;
        qu.push(i);
        while (!qu.empty()) {
            int ss = qu.size();
            for (int j = 0; j != ss; ++j) {
                int p = qu.front(); qu.pop();
                for (auto k : G[p])
                    if (!C[k]) sum += count, qu.push(k), C[k] = 1;
            }
            ++count;
        }
        if (R > sum) {
            R = sum;
            RP = i;
        }
    }
    cout << RP;
}

