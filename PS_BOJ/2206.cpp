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

int N, M, A[1010][1010], DS[1010][1010], DF[1010][1010], R;
#include<queue>
queue<pair<int,int>> qu;

int main() {
    scanf("%d%d", &N, &M); getchar();
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j)
            A[i][j] = getchar() - '0';
        getchar();
    }
    int K = 1;
    qu.push(make_pair(1, 1)); DS[1][1] = 1;
    while (!qu.empty()) {
        int s = qu.size(); ++K;
        while (s--) {
            auto o = qu.front(); qu.pop();
            if (o.first-1>0&&!A[o.first-1][o.second]&&!DS[o.first-1][o.second])
                DS[o.first-1][o.second] = K, qu.push(make_pair(o.first-1,o.second));
            if (o.first+1<=N&&!A[o.first+1][o.second]&&!DS[o.first+1][o.second])
                DS[o.first+1][o.second] = K, qu.push(make_pair(o.first+1,o.second));
            if (o.second-1>0&&!A[o.first][o.second-1]&&!DS[o.first][o.second-1])
                DS[o.first][o.second-1] = K, qu.push(make_pair(o.first,o.second-1));
            if (o.second+1<=M&&!A[o.first][o.second+1]&&!DS[o.first][o.second+1])
                DS[o.first][o.second+1] = K, qu.push(make_pair(o.first,o.second+1));
        }
    }
    K = 1;
    qu.push(make_pair(N, M)); DF[N][M] = 1;
    while (!qu.empty()) {
        int s = qu.size(); ++K;
        while (s--) {
            auto o = qu.front(); qu.pop();
            if (o.first-1>0&&!A[o.first-1][o.second]&&!DF[o.first-1][o.second])
                DF[o.first-1][o.second] = K, qu.push(make_pair(o.first-1,o.second));
            if (o.first+1<=N&&!A[o.first+1][o.second]&&!DF[o.first+1][o.second])
                DF[o.first+1][o.second] = K, qu.push(make_pair(o.first+1,o.second));
            if (o.second-1>0&&!A[o.first][o.second-1]&&!DF[o.first][o.second-1])
                DF[o.first][o.second-1] = K, qu.push(make_pair(o.first,o.second-1));
            if (o.second+1<=M&&!A[o.first][o.second+1]&&!DF[o.first][o.second+1])
                DF[o.first][o.second+1] = K, qu.push(make_pair(o.first,o.second+1));
        }
    }
    R = DS[N][M];
    if (!R) R = 2110101010;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) if (A[i][j]) {
        if (DS[i-1][j] && DF[i+1][j]) R = min(R, DS[i-1][j] + DF[i+1][j] + 1);
        if (DS[i-1][j] && DF[i][j-1]) R = min(R, DS[i-1][j] + DF[i][j-1] + 1);
        if (DS[i-1][j] && DF[i][j+1]) R = min(R, DS[i-1][j] + DF[i][j+1] + 1);
        if (DS[i+1][j] && DF[i-1][j]) R = min(R, DS[i+1][j] + DF[i-1][j] + 1);
        if (DS[i+1][j] && DF[i][j-1]) R = min(R, DS[i+1][j] + DF[i][j-1] + 1);
        if (DS[i+1][j] && DF[i][j+1]) R = min(R, DS[i+1][j] + DF[i][j+1] + 1);
        if (DS[i][j-1] && DF[i-1][j]) R = min(R, DS[i][j-1] + DF[i-1][j] + 1);
        if (DS[i][j-1] && DF[i+1][j]) R = min(R, DS[i][j-1] + DF[i+1][j] + 1);
        if (DS[i][j-1] && DF[i][j+1]) R = min(R, DS[i][j-1] + DF[i][j+1] + 1);
        if (DS[i][j+1] && DF[i-1][j]) R = min(R, DS[i][j+1] + DF[i-1][j] + 1);
        if (DS[i][j+1] && DF[i+1][j]) R = min(R, DS[i][j+1] + DF[i+1][j] + 1);
        if (DS[i][j+1] && DF[i][j-1]) R = min(R, DS[i][j+1] + DF[i][j-1] + 1);
    }
    if (R != 2110101010 || (N == 1 && M == 1)) printf("%d\n", R);
    else printf("-1\n");
}
