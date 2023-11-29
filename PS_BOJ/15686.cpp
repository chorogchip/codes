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

int N, M, X, R = 101010101, S[14];
vector<pair<int,int>> houses, chickens;

void asd(int depth, int sel) {
    if (depth != M) {
        for (int i = sel + 1; i < X; ++i) {
            S[depth] = i;
            asd(depth+1, i);
        }
    } else {
        int RR = 0;
        for (int i = 0; i != N; ++i) {
            int RRR = 101010101;
            for (int j = 0; j != M; ++j)
                RRR = min(RRR, abs(houses[i].first  - chickens[S[j]].first) +
                               abs(houses[i].second - chickens[S[j]].second));
            RR += RRR;
        }
        R = min(R, RR);
    }
}

int main() { FAST
    cin >> N >> M;
    fore (i, N) fore (j, N) {
        cin >> X;
        if (X == 1) houses.push_back(make_pair(i, j));
        else if (X == 2) chickens.push_back(make_pair(i, j));
    } X = chickens.size(); N = houses.size();
    asd(0, -1);
    cout << R << endl;
}
