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
constexpr int INF = 1000*1000*1000*2;

int N, M, C[1010], D[1010], DD[1010], A, B, W;
vii G[1010];
#include<queue>
priority_queue<ii> qu;

int main() { FAST
    cin >> N >> M;
    fore (i, M) {
        cin >> A >> B >> W;
        G[A].emplace_back(B, W);
    }
    cin >> A >> B;
    for1 (i, N) D[i] = INF;
    D[A] = 0;
    qu.push({0, A});
    while (!qu.empty()) {
        auto o = qu.top(); qu.pop();
        if (C[o.second]) continue;
        for (auto oo : G[o.second])
            if (!C[oo.first] && D[oo.first] > D[o.second] + oo.second)
                D[oo.first] = D[o.second] + oo.second,
                DD[oo.first] = o.second,
                qu.push({-D[oo.first], oo.first});
        C[o.second] = 1;
    }
    cout << D[B] << endl;
    vi v; int i = B;
    do v.push_back(i); while (i = DD[i]);
    cout << v.size() << endl;
    for (int i = v.size() - 1; i >= 0; --i)
        cout << v[i] << ' ';
}
