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

int N, A, B, C, R, D[101010];
vector<pair<int,int>> trees[101010];
pair<int,int> mm[101010];

int asd(int v) {
    int m;
    for (auto o : trees[v]) if (!D[o.second]) {
        D[o.second] = 1;
        m = o.first + asd(o.second);
        if (mm[v].second < m)
            if (mm[v].first < m) mm[v].second = mm[v].first, mm[v].first = m;
            else mm[v].second = m;
    }
    return mm[v].first;
}

int main() { FAST
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A >> B;
        while (B != -1) {
            cin >> C;
            trees[A].push_back(make_pair(C, B));
            cin >> B;
        }
    }
    D[1] = 1;
    asd(1);
    for (int i = 1; i <= N; ++i) R = max(R, mm[i].first + mm[i].second);
    cout << R << endl;
}
