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

int N, M, V, C, K, D[160101];
vector<pair<int,int>> v;

int main() { FAST
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> V >> C >> K;
        for (int b = 1; K > 0; b<<=1) {
            int bb = min(K, b);
            v.push_back(make_pair(V * bb, C * bb));
            K -= bb;
        }
    } N = v.size();
    for (int i = 0; i != N; ++i)
        for (int j = M; j >= v[i].first; --j)
            D[j] = max(D[j], D[j-v[i].first]+v[i].second);
    cout << D[M] << endl;
}
