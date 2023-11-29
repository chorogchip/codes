#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int T, K, M, N;
char D[51][51];
pair<short,short> V[2601];
#include<queue>
queue<pair<short,short>> qu;

void BFS() {
    while (!qu.empty()) {
        auto o = qu.front(); qu.pop();
        if (o.second > 0 && D[o.second-1][o.first]) D[o.second-1][o.first] = 0, qu.push(make_pair(o.first,o.second-1));
        if (o.second < N-1 && D[o.second+1][o.first]) D[o.second+1][o.first] = 0, qu.push(make_pair(o.first,o.second+1));
        if (o.first > 0 && D[o.second][o.first-1]) D[o.second][o.first-1] = 0, qu.push(make_pair(o.first-1,o.second));
        if (o.first < M-1 && D[o.second][o.first+1]) D[o.second][o.first+1] = 0, qu.push(make_pair(o.first+1,o.second));
    }
}

main() { FAST 
    cin >> T;
    fore (tt, T) {
        int R = 0;
        cin >> M >> N >> K;
        for (int i = 0; i != K; ++i) {
            cin >> V[i].first >> V[i].second;
            D[V[i].second][V[i].first] = 1;
        }
        for (int i = 0; i != K; ++i)
            if (D[V[i].second][V[i].first]) {
                D[V[i].second][V[i].first] = 0;
                qu.push(make_pair(V[i].first, V[i].second));
                BFS();
                ++R;
            }
        cout << R << endl;
    }
}