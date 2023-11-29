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

int V, E, K, X, Y, Z, D[20101], H[20101];
vector<pair<int,int>> G[20101];
#include<queue>
priority_queue<pair<int,int>> heap;

int main() { FAST
    cin >> V >> E >> K;
    fore (i, E) {
        cin >> X >> Y >> Z;
        G[X].push_back(make_pair(-Z, Y));
    }
    for (int i = 1; i <= V; ++i) D[i] = 1010101010;
    heap.push(make_pair(0, K)); D[K] = 0; H[K] = 1;
    while (!heap.empty()) {
        auto o = heap.top(); heap.pop();
        for (auto oo : G[o.second]) if (!H[oo.second] && D[o.second] - oo.first < D[oo.second]) {
            D[oo.second] = D[o.second] - oo.first;
            if (!H[oo.second]) {
                heap.push(make_pair(-D[oo.second], oo.second));
            }
        }
        H[o.second] = 1;
    }
    for (int i = 1; i <= V; ++i)
        if (D[i] == 1010101010) cout << "INF\n";
        else cout << D[i] << endl;
}
