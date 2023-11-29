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

int V, E, U[10101], A, B, W, S;
pair<int,ii> G[101010];

int find(int x) {
    if (U[x] == x) return x;
    return U[x] = find(U[x]);
}

int main() { FAST
    cin >> V >> E;
    fore (i, E) {
        cin >> A >> B >> W;
        G[i] = {W, {A, B}};
    }
    for1 (i, V) U[i] = i;
    sort(G, G + E);
    int k = 1, a, b;
    fore (i, E) {
        if ((a = find(G[i].second.first)) !=
            (b = find(G[i].second.second)))
            U[a] = b, ++k, S += G[i].first;
        if (k == V) break;
    }
    cout << S;
}
