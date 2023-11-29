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

int N, M, X, D1[1010], D2[1010], C[1010], A, B, T, MM;
vii G1[1010], G2[1010];
#include<queue>
priority_queue<pair<int,int>> qu;

int main() { FAST
    cin >> N >> M >> X;
    fore (i, M) {
        cin >> A >> B >> T;
        G1[A].push_back(make_pair(B, T));
        G2[B].push_back(make_pair(A, T));
    }
    for1 (i, N) D1[i] = D2[i] = INF;

    D1[X] = 0;
    qu.push(make_pair(0, X));
    while (!qu.empty()) {
        int o = qu.top().second; qu.pop();
        if (C[o]) continue;
        for (auto oo : G1[o])
            if (D1[oo.first] > D1[o] + oo.second) {
                D1[oo.first] = D1[o] + oo.second;
                qu.push(make_pair(-D1[oo.first] , oo.first));
            }
        C[o] = 1;
    } memset(C, 0, sizeof(C));
    D2[X] = 0;
    qu.push(make_pair(0, X));
    while (!qu.empty()) {
        int o = qu.top().second; qu.pop();
        if (C[o]) continue;
        for (auto oo : G2[o])
            if (D2[oo.first] > D2[o] + oo.second) {
                D2[oo.first] = D2[o] + oo.second;
                qu.push(make_pair(-D2[oo.first], oo.first));
            }
        C[o] = 1;
    }
    for1 (i, N)
        MM = max(MM, D1[i] + D2[i]);
    cout << MM;
}
