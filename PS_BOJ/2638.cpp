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

int N, M, D[111][111], S, K;
vii v;

void c(int i, int j) {
    if (!i || !j || i > N || j > M) return;
    D[i][j] = 2;
    if (!D[i-1][j]) c(i-1, j);
    if (!D[i+1][j]) c(i+1, j);
    if (!D[i][j-1]) c(i, j-1);
    if (!D[i][j+1]) c(i, j+1);
}

int main() {
    cin >> N >> M;
    for1 (i, N) for1 (j, M) {
        cin >> D[i][j];
        if (D[i][j]) ++S;
    }
    c(1, 1);
    while (S) {
        ++K;
        for1 (i, N) for1 (j, M) if (D[i][j] == 1) {
            int cnt = 0;
            if (D[i-1][j] == 2) ++cnt;
            if (D[i+1][j] == 2) ++cnt;
            if (D[i][j-1] == 2) ++cnt;
            if (D[i][j+1] == 2) ++cnt;
            if (cnt >= 2) v.emplace_back(i, j), --S;
        }
        while (!v.empty()) {
            auto o = v.back(); v.pop_back();
            c(o.first, o.second);
        }
    }
    cout << K;
}
