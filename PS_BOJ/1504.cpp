#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

int N, E, C[801], D[801], A, B, W;
vii G[801];
#include<queue>
priority_queue<ii> heap;

ll asd(int st, int to) {
    for1 (i, N) D[i] = INF;
    memset(C, 0, sizeof(C));
    D[st] = 0;
    heap.push({0, st});
    while (!heap.empty()) {
        auto o = heap.top(); heap.pop();
        for (auto oo : G[o.second])
            if (!C[o.second] && D[oo.first] > D[o.second] + oo.second) {
            D[oo.first] = D[o.second] + oo.second;
            heap.push({-D[oo.first], oo.first});
        }
        C[o.second] = 1;
    }
    return D[to];
}

int main() { FAST
    cin >> N >> E;
    fore (i, E) {
        cin >> A >> B >> W;
        G[A].emplace_back(B, W);
        G[B].emplace_back(A, W);
    }
    cin >> A >> B;
    ll ww = asd(A, B);
    if (ww == INF) {
        cout << -1;
        return 0;
    }
    ll R = min(asd(1, A) + asd(B, N),
               asd(1, B) + asd(A, N));
    if (R >= INF) {
        cout << -1;
        return 0;
    }
    cout << R + ww;
}
