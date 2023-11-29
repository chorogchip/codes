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

int N, M, C[32010], A, B;
vi G[32010];
#include<queue>
priority_queue<int,vi,greater<int>> heap;


int main() { FAST
    cin >> N >> M;
    fore (i, M) {
        cin >> A >> B;
        G[A].push_back(B);
        ++C[B];
    }
    //for1 (i, N) sort(G[i].begin(), G[i].end());
    for1 (i, N) if (!C[i]) heap.push(i);
    while (!heap.empty()) {
        auto o = heap.top(); heap.pop();
        cout << o << ' ';
        for (auto oo : G[o]) {
            --C[oo];
            if (!C[oo]) heap.push(oo);
        }
    }
}
