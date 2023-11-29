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

int T, N, K, C[1010], X, Y, W, D[1010];
vi v[1010];

int getT(int x) {
    if (D[x] != -1) return D[x];
    int mx = 0;
    for (auto o : v[x]) mx = max(mx, getT(o));
    return D[x] = mx + C[x];
}

int main() { FAST
    cin >> T;
    do {
        cin >> N >> K;
        for1 (i, N) cin >> C[i], v[i].clear();
        memset(D, -1, sizeof(D));
        for1 (i, K) {
            cin >> X >> Y;
            v[Y].push_back(X);
        } cin >> W;
        cout << getT(W) << endl;
    } while (--T);
}
