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
typedef pair<int,ii> iii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

int N, M, U[101010], A, B, W, S;
iii G[1010101];

int find(int x) {
    if (U[x] == x) return x;
    return U[x] = find(U[x]);
}

int main() { FAST
    cin >> N >> M;
    fore (i, M) {
        cin >> A >> B >> W;
        G[i] = {W, {A, B}};
    }
    sort(G, G + M);
    for1 (i, N) U[i] = i;
    int k = 2, a, b;
    fore (i, M) {
        if (k == N) break;
        if ((a = find(G[i].second.first)) != 
            (b = find(G[i].second.second)))
                U[a] = b, ++k, S += G[i].first;
    }
    cout << S;
}
