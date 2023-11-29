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

int T, N, M, W, D[501], j;
constexpr int INF = 1<<28;
pair<pair<int,int>,int> G[10101];

int main() { FAST
    cin >> T;
    do {
        cin >> N >> M >> W; M <<= 1;
        for (j = 0; j != M; j += 2) {
            cin >> G[j].first.first >> G[j].first.second >> G[j].second;
            G[j+1].first.first = G[j].first.second;
            G[j+1].first.second = G[j].first.first;
            G[j+1].second = G[j].second;
        } M += W;
        for (; j != M; ++j) {
            cin >> G[j].first.first >> G[j].first.second >> G[j].second;
            G[j].second = -G[j].second;
        }
        for (int i = 2; i <= N; ++i) D[i] = INF; D[1] = 0;
        for (int i = 1; i != N; ++i)
        for (j = 0; j != M; ++j)
            if (D[G[j].first.second] > D[G[j].first.first] + G[j].second)
                D[G[j].first.second] = D[G[j].first.first] + G[j].second;
        for (j = 0; j != M; ++j)
            if (D[G[j].first.second] > D[G[j].first.first] + G[j].second)
                goto YES;
        cout << "NO\n"; continue;
        YES: cout << "YES\n"; continue;
    } while (--T);
}
