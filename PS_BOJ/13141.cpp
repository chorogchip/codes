#include<bits/stdc++.h>
using namespace std;

int dist[256][256];
struct {
    int a, b, l;
    int get_time(int st) const {
        int a_time = dist[st][a]*2;
        int b_time = dist[st][b]*2;
        if (a_time > b_time) swap(a_time, b_time);
        int gap = b_time - a_time;
        int new_l = l*2 - gap;
        if (new_l <= 0) return a_time + l*2;
        return b_time + new_l/2;
    }
} e[20101];
const int INF = 401'0101;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        if (i != j) dist[i][j] = INF;
    for(int i = 0; i < m; ++i) {
        int a, b, l; scanf("%d%d%d", &a, &b, &l);
        e[i] = {a, b, l};
        dist[a][b] = min(dist[a][b], l);
        dist[b][a] = min(dist[b][a], l);
    }
    for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int time = INF;
    for (int i = 1; i <= n; ++i) {
        int time_i = 0;
        for (int j = 0; j < m; ++j)
            time_i = max(time_i, e[j].get_time(i));
        time = min(time, time_i);
    }
    printf("%.1f", time / 2.0f);
}