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

#include<queue>
queue<int> qu;
int N, M, FR, TO, CO, C[1010], COST[1010];
vector<pair<int, int>> G[1010];

main() { FAST
    cin >> N >> M;
    fore (i, M) {
        cin >> FR >> TO >> CO;
        G[FR].push_back(make_pair(-CO, TO));
    }
    for (int i = 1; i <= N; ++i) sort(G[i].begin(), G[i].end());
    cin >> FR >> TO;
    for (int i = 1; i <= N; ++i) COST[i] = -2110101010;
    COST[FR] = 0;
    C[FR] = 1;
    qu.push(FR);
    while (!qu.empty()) {
        auto o = qu.front(); qu.pop();
        C[o] = 0;
        for (auto oo : G[o])
            if (COST[o] + oo.first > COST[oo.second]) {
                COST[oo.second] = COST[o] + oo.first;
                if (!C[oo.second]) {
                    C[oo.second] = 1;
                    qu.push(oo.second);
                }
            }
    }
    cout << -COST[TO] << endl;
}
