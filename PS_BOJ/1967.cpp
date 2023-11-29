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

int N, A, B, C, R; pair<int,int> D[10101];
vector<pair<int,int>> trees[10101];
int asd(int v) {
    if (!D[v].first) {
        int m;
        for (auto o : trees[v]) {
            m = o.second + asd(o.first);
            if (m > D[v].second)
                if (m > D[v].first) D[v].second = D[v].first, D[v].first = m;
                else D[v].second = m;
        }
    }
    return D[v].first;
}
int main() { FAST
    cin >> N;
    for (int i = 1; i != N; ++i) {
        cin >> A >> B >> C;
        trees[A].push_back(make_pair(B, C));
    }
    asd(1);
    for (int i = 1; D[i].first; ++i) R = max(R, D[i].first + D[i].second);
    cout << R << endl;
}
